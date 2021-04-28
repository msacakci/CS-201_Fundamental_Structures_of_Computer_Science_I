#ifndef __SIMPLESTUDENT_H
#define __SIMPLESTUDENT_H

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

//Metehan Sacakci, 21802788
//CS201 - 003

class Student
{
public:
    Student();
    ~Student();

    void setId( int idNo);
    void setStudentName( string name);
    void setNextPointer( Student* newNext);
    void addBook( const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void showAllCheckOut( int mode) const;

    int getId();
    string getStudentName();
    Student* getNextPointer();
    Book* findPointerOfSpecificBook( int bookId);
    int getCheckOutSize();
    Book* getCheckOutHead();

private:
    int id;
    string studentName;
    Student* next;

    Book* checkoutHead;
    int checkOutSize;
};

#endif // __SIMPLESTUDENT_H
