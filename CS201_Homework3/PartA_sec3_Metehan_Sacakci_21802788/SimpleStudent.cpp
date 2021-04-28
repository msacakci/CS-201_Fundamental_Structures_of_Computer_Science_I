#include "SimpleStudent.h"

//Metehan Sacakci, 21802788
//Cs201 - 003

Student::Student()
{
    id = 0;
    studentName = "";
    next = NULL;
}

Student::~Student()
{
    id = NULL;
    delete next;
    next = NULL;
}

void Student::setId( int idNo)
{
    id = idNo;
}

void Student::setStudentName(string name)
{
    studentName = name;
}

void Student::setNextPointer( Student* newNext)
{
    next = newNext;
}

int Student::getId()
{
    return id;
}

string Student::getStudentName()
{
    return studentName;
}

Student* Student::getNextPointer()
{
    return next;
}


