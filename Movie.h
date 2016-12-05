#include <iostream>
#include <string> 
#include <cstring> 
#include <cstdlib>
#include <unistd.h>

#define MAX 2 
#define ROW 5 
#define COL 5 

using namespace std; 

void movieInput(class movieInformation *addMovie); 
int selectMenu(); 
void moviePrint(class movieInformation *addMovie);
void seatPrint(int i, class seatInformation *addSeat);
void movieReservation(class movieInformation *addMovie, class seatInformation *addSeat);
int seatReservation(int num, int *seatNumber, int person, class seatInformation *addSeat);

class seatInformation { //좌석 정보 
	int movieSeat[ROW][COL]; 

public :
	friend int seatReservation(int num, int *seatNumber, int person, class seatInformation *addSeat);
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
	friend void movieReservation(class movieInformation *addMovie, class seatInformation *addSeat);
	
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

