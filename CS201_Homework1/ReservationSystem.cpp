#include "ReservationSystem.h"

//Metehan Sacakci, ID: 21802788

ReservationSystem::ReservationSystem()
{
    flights = NULL;
    totalFlightNumber = 0;

    reservations = NULL;
    totalReservationNumber = 0;
}

ReservationSystem::~ReservationSystem()
{
    if( flights != NULL)
    {
        delete [] flights;
        flights = NULL;
    }

    if( reservations != NULL)
    {
        delete [] reservations;
        reservations = NULL;
    }

    totalFlightNumber = NULL;
    totalReservationNumber = NULL;
}

void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo)
{
    cout << "---------------------------" << endl;
    int found = -1;

    for( int i = 0; i < totalFlightNumber; i++)
    {
        if( flights[i].getFlightNumber() == flightNo )
        {
            found = i;
        }
    }


    if( found != -1)
    {
        cout << "Flight " << flightNo << " already exists." << endl;
    }

    else if( found == -1 && rowNo <= 0 )
    {
        cout << "Error: Row number cannot be negative or zero!" << endl;
    }

    else if( found == -1 && seatNo <= 0)
    {
        cout << "Error: Number of seats in each row cannot be negative or zero!" << endl;
    }

    else if( found == - 1 && seatNo > 0 && rowNo > 0)
    {
        if( totalFlightNumber == 0)
        {
            flights = new Flight[1];

            flights[0].setFlightNumber( flightNo);
            flights[0].setNumberOfRows( rowNo);
            flights[0].setNumberOfSeatsInEachRow( seatNo);
            flights[0].setSeats();
            totalFlightNumber = totalFlightNumber + 1;
            cout << "Flight " << flightNo << " is added successfully." << endl;
        }

        else if ( totalFlightNumber != 0 )
        {
            Flight* temp;
            temp = new Flight[totalFlightNumber + 1];

            for( int i = 0; i < totalFlightNumber; i++)
            {
                temp[i] = flights[i];
            }

            temp[totalFlightNumber].setFlightNumber(flightNo);
            temp[totalFlightNumber].setNumberOfRows( rowNo);
            temp[totalFlightNumber].setNumberOfSeatsInEachRow( seatNo);
            temp[totalFlightNumber].setSeats();

            delete [] flights;
            flights = temp;

            totalFlightNumber = totalFlightNumber + 1;
            cout << "Flight " << flightNo << " has been added successfully." << endl;
        }
    }
}

void ReservationSystem::cancelFlight( const int flightNo )
{
    cout << "---------------------------" << endl;
    int found;
    found = -1;

    for( int i = 0; i < totalFlightNumber; i++)
    {
        if( flights[i].getFlightNumber() == flightNo )
        {
            found = i;
            i = totalFlightNumber - 1;
        }
    }

    if( found == -1)
    {
        cout << "Flight " << flightNo << " does not exist." << endl;
    }

    else if ( found != -1 )
    {
        for( int i = 0; i < totalReservationNumber; i++)
        {
            if( reservations[i].getFlightNumber() == flightNo )
            {
                this->cancelReservation( reservations[i].getReservationNumber());
            }
        }

        if( totalFlightNumber == 1)
        {
            totalFlightNumber = 0;
            delete [] flights;
            flights = NULL;
        }

        else if( totalFlightNumber > 1)
        {

            Flight* temp;
            temp = new Flight[ totalFlightNumber - 1];

            for( int i = 0; i < found; i++ )
            {
                temp[i] = flights[i];
            }

            for( int i = found + 1; i < totalFlightNumber; i++)
            {
                temp[i - 1] = flights[i];
            }

            delete [] flights;
            flights = temp;
            totalFlightNumber = totalFlightNumber - 1;
        }

        cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;
    }
}

void ReservationSystem::showAllFlights()
{
    cout << "---------------------------" << endl;
    if( totalFlightNumber == 0 )
    {
        cout << " No flights exist " << endl;
    }
    else
    {
        cout << "Flights currently operated:" << endl;

        for( int i = 0; i < totalFlightNumber; i++)
        {
            cout << "Flight " << flights[i].getFlightNumber() << " ";
            cout << "( " << flights[i].getTotalAvailableSeats() << " available seats )" << endl;
        }
    }
}

void ReservationSystem::showFlight( const int flightNo )
{
    cout << "---------------------------" << endl;
    int found;
    found = -1;
    for( int i = 0; i < totalFlightNumber; i++)
    {
        if( flights[i].getFlightNumber() == flightNo )
        {
            cout << "Flight " << flights[i].getFlightNumber() << " ( " << flights[i].getTotalAvailableSeats() << " available seats )" << endl;
            flights[i].displayFlightSeats();
            found = i;
            i = totalFlightNumber - 1;
        }
    }
    if( found == -1)
    {
        cout << "Flight " << flightNo << " does not exist." << endl;
    }
}

int ReservationSystem::makeReservation( const int flightNo, const int numOfPassangers, const int* seatRow, const char* seatCol)
{
    cout << "---------------------------" << endl;
    int operationSuccess;
    int indexOfFlight;
    string warningMessage;

    warningMessage = "";
    operationSuccess = 1;

    indexOfFlight = -1;

    for( int i = 0; i < totalFlightNumber; i++)
    {
        if( flights[i].getFlightNumber() == flightNo)
        {
            indexOfFlight = i;
            for( int i2 = 0; i2 < numOfPassangers; i2++)
            {
                if( flights[indexOfFlight].checkSeat( seatRow[i2], seatCol[i2]) == 'X')
                {
                    operationSuccess = 0;
                    warningMessage = to_string( seatRow[i2]) + seatCol[i2] + " " + warningMessage ;
                }
            }
        }
    }

    if( indexOfFlight == -1)
    {
        cout << "Flight number cannot be found!" << endl;
        return -1;
    }

    else if( indexOfFlight != -1 && operationSuccess != 1)
    {
        cout << "In flight " << flightNo << ", not available seat(s) for the reservation request:";
        cout << " " << warningMessage << endl;
        return -1;
    }

    else if( operationSuccess == 1 && indexOfFlight != -1)
    {
        flights[indexOfFlight].changeSeatsAvailability( seatRow, seatCol, numOfPassangers, 'X');

        if ( totalReservationNumber == 0)
        {
            totalReservationNumber = 1;
            reservations = new Reservation[1];

            reservations[totalReservationNumber - 1].setReservationNumber( totalReservationNumber);
            reservations[totalReservationNumber - 1].setFlightNumber( flightNo);
            reservations[totalReservationNumber - 1].setNumOfPassangers( numOfPassangers);
            reservations[totalReservationNumber - 1].setSeatRowArr( seatRow);
            reservations[totalReservationNumber - 1].setSeatColArr( seatCol);

            cout << "Reservation is completed." << endl;
            cout << "Reservation Number: " << reservations[totalReservationNumber - 1].getReservationNumber() << endl;
            return reservations[totalReservationNumber - 1].getReservationNumber();

        }
        else
        {
            totalReservationNumber = totalReservationNumber + 1;

            Reservation* temp;
            temp = new Reservation[ totalReservationNumber];

            for ( int i = 0; i < totalReservationNumber - 1; i++)
            {
                temp[i] = reservations[i];
            }

            temp[totalReservationNumber - 1].setReservationNumber( totalReservationNumber);
            temp[totalReservationNumber - 1].setFlightNumber( flightNo);
            temp[totalReservationNumber - 1].setNumOfPassangers( numOfPassangers);
            temp[totalReservationNumber - 1].setSeatRowArr( seatRow);
            temp[totalReservationNumber - 1].setSeatColArr( seatCol);

            delete [] reservations;
            reservations = temp;

            cout << "Reservation is completed." << endl;
            cout << "Reservation Number: " << reservations[totalReservationNumber - 1].getReservationNumber() << endl;
            return reservations[totalReservationNumber - 1].getReservationNumber();
        }

    }
}

void ReservationSystem::cancelReservation( const int resCode)
{
    cout << "---------------------------" << endl;
    int found;
    found = -1;

    for( int i = 0; i < totalReservationNumber; i++)
    {
        if( reservations[i].getReservationNumber() == resCode )
        {
            found = i;
        }
    }

    if( found == -1)
    {
        cout << "No reservation under code " << resCode << endl;
    }
    else if( found != -1)
    {
        int indexOfFlight;
        indexOfFlight = -1;

        for( int i = 0; i < totalFlightNumber; i++)
        {
            if( reservations[found].getFlightNumber() == flights[i].getFlightNumber())
            {
                indexOfFlight = i;
                i = totalFlightNumber - 1;
            }
        }

        flights[indexOfFlight].changeSeatsAvailability( reservations[found].getSeatRowArr(), reservations[found].getSeatColArr(), reservations[found].getNumOfPassangers(), 'O');

        cout << "Reservation for the seats ";

        for( int i = 0; i < reservations[found].getNumOfPassangers(); i++)
        {
            cout << to_string( reservations[found].getSeatRowArrForIndex(i)) << reservations[found].getSeatColArrForIndex(i) << " ";
        }
        cout << "is canceled in Flight " << reservations[found].getFlightNumber() << endl;

        if( totalReservationNumber == 1)
        {
            totalReservationNumber = 0;
            delete [] reservations;
            reservations = NULL;
        }
        else if( totalReservationNumber > 1)
        {
            Reservation* temp;
            temp = new Reservation[ totalReservationNumber - 1];
            for( int i = 0; i < found; i++)
            {
                temp[i] = reservations[i];
            }

            for( int i = found + 1; i < totalReservationNumber; i++)
            {
                temp[i - 1] = reservations[i];
            }

            delete [] reservations;
            reservations = temp;

            totalReservationNumber = totalReservationNumber - 1;
        }
    }
}

void ReservationSystem::showReservation( const int resCode)
{
    cout << "---------------------------" << endl;
    int found;
    found = -1;

    for( int i = 0; i < totalReservationNumber; i++)
    {
        if( reservations[i].getReservationNumber() == resCode)
        {
            found = i;
            i = totalReservationNumber - 1;
        }
    }

    if( found == -1 )
    {
        cout << "No reservation under Code " << resCode << endl;
    }

    else if( found != -1)
    {
        cout << "Reservation under Code " << resCode << " in Flight " << reservations[found].getFlightNumber() << ": ";

        for( int i = 0; i < reservations[found].getNumOfPassangers(); i++)
        {
            cout << to_string( reservations[found].getSeatRowArrForIndex( i)) << reservations[found].getSeatColArrForIndex( i) << " ";
        }
        cout << endl;

    }
}

