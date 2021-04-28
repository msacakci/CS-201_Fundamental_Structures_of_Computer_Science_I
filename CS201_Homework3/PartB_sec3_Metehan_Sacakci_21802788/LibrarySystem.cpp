#include "LibrarySystem.h"

//Metehan Sacakci, 21802788
//CS201 - 003

LibrarySystem::LibrarySystem()
{
    studentsHead = NULL;
    studentsSize = 0;

    booksHead = NULL;
    booksSize = 0;
}

LibrarySystem::~LibrarySystem()
{
    delete studentsHead;
    delete booksHead;
}

void LibrarySystem::addBook( const int bookId, const string bookName, const int bookYear)
{
    if( bookId <= 0)
    {
        cout << "Book id must be positive integers!" << endl;
    }

    else if( bookId > 0)
    {
        if( booksSize == 0 && booksHead == NULL)
        {
            booksHead = new Book();
            booksHead -> setId( bookId);
            booksHead -> setTitle( bookName);
            booksHead -> setYear( bookYear);
            booksHead -> setNextPointer(NULL);

            booksSize++;
            cout << "Book " << bookId << " has been added." << endl;
        }

        else if( booksSize != 0 )
        {
            int operationStatus = 0;
            int found = 0;

            for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
            {
                if( bookId == currentBook -> getId() && found == 0)
                {
                    found = 1;
                    cout << "Book " << bookId << " already exists!" << endl;
                }
            }

            if( found == 0)
            {
                for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
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

                        booksSize++;
                        cout << "Book " << bookId << " has been added." << endl;
                    }
                }
            }
        }
    }
}

void LibrarySystem::deleteBook(const int bookId)
{
    int found = 0;
    Book* temp;
    temp = NULL;

    for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
    {
        if( currentBook -> getId() == bookId)
        {
            found = 1;
            temp = currentBook;
        }
    }

    for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer())
    {
        if( currentStudent -> findPointerOfSpecificBook( bookId) != NULL)
        {
            temp = currentStudent -> findPointerOfSpecificBook( bookId);
            returnBook( bookId);
            found = 2;
        }
    }

    if( found == 0 )
    {
        cout << "Book " << bookId << " does not exist!" << endl;
    }

    else if( found == 1 || found == 2 )
    {
        if( found == 2 )
        {
            for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
            {
                if( currentBook -> getId() == bookId)
                {
                    found = 1;
                    temp = currentBook;
                }
            }
        }

        for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
        {
            if( currentBook -> getNextPointer() == temp && temp -> getNextPointer() != NULL )
            {
                currentBook -> setNextPointer( temp -> getNextPointer() );
                temp -> setNextPointer( NULL );
                delete temp;
                booksSize--;
                cout << "Book " << bookId << " has been deleted." << endl;
            }

            else if( currentBook -> getNextPointer() == temp && temp -> getNextPointer() == NULL )
            {
                currentBook -> setNextPointer(NULL);
                delete temp;
                booksSize--;
                cout << "Book " << bookId << " has been deleted." << endl;
            }

            else if( booksHead == temp && temp -> getNextPointer() != NULL)
            {
                booksHead = temp -> getNextPointer();
                temp -> setNextPointer( NULL );
                delete temp;
                booksSize--;
                cout << "Book " << bookId << " has been deleted." << endl;
            }

            else if ( booksHead == temp && temp -> getNextPointer() == NULL)
            {
                booksHead = NULL;
                delete temp;
                booksSize--;
                cout << "Book " << bookId << " has been deleted." << endl;
            }
        }
    }
}

void LibrarySystem::addStudent( const int studentId, const string studentName )
{
    if( studentId <= 0)
    {
        cout << "Student ID must be positive!" << endl;
    }

    else if ( studentId > 0)
    {
        if( studentsSize == 0 && studentsHead == NULL)
        {
            studentsHead = new Student();
            studentsHead->setId( studentId);
            studentsHead->setStudentName( studentName);
            studentsHead->setNextPointer(NULL);
            cout << "Student " << studentId <<  " has been added." << endl;
            studentsSize++;
        }

        else if( studentsSize != 0)
        {
            int operationStatus = 0;
            int found = 0;

            for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer())
            {
                if( studentId == currentStudent -> getId() && found == 0 )
                {
                    found = 1;
                    cout << "Student " << studentId << " already exists!" << endl;
                }
            }

            if( found == 0)
            {
                for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer() )
                {
                    if( currentStudent -> getNextPointer() == NULL && operationStatus == 0 )
                    {
                        Student* temp = new Student();
                        temp -> setId( studentId);
                        temp -> setStudentName( studentName);
                        temp -> setNextPointer( NULL);

                        currentStudent -> setNextPointer( temp);

                        operationStatus = 1;

                        studentsSize++;
                        cout << "Student " << studentId <<  " has been added." << endl;
                    }
                }
            }
        }
    }

}

void LibrarySystem::deleteStudent( const int studentId)
{

    int found = 0;
    Student* temp;

    for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer() )
    {
        if( currentStudent -> getId() == studentId)
        {
            found = 1;
            temp = currentStudent;
        }
    }

    if( found == 0 )
    {
        cout << "Student " << studentId << " does not exist!" << endl;
    }

    else if( found == 1 )
    {
        while( temp -> getCheckOutHead() != NULL)
        {
            returnBook( temp -> getCheckOutHead() -> getId());
        }

        for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer() )
        {
            if( currentStudent -> getNextPointer() == temp && temp -> getNextPointer() != NULL )
            {
                currentStudent -> setNextPointer( temp -> getNextPointer() );
                temp -> setNextPointer( NULL );
                delete temp;
                studentsSize--;
                cout << "Student " << studentId << " has been deleted." << endl;
            }

            else if( currentStudent -> getNextPointer() == temp && temp -> getNextPointer() == NULL )
            {
                currentStudent -> setNextPointer(NULL);
                delete temp;
                studentsSize--;
                cout << "Student " << studentId << " has been deleted." << endl;
            }

            else if( studentsHead == temp && temp -> getNextPointer() != NULL)
            {
                studentsHead = temp -> getNextPointer();
                temp -> setNextPointer( NULL );
                delete temp;
                studentsSize--;
                cout << "Student " << studentId << " has been deleted." << endl;
            }

            else if ( studentsHead == temp && temp -> getNextPointer() == NULL)
            {
                studentsHead = NULL;
                delete temp;
                studentsSize--;
                cout << "Student " << studentId << " has been deleted." << endl;
            }
        }
    }
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
    Book* tempBook;
    tempBook = NULL;

    for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
    {
        if( bookId == currentBook -> getId())
        {
            tempBook = currentBook;
        }
    }

    if( tempBook == NULL)
    {
        for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer())
        {
            if( currentStudent -> findPointerOfSpecificBook( bookId) != NULL)
            {
                tempBook = currentStudent -> findPointerOfSpecificBook( bookId);
            }
        }

        if( tempBook != NULL)
        {
            cout << "Book " << bookId << " has been already checked out by another student!" << endl;
        }

        else if( tempBook == NULL )
        {
            cout << "Book " << bookId << " does not exist for checkout!" << endl;
        }
    }

    else
    {
        Student* tempStudent;
        tempStudent = NULL;
        for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer())
        {
            if( studentId == currentStudent -> getId())
            {
                tempStudent = currentStudent;
            }
        }

        if( tempStudent == NULL)
        {
            cout << "Student " << studentId << " does not exist for checkout!" << endl;
        }

        else if( tempStudent != NULL )
        {
            tempStudent -> addBook( tempBook -> getId(), tempBook -> getTitle(), tempBook -> getYear());

            for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
            {
                if( currentBook -> getNextPointer() == tempBook && tempBook -> getNextPointer() != NULL )
                {
                    currentBook -> setNextPointer( tempBook -> getNextPointer() );
                    tempBook -> setNextPointer( NULL );
                    delete tempBook;
                    booksSize--;
                }

                else if( currentBook -> getNextPointer() == tempBook && tempBook -> getNextPointer() == NULL )
                {
                    currentBook -> setNextPointer(NULL);
                    delete tempBook;
                    booksSize--;
                }

                else if( booksHead == tempBook && tempBook -> getNextPointer() != NULL)
                {
                    booksHead = tempBook -> getNextPointer();
                    tempBook -> setNextPointer( NULL );
                    delete tempBook;
                    booksSize--;
                }

                else if ( booksHead == tempBook && tempBook -> getNextPointer() == NULL)
                {
                    booksHead = NULL;
                    delete tempBook;
                    booksSize--;
                }
            }

            cout << "Book " << bookId << " has been checked out by student " << studentId << "." << endl;
        }
    }
}

void LibrarySystem::returnBook(const int bookId)
{
    Student* tempSecond;
    tempSecond = NULL;

    Book* temp;
    temp = NULL;

    for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
    {
        if( bookId == currentBook -> getId())
        {
            temp = currentBook;
        }
    }

    if( temp != NULL)
    {
        cout << "Book " << bookId << " has not been checked out." << endl;
    }

    else if( temp == NULL)
    {
        for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer())
        {
            if( currentStudent -> findPointerOfSpecificBook( bookId) != NULL )
            {
                temp = currentStudent -> findPointerOfSpecificBook( bookId);
                tempSecond = currentStudent;
            }
        }

        if( temp == NULL)
        {
            cout << "Book: " << bookId << " is not found!" << endl;
        }

        else if( temp != NULL)
        {
            if( booksSize == 0 && booksHead == NULL)
            {
                booksHead = new Book();
                booksHead -> setId( temp -> getId());
                booksHead -> setTitle( temp -> getTitle());
                booksHead -> setYear( temp -> getYear());
                booksHead -> setNextPointer(NULL);

                booksSize++;
            }

            else if( booksSize != 0 )
            {
                int operationStatus = 0;
                for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
                {
                    if( currentBook -> getNextPointer() == NULL && operationStatus == 0 )
                    {
                    Book* tempThird = new Book();
                    tempThird -> setId( temp -> getId());
                    tempThird -> setTitle( temp -> getTitle());
                    tempThird -> setYear( temp -> getYear());
                    tempThird -> setNextPointer( NULL);

                    currentBook -> setNextPointer( tempThird);

                    operationStatus = 1;

                    booksSize++;
                    }
                }
            }
            tempSecond -> deleteBook( bookId);

            cout << "Book " << bookId << " has been returned." << endl;
        }
    }
}

void LibrarySystem::showStudent(const int studentId) const
{
    int operationStatus = 0;

    for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer() )
    {
        if( currentStudent -> getId() == studentId && operationStatus == 0)
        {
            cout << "Student ID: " << currentStudent -> getId() << " Student Name: " << currentStudent -> getStudentName() << endl;

            if( currentStudent -> getCheckOutSize() == 0)
            {
                cout << "Student "  << studentId << " has no books." << endl;
            }

            else
            {
                cout << "Student " << studentId << " has checked out the following books:" << endl;
                cout << "Book Id - Book Name - Year" << endl;
                currentStudent -> showAllCheckOut(2);

            }
            operationStatus = 1;
        }
    }

    if( operationStatus == 0)
    {
            cout << "Student " << studentId << " does not exist!" << endl;
    }
}

void LibrarySystem::showAllBooks() const
{
    cout << "Book Id - Book Name - Year - Status " << endl;

    for(Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer())
    {
        cout << currentBook -> getId() << " - " << currentBook -> getTitle() << " - " << currentBook -> getYear() << " - Not checked out" << endl;
    }

    for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer())
    {
        currentStudent -> showAllCheckOut(1);
    }
}

void LibrarySystem::showBook(const int bookId) const
{
    Student* tempSecond;
    tempSecond = NULL;

    Book* temp;
    temp = NULL;

    for( Book* currentBook = booksHead; currentBook != NULL; currentBook = currentBook -> getNextPointer() )
    {
        if( bookId == currentBook -> getId())
        {
            temp = currentBook;
        }
    }

    if( temp != NULL)
    {
        cout << "" << bookId << " - " << temp -> getTitle() << " - " << temp -> getYear() << " - " << "Not checked out" << endl;
    }

    else if( temp == NULL)
    {
        for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer())
        {
            if(currentStudent -> findPointerOfSpecificBook( bookId) != NULL)
            {
                temp = currentStudent -> findPointerOfSpecificBook( bookId);
                tempSecond = currentStudent;
            }
        }

        if( temp == NULL)
        {
            cout << "Book " << bookId << " does not exist!" << endl;
        }

        else if( temp != NULL)
        {
            cout << "" << temp -> getId() << " - " << temp -> getTitle() << " - " << temp -> getYear() << " - " << "Checked out by student " << tempSecond -> getId() << endl;
        }
    }

}
