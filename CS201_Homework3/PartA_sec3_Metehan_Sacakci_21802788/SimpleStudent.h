#ifndef __SIMPLESTUDENT_H
#define __SIMPLESTUDENT_H

#include <string>
using namespace std;

//Metehan Sacakci, 21802788
//Cs201 - 003

class Student
{
public:
    Student();

    ~Student();

    void setId( int idNo);
    void setStudentName( string name);
    void setNextPointer( Student* newNext);

    int getId();
    string getStudentName();
    Student* getNextPointer();

private:
    int id;
    string studentName;
    Student* next;
};

#endif // __SIMPLESTUDENT_H


