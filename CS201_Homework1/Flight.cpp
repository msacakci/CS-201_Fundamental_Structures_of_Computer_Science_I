#include "Flight.h"

//Metehan Sacakci, ID: 21802788

Flight::Flight()
{
    flightNumber = 0;
    seats = NULL;
    numberOfRows = 0;
    numberOfSeatsInEachRow = 0;
}

Flight::~Flight()
{
    if( seats != NULL)
    {
        delete [] seats;
    }
    flightNumber = NULL;
    numberOfRows = NULL;
    numberOfSeatsInEachRow = NULL;
    seats = NULL;
}

void Flight::setFlightNumber( int flightNo)
{
    flightNumber = flightNo;
}

void Flight::setNumberOfRows( int rowNo)
{
    numberOfRows = rowNo;
}

void Flight::setNumberOfSeatsInEachRow( int columnNo)
{
    numberOfSeatsInEachRow = columnNo;
}

void Flight::setSeats()
{
    delete [] seats;
    seats = new Seat[ numberOfRows * numberOfSeatsInEachRow];

    int rowCounter;
    int columnCounter;
    int seatCounter;

    seatCounter = 0;
    rowCounter = 0;
    columnCounter = 0;

    while( rowCounter < numberOfRows )
    {
        columnCounter = 0;
        while( columnCounter < numberOfSeatsInEachRow )
        {
            seats[seatCounter].setRowNumber( rowCounter + 1);
            seats[seatCounter].setColumnChar( columnCounter);
            seats[seatCounter].setAvailability( 'O' );

            seatCounter = seatCounter + 1;
            columnCounter = columnCounter + 1;
        }
        rowCounter = rowCounter + 1;
    }
}

void Flight::changeSeatsAvailability( const int *seatRow, const char *seatCol, const int numPassangers, char status)
{
    for( int i = 0; i <  numberOfRows * numberOfSeatsInEachRow; i++)
    {
        for( int j = 0; j < numPassangers; j++)
        {
            if( seatRow[j] == seats[i].getRowNumber() && seatCol[j] == seats[i].getColumnChar())
            {
                seats[i].setAvailability(status);
            }
        }
    }
}

void Flight::displayFlightSeats()
{
    int rowCounter;
    int columnCounter;
    int seatCounter;
    string message;

    rowCounter = 0;
    columnCounter = 0;
    seatCounter = 0;
    message = "  ";

    for( char i = 'A'; i <= 'Z'; i++)
    {
        columnCounter = columnCounter + 1;
        message = message + i + " ";
        if( columnCounter == numberOfSeatsInEachRow)
        {
            i = 'Z';
        }
    }

    message = message + "\n";
    while ( rowCounter < numberOfRows)
    {
        columnCounter = -1;
        while( columnCounter < numberOfSeatsInEachRow)
        {
            if( columnCounter == -1)
            {
                int directRowCounter;
                directRowCounter = rowCounter + 1;

                message = message + to_string(directRowCounter) + " ";
            }
            else
            {
                message = message + seats[seatCounter].getAvailability() + " ";
                seatCounter = seatCounter + 1;

            }
            columnCounter = columnCounter + 1;
        }
        message = message + "\n";
        rowCounter = rowCounter + 1;
    }

    cout << message << endl;
}

int Flight::getFlightNumber()
{
    return flightNumber;
}

int Flight::getNumberOfRows()
{
    return numberOfRows;
}

int Flight::getNumberOfSeatsInEachRow()
{
    return numberOfSeatsInEachRow;
}

int Flight::getTotalAvailableSeats()
{
    int counter;
    counter = 0;

    for( int i = 0; i < (numberOfRows * numberOfSeatsInEachRow); i++ )
    {
        if( seats[i].getAvailability() == 'O' )
        {
            counter = counter + 1;
        }
    }
    return counter;
}

char Flight::checkSeat( int rowNo, char columnChar)
{
    int found;
    found = -1;

    for( int i = 0; i < (numberOfRows * numberOfSeatsInEachRow); i++)
    {
        if( seats[i].getRowNumber() == rowNo && seats[i].getColumnChar() == columnChar )
        {
            found = i;
            i = (numberOfRows * numberOfSeatsInEachRow) - 1;
        }
    }
    if( found != -1)
    {
        return seats[found].getAvailability();
    }
    else
    {
        return NULL;
    }

}

Flight& Flight::operator=( Flight& right)
{
    if( &right != this)
    {
        flightNumber = right.getFlightNumber();
        numberOfRows = right.getNumberOfRows();
        numberOfSeatsInEachRow = right.getNumberOfSeatsInEachRow();

        delete [] seats;

        seats = new Seat[ (right.getNumberOfRows() * right.getNumberOfSeatsInEachRow()) ];

        for( int i = 0; i < (right.getNumberOfRows() * right.getNumberOfSeatsInEachRow()); i++ )
        {
            seats[i] = right.seats[i];
        }


    }
    return *this;
}
