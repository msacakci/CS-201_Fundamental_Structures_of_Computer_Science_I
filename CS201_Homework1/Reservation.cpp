#include "Reservation.h"

//Metehan Sacakci, ID: 21802788

Reservation::Reservation()
{
    reservationNumber = 0;
    flightNumber = 0;
    numOfPassangers = 0;

    seatRowArr = NULL;
    seatColArr = NULL;
}

Reservation::~Reservation()
{
    if( seatRowArr != NULL)
    {
        delete [] seatRowArr;
    }

    if( seatColArr != NULL)
    {
        delete [] seatColArr;
    }

    reservationNumber = NULL;
    flightNumber = NULL;
    numOfPassangers = NULL;
}

void Reservation::setReservationNumber( int reservNo)
{
    reservationNumber = reservNo;
}

void Reservation::setFlightNumber( int flightNo)
{
    flightNumber = flightNo;
}

void Reservation::setNumOfPassangers( int passangerNumber)
{
    numOfPassangers = passangerNumber;
}

void Reservation::setSeatRowArr( const int* seatRow )
{
    delete [] seatRowArr;
    seatRowArr = new int[ numOfPassangers];

    for( int i = 0; i < numOfPassangers; i++)
    {
        seatRowArr[i] = seatRow[i];
    }
}

void Reservation::setSeatColArr( const char* seatCol )
{
    delete [] seatColArr;
    seatColArr = new char[ numOfPassangers];

    for( int i = 0; i < numOfPassangers; i++)
    {
        seatColArr[i] = seatCol[i];
    }
}

int Reservation::getReservationNumber()
{
    return reservationNumber;
}

int Reservation::getFlightNumber()
{
    return flightNumber;
}

int Reservation::getNumOfPassangers()
{
    return numOfPassangers;
}

int Reservation::getSeatRowArrForIndex( int index)
{
    return seatRowArr[index];
}

char Reservation::getSeatColArrForIndex( int index)
{
    return seatColArr[index];
}

int* Reservation::getSeatRowArr()
{
    return seatRowArr;
}

char* Reservation::getSeatColArr()
{
    return seatColArr;
}

Reservation& Reservation::operator=( Reservation& right)
{
    if( &right != this)
    {
        reservationNumber = right.getReservationNumber();
        flightNumber = right.getFlightNumber();
        numOfPassangers = right.getNumOfPassangers();

        delete [] seatRowArr;
        seatRowArr = new int[ numOfPassangers];

        for( int i = 0; i < numOfPassangers; i++ )
        {
            seatRowArr[i] = right.getSeatRowArrForIndex(i);
        }

        delete [] seatColArr;
        seatColArr = new char[ numOfPassangers];

        for( int i = 0; i < numOfPassangers; i++)
        {
            seatColArr[i] = right.getSeatColArrForIndex(i);
        }
    }
    return *this;
}
