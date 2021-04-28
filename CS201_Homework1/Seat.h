#ifndef __SEAT_H
#define __SEAT_H

//Metehan Sacakci, ID: 21802788

#include <iostream>
using namespace std;

class Seat
{
public:
    Seat();
    ~Seat();

    void setRowNumber( int rowNo);
    void setColumnChar( int columNo);
    void setColumnCharWithChar( char column);
    void setAvailability( char avail);

    int getRowNumber();
    char getColumnChar();
    char getAvailability();

    Seat& operator=( Seat& right);

private:
    int rowNumber;
    char columnChar;
    char availability;
};
#endif // __SEAT_H
