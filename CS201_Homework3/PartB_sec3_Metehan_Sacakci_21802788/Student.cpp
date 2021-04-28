#include "Student.h"

//Metehan Sacakci, 21802788
//CS201 - 003

Student::Student()
{
    id = 0;
    studentName = "";
    next = NULL;
    checkoutHead = NULL;
    checkOutSize = 0;
}

Student::~Student()
{
    id = NULL;
    delete next;
    next = NULL;
    checkOutSize = NULL;
    delete checkoutHead;
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

void Student::addBook( const int bookId, const string bookName, const int bookYear)
{
    if( checkoutHead == NULL)
    {
        checkoutHead = new Book();
        checkoutHead -> setId( bookId);
        checkoutHead -> setTitle( bookName);
        checkoutHead -> setYear( bookYear);
        checkoutHead -> setNextPointer(NULL);

        checkOutSize++;
    }

    else if( checkoutHead != 0 )
    {
        int operationStatus = 0;
        for( Book* currentBook = checkoutHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
        {
            if( currentBook -> getNextPointer() == NULL && operationStatus == 0 )
            {
                Book* temp = new Book();
                temp -> setId( bookId);
                temp -> setTitle( bookName);
                temp -> setYear( bookYear);
                temp -> setNextPointer( NULL);

                currentBook -> setNextPointer( temp);

                operationStatus = 1;

                checkOutSize++;
            }
        }
    }

}

void Student::deleteBook(const int bookId)
{
    Book* temp;

    for( Book* currentBook = checkoutHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
    {
        if( currentBook -> getId() == bookId)
        {
            temp = currentBook;
        }
    }

    for( Book* currentBook = checkoutHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
        {
            if( currentBook -> getNextPointer() == temp && temp -> getNextPointer() != NULL )
            {
                currentBook -> setNextPointer( temp -> getNextPointer() );
                temp -> setNextPointer( NULL );
                delete temp;
                checkOutSize--;
            }

            else if( currentBook -> getNextPointer() == temp && temp -> getNextPointer() == NULL )
            {
                currentBook -> setNextPointer(NULL);
                delete temp;
                checkOutSize--;
            }

            else if( checkoutHead == temp && temp -> getNextPointer() != NULL)
            {
                checkoutHead = temp -> getNextPointer();
                temp -> setNextPointer( NULL );
                delete temp;
                checkOutSize--;
            }

            else if ( checkoutHead == temp && temp -> getNextPointer() == NULL)
            {
                checkoutHead = NULL;
                delete temp;
                checkOutSize--;
            }
        }
}

void Student::showAllCheckOut( int mode) const
{
    for( Book* currentBook = checkoutHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
    {
        if( mode == 1)
        {
            cout << currentBook -> getId() << " - " << currentBook -> getTitle() << " - " << currentBook -> getYear() << " - Checked out by student " << id  << " - " << studentName << endl;
        }
        else if( mode == 2)
        {
            cout << currentBook -> getId() << " - " << currentBook -> getTitle() << " - " << currentBook -> getYear() << endl;
        }
    }
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

Book* Student::findPointerOfSpecificBook( int bookId)
{
    Book* temp;
    temp = NULL;

    for( Book* currentBook = checkoutHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
    {
        if( bookId == currentBook -> getId())
        {
            temp = currentBook;
        }
    }

    return temp;
}

int Student::getCheckOutSize()
{
    return checkOutSize;
}

Book* Student::getCheckOutHead()
{
    return checkoutHead;
}
