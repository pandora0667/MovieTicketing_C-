#include "Movie.h"

void movieReservation(class movieInformation *addMovie, class seatInformation *addSeat)
{
	int i;
	int person;  

	moviePrint(addMovie); 
	cout << " 몇 번 영화를 예약하실 건가요? " << endl << "->"; 
	cin >> i; 

	cout << "몇 명이신가요? " << endl << "->"; 
	cin >> person; 
	
	seatPrint(i, addSeat); 
	int *seatNumber = new int [person];
	cout << "좌석 번호 입력 " << endl << "->"; 
	for( int j = 0; j < person; j++)
		cin >> seatNumber[j]; 
	
	int check = seatReservation(i, seatNumber, person, addSeat);
	system("clear");	
	seatPrint(i, addSeat);
	
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

int seatReservation(int num, int *seatNumber, int person, class seatInformation *addSeat)
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
