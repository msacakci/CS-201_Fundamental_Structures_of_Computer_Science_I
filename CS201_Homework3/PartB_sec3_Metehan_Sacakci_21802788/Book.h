#ifndef __BOOK_H
#define __BOOK_H

#include <string>
using namespace std;

//Metehan Sacakci, 21802788
//CS201 - 003

class Book
{
public:
    Book();
    ~Book();

    void setId( int idNumber);
    void setTitle( string titleName);
    void setYear( int yearNumber);
    void setNextPointer( Book* newNext);

    int getId();
    string getTitle();
    int getYear();
    Book* getNextPointer();


private:
    int id;
    string title;
    int year;
    Book* next;
};

#endif // __BOOK_H
