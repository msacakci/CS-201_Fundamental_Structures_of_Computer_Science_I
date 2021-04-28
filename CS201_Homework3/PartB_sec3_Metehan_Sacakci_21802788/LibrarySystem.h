#ifndef __LIBRARYSYSTEM_H
#define __LIBRARYSYSTEM_H

#include <iostream>

#include "Student.h"
#include "Book.h"

#include <string>
using namespace std;

//Metehan Sacakci, 21802788
//CS201 - 003

class LibrarySystem
{
public:
    LibrarySystem();
    ~LibrarySystem();

    void addBook(const int bookId, const string bookName, const int bookYear);

    void deleteBook(const int bookId);

    void addStudent(const int studentId, const string studentName);

    void deleteStudent(const int studentId);

    void checkoutBook(const int bookId, const int studentId);

    void returnBook(const int bookId);

    void showAllBooks() const;

    void showBook(const int bookId) const;

    void showStudent(const int studentId) const;

private:
    Student* studentsHead;
    int studentsSize;

    Book* booksHead;
    int booksSize;

};


#endif // __LIBRARYSYSTEM_H
