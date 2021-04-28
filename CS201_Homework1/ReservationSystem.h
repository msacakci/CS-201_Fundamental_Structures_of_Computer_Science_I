#ifndef __RESERVATIONSYSTEM_H
#define __RESERVATIONSYSTEM_H

#include <iostream>
#include "Flight.h"
#include "Reservation.h"

//Metehan Sacakci, ID: 21802788

using namespace std;

class ReservationSystem
{
public:
    ReservationSystem();
    ~ReservationSystem();
    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );

    int makeReservation( const int flightNo, const int numPassengers,
                    const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );

private:
    Flight* flights;
    int totalFlightNumber;

    Reservation* reservations;
    int totalReservationNumber;
};

#endif // __RESERVATIONSYSTEM_H

