#include "Seat.h"

//Metehan Sacakci, ID: 21802788

Seat::Seat()
{
    rowNumber = 0;
    columnChar = 'C';
    availability = 'O';
}

Seat::~Seat()
{
    rowNumber = NULL;
    columnChar = NULL;
    availability = NULL;
}

void Seat::setRowNumber( int rowNo )
{
    rowNumber = rowNo;
}

void Seat::setColumnChar( int columnNo)
{
    char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    columnChar = alphabet[columnNo];


}

void Seat::setColumnCharWithChar( char column)
{
    columnChar = column;
}

void Seat::setAvailability( char avail)
{
    availability = avail;
}

int Seat::getRowNumber()
{
    return rowNumber;
}

char Seat::getColumnChar()
{
    return columnChar;
}

char Seat::getAvailability()
{
    return availability;
}

Seat& Seat::operator=( Seat& right)
{
    rowNumber = right.getRowNumber();
    columnChar = right.getColumnChar();
    availability = right.getAvailability();
}
