#include "Movie.h"

int main()
{
	movieInformation addMovie[MAX]; // 영화 정보 class 배열
	seatInformation addSeat[MAX]; // 좌석 정보 class 배열
	
	movieInput(addMovie); 
	int i;

	while(true) 
	{ 
		int select = selectMenu(); // 기능 선택함수 
		switch(select) 
		{	 
			case 1 : // 상영중인 영화 
				moviePrint(addMovie); 
				break;

			case 2: // 영화 예매 
				movieReservation(addMovie, addSeat); 
				break;

			case 3: // 좌석 출력 
				moviePrint(addMovie);
				cout << "몇번 영화를 예약 하셨나요? " << endl <<  "->";
				cin >> i;

				seatPrint(i, addSeat);
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
