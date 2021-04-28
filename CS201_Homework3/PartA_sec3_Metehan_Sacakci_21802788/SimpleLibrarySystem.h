#ifndef __SIMPLELIBRARYSYSTEM_H
#define __SIMPLELIBRARYSYSTEM_H

#include "SimpleStudent.h"
#include <string>
#include <iostream>

//Metehan Sacakci, 21802788
//Cs201 - 003

using namespace std;

class LibrarySystem {

public:
    LibrarySystem();
    ~LibrarySystem();

    void addStudent(const int studentId, const string studentName);

    void deleteStudent(const int studentId);

    void showStudent(const int studentId) const;

private:
    Student* studentsHead;
    int studentsSize;
};

#endif // __SIMPLELIBRARYSYSTEM_H

