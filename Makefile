MovieTicket : main.o Reservation.o IO.o
	g++ -o MovieTicket main.o Reservation.o IO.o 

Reservation.o : Reservation.cpp
	g++ -c -o Reservation.o Reservation.cpp 

IO.o : IO.cpp
	g++ -c -o IO.o IO.cpp

main.o : main.cpp 
	g++ -c -o main.o main.cpp

clean : 
	rm *.o MovieTicket
