#include <iostream>
#include <string> 
#include <cstring> 
#include <cstdlib>
#include <unistd.h>

#define MAX 2 
#define ROW 5 
#define COL 5 

using namespace std; 

void movieInput(); 
int selectMenu(); 
void moviePrint();
void seatPrint(int i);
void seatInput(int i, int j);
void movieReservation();
int seatReservation(int num, int *seatNumber, int person);

class seatInformation { //좌석 정보 
	int movieSeat[ROW][COL]; 

public :
	friend int seatReservation(int num, int *seatNumber, int person);
	seatInformation()
	{
		int seatNumber = 1; 
		for(int i = 0; i < ROW; i++) 
			for(int j = 0; j< COL; j++) 
			{
				movieSeat[i][j] = seatNumber;
				seatNumber++;
			}
	}

	void getSeatInformation()
	{
		for(int i = 0; i< ROW; i++)
		{
			cout << "\t\t"; 
			for(int j = 0; j< COL; j++)
				cout << "\t"<<  movieSeat[i][j];
			cout << endl; 
		}
	}

	void setSeatinformation(int i, int j)
	{
		movieSeat[i][j] = 0; 
	}
	~seatInformation() {  
	} 
}; 

class movieInformation { //영화 정보 
	string movieTitle; 
	string movieRelease; 
	int moviePrice;

public : 
	friend void movieReservation();
	void setMovieTitle(string movieTitle, string movieRelease, int moviePrice)
	{
		this -> movieTitle = movieTitle; 
		this -> movieRelease = movieRelease; 
		this -> moviePrice = moviePrice; 
	}
	
	void getMovieInformation(int i)
	{
		 cout <<  "\t\t" << i+1 << "번 영화제목 : " <<  movieTitle;
		 cout << ", 개봉일 : " <<  movieRelease; 
		 cout << ", 영화 가격 : " <<  moviePrice << endl; 
	}
	~movieInformation(){
	}
};

movieInformation addMovie[MAX]; // 영화 정보 class 배열 전역선언 
seatInformation addSeat[MAX]; // 좌석 정보 class 배열 전역선언 

int main()
{ 
	movieInput(); 
	int i;

	while(true) 
	{ 
		int select = selectMenu(); // 기능 선택함수 
		switch(select) 
		{	 
			case 1 : // 상영중인 영화 
				moviePrint(); 
				break;

			case 2: // 영화 예매 
				movieReservation(); 
				break;

			case 3: // 좌석 출력 
				moviePrint();
				cout << "몇번 영화를 예약 하셨나요? " << endl <<  "->";
				cin >> i;

				seatPrint(i);
				break;

			case 4: // 나가기
				system("clear"); 
				cout << "이용해 주셔서 감사합니다" << endl; 
				sleep(1);  
				exit(1);

			default : 
				cout << "다시 입력하세요" << endl ; 
		} 
	} 	
	return 0; 
}
		
void movieInput()
{	
	string tmpTitle, tmpRelease;
	int tmpPrice; 

	for(int i = 0; i < MAX; i++) 
	{
		cout << "영화 제목 : ";
		cin >> tmpTitle; 

		cout << "개봉일  : ";
		cin >> tmpRelease;
		 
		cout << "가격  : ";
		cin >> tmpPrice;
		addMovie[i].setMovieTitle(tmpTitle, tmpRelease, tmpPrice); 
	}
	system("clear"); 
}

int selectMenu()
{
	cout << "\t*********************************************************" << endl;
	cout << "\t*                                                       *" << endl;
	cout << "\t*             Welcome to our Theater!! V.2.2            *" << endl;
	cout << "\t*             Object C++ Movie Ticketing System         *" << endl;
	cout << "\t*                                                       *" << endl;
	cout << "\t*                       Project By Seong Won, Min Young *" << endl;
	cout << "\t*********************************************************" << endl;
	cout << endl << endl;

	int select; 
	cout << "1번 상영중인 영화 출력 " << endl; 
	cout << "2번 영화예매 " << endl; 
	cout << "3번 좌석 출력" << endl; 
	cout << "4번 나가기" << endl; 

	cin >> select; 
	return select; 
}

void moviePrint()
{
	system("clear"); 

	cout << endl << endl << "\t\t-------------------- 상영중인 영화 정보 -------------------- " << endl << endl;
	for(int i = 0; i < MAX; i++)
	{
		addMovie[i].getMovieInformation(i);
	}
	cout << endl << endl << "\t\t------------------------------------------------------------ " << endl << endl;
	cout << endl << endl;
}

void seatPrint(int i)
{
	cout << endl << endl << "\t\t-------------------- S  C  R  E  E  N -------------------- " << endl << endl;
	addSeat[i-1].getSeatInformation(); 
	cout << endl << endl << "\t\t---------------------------------------------------------- " << endl << endl;
	cout << endl << endl; 
}

void movieReservation()
{
	int i;
	int person;  

	moviePrint(); 
	cout << " 몇 번 영화를 예약하실 건가요? " << endl << "->"; 
	cin >> i; 

	cout << "몇 명이신가요? " << endl << "->"; 
	cin >> person; 
	
	seatPrint(i); 
	int *seatNumber = new int [person];
	cout << "좌석 번호 입력 " << endl << "->"; 
	for( int j = 0; j < person; j++)
		cin >> seatNumber[j]; 
	
	int check = seatReservation(i, seatNumber, person);
	system("clear");	
	seatPrint(i);
	
	if(check == 1)
	{
		cout << "예약한 좌석이 있습니다. " << endl << "다시한번 확인해 주세요!! "<< endl; 
		return;
	}
	cout << "제목 : " << addMovie[i-1].movieTitle << ", "; 
	cout << "개봉일 :" << addMovie[i-1].movieRelease << ", ";
	cout << "총 가격 : " << addMovie[i-1].moviePrice * person << endl << endl;  
 
	cout << "예약이 완료되었습니다. " << endl;
}

int seatReservation(int num, int *seatNumber, int person)
{
	int tmp = 0; // person
	int i,j;
	int reservation[MAX] = {0}; 
	int tmpPerson[MAX] = {0}; 

	tmpPerson[num-1] += person; 
	while( tmp != person)
	{ 
		for(i = 0; i < ROW; i++)
			for(j = 0; j < COL; j++)
				if(addSeat[num-1].movieSeat[i][j] == seatNumber[tmp])
				{
					reservation[num-1]++;	
					addSeat[num-1].setSeatinformation(i, j);  
				}
		tmp++; 
	}
	
	if(reservation[num-1] == tmpPerson[num-1])
		return 0;
	else 
		return 1;
}
