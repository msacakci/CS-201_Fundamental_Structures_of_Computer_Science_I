#ifndef __RESERVATION_H
#define __RESERVATION_H

//Metehan Sacakci, ID: 21802788

#include <iostream>
using namespace std;

class Reservation
{
public:
    Reservation();
    ~Reservation();

    void setReservationNumber( int reservNo);
    void setFlightNumber( int flightNo);
    void setNumOfPassangers( int numOfPassangers);
    void setSeatRowArr( const int* seatRow);
    void setSeatColArr( const char* seatCol);

    int getReservationNumber();
    int getFlightNumber();
    int getNumOfPassangers();
    int getSeatRowArrForIndex( int index);
    char getSeatColArrForIndex( int index);
    int* getSeatRowArr();
    char* getSeatColArr();

    Reservation& operator=( Reservation& right);

private:
    int reservationNumber;
    int flightNumber;
    int numOfPassangers;

    int* seatRowArr;
    char* seatColArr;

};

#endif // __RESERVATION_H
