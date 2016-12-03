#include <iostream>
#include <string> 
#include <cstring> 

#define MAX 2 
#define ROW 5 
#define COL 3 

using namespace std; 

void movieInput(); 
int selectMenu(); 
void moviePrint(); 

class seatInformation { //좌석 정보 
	int movieSeat[ROW][COL]; 

public :
	seatInformation()
	{ 
		for(int i = 0; i < ROW; i++) 
			for(int j = 0; j< COL; j++) 
				movieSeat[i][j] = 0; 
	}
	~seatInformation() 
	{ 
		//system("clear"); 
		cout << "이용해 주셔서 감사합니다." << endl; 
	} 
}; 

class movieInformation { //영화 정보 
	string movieTitle; 
	string movieRelease; 
	int moviePrice;

public : 
	void setMovieTitle(string movieTitle, string movieRelease, int moviePrice)
	{
		this -> movieTitle = movieTitle; 
		this -> movieRelease = movieRelease; 
		this -> moviePrice = moviePrice; 
	}
	void getMovieInformation()
	{
		 cout <<  movieTitle << ", " <<  movieRelease << ", " <<  moviePrice << endl; 
	}
	~movieInformation(){
	}
};

movieInformation addMovie[MAX]; 

int main()
{ 
	cout << "\t*********************************************************" << endl;
	cout << "\t*                                                       *" << endl;
	cout << "\t*             Welcome to our Theater!! V.1.0            *" << endl;
	cout << "\t*                                                       *" << endl;
	cout << "\t*                                                       *" << endl;
	cout << "\t*                        Project By SeongWon, Min Young *" << endl;
	cout << "\t*********************************************************" << endl;
	cout << endl << endl;
		
	movieInput(); 
	int select = selectMenu(); // 기능 선택함수 

	while(true) 
	{ 
		switch(select) 
		{	 
			case 1 : // 상영중인 영화 
				moviePrint(); 
				break;

			case 2: // 영화 예매 
				break;

			case 3: // 좌석 출력 
				break;

			case 4: // 나가기
				//system("clear"); 
				//sleep(1000);  
				cout << "이용해 주셔서 감사합니다" << endl; 
				return 0;

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
}

int selectMenu()
{
	int select; 
	cout << "Object C++ Movie Ticketing System" << endl << endl; 
	cout << "1번 상영중인 영화 출력 " << endl; 
	cout << "2번 영화예매 " << endl; 
	cout << "3번 좌석 출력" << endl; 
	cout << "4번 나가기" << endl; 

	while(true) 
	{
		cin >> select;
		if(select < 4)
			break; 
	}
	return select; 
}

void moviePrint()
{
	addMovie[0].getMovieInformation();
	addMovie[1].getMovieInformation();
}

