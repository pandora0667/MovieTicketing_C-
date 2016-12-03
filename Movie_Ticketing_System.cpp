#include <iostream>
#include <string> 
#include <cstring> 

#define MAX 2 
#define ROW 5 
#define COL 3 

using namespace std; 

void movieInput(); 
int selectMenu(); 

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
	void setMovieTitle(string movieTitle)
	{
		this -> movieTitle = movieTitle; 
	}
	~movieInformation(){
	}
};

int main()
{ 
	    cout << "\t*********************************************************" << endl;
		cout << "\t*                                                       *" << endl;
		cout << "\t*             Welcome to our Theater!! V.1.0		       *" << endl;
		cout << "\t*                                                       *" << endl;
		cout << "\t*                                                       *" << endl;
		cout << "\t*                        Project By SeongWon, Min Young *" << endl;
		cout << "\t*********************************************************" << endl;
		cout << endl << endl;
		
		
		movieInput(); 
	/*	int select = selectMenu(); // 기능 선택함수 

		while(true) 
		{ 
			switch(select) 
			{	 
				case 1 : // 상영중인 영화 
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
		} */
		
		return 0; 
}
		
void movieInput()
{	
	movieInformation addMovie[MAX]; 
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
		
		addMovie[i].setMovieTitle(tmpTitle); 
	}  

}












