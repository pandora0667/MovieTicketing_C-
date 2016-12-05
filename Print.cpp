#include "Movie.h"

void movieInput(class movieInformation *addMovie)
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
	cout << "\t*             Welcome to our Theater!! V.2.5            *" << endl;
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

void moviePrint(class movieInformation *addMovie)
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

void seatPrint(int i, class seatInformation *addSeat)
{
	cout << endl << endl << "\t\t-------------------- S  C  R  E  E  N -------------------- " << endl << endl;
	addSeat[i-1].getSeatInformation(); 
	cout << endl << endl << "\t\t---------------------------------------------------------- " << endl << endl;
	cout << endl << endl; 
}
