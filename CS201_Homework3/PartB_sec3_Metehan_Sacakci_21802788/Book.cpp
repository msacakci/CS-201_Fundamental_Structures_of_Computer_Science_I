#include "Book.h"

//Metehan Sacakci, 21802788
//CS201 - 003

Book::Book()
{
    id = 0;
    title = "";
    year = 0;
    next = NULL;
}

Book::~Book()
{
    id = NULL;
    year = NULL;
    delete next;
    next = NULL;
}

void Book::setId( int idNumber)
{
    id = idNumber;
}

void Book::setTitle( string titleName)
{
    title = titleName;
}

void Book::setYear( int yearNumber)
{
    year = yearNumber;
}

void Book::setNextPointer( Book* newNext)
{
    next = newNext;
}

int Book::getId()
{
    return id;
}

string Book::getTitle()
{
    return title;
}

int Book::getYear()
{
    return year;
}

Book* Book::getNextPointer()
{
    return next;
}
