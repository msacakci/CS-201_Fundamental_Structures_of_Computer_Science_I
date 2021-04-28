finalFlightSystemMS : Flight.o Reservation.o mainProgram.o ReservationSystem.o Seat.o
	g++ Flight.o Reservation.o mainProgram.o ReservationSystem.o Seat.o -o finalFlightSystemMS

Seat.o : Seat.cpp
	g++ -c Seat.cpp

Flight.o : Flight.cpp
	g++ -c -std=gnu++11 Flight.cpp

Reservation.o : Reservation.cpp
	g++ -c Reservation.cpp

ReservationSystem.o : ReservationSystem.cpp
	g++ -c -std=gnu++11 ReservationSystem.cpp

mainProgram.o : mainProgram.cpp
	g++ -c mainProgram.cpp




