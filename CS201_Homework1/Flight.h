#ifndef __FLIGHT_H
#define __FLIGHT_H

//Metehan Sacakci, ID: 21802788

#include "Seat.h"
#include <iostream>
#include <string>
using namespace std;

class Flight
{
public:
    Flight();
    ~Flight();

    void setFlightNumber( int flightNo);
    void setNumberOfRows( int rowNo);
    void setNumberOfSeatsInEachRow( int columnNo);
    void setSeats();
    void changeSeatsAvailability( const int *seatRow, const char *seatCol, const int numPassangers, char status);
    void displayFlightSeats();

    int getFlightNumber();
    int getNumberOfRows();
    int getNumberOfSeatsInEachRow();
    int getTotalAvailableSeats();
    char checkSeat( int rowNo, char columnChar);

    Flight& operator=( Flight& right);

private:
    int flightNumber;

    Seat* seats;
    int numberOfRows;
    int numberOfSeatsInEachRow;
};

#endif // __FLIGHT_H
