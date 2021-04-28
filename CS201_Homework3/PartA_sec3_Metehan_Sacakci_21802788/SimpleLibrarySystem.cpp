#include "SimpleLibrarySystem.h"

//Metehan Sacakci, 21802788
//Cs201 - 003

LibrarySystem::LibrarySystem()
{
    studentsHead = NULL;
    studentsSize = 0;
}

LibrarySystem::~LibrarySystem()
{
    delete studentsHead;
}

void LibrarySystem::addStudent( const int studentId, const string studentName )
{
    cout << "--------------------------" << endl;

    if( studentId <= 0)
    {
        cout << "Student ID must be positive!" << endl;
    }

    else if( studentsSize == 0 && studentsHead == NULL)
    {
        studentsHead = new Student();
        studentsHead->setId( studentId);
        studentsHead->setStudentName( studentName);
        studentsHead->setNextPointer(NULL);
        cout << "Student: " << studentId << " - " << studentName << " is added." << endl;
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
                cout << "Student ID: " << studentId << " already exists!" << endl;
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
                    cout << "Student: " << studentId << " - " << studentName << " is added." << endl;
                }
            }
        }
    }
}

void LibrarySystem::deleteStudent( const int studentId)
{
    cout << "--------------------------" << endl;

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
        cout << "Student: " << studentId << " is not found!" << endl;
    }

    else if( found == 1 )
    {
        for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer() )
        {
            if( currentStudent -> getNextPointer() == temp && temp -> getNextPointer() != NULL )
            {
                currentStudent -> setNextPointer( temp -> getNextPointer() );
                temp -> setNextPointer( NULL );
                delete temp;
                studentsSize--;
                cout << "Student: " << studentId << " is deleted." << endl;
            }

            else if( currentStudent -> getNextPointer() == temp && temp -> getNextPointer() == NULL )
            {
                currentStudent -> setNextPointer(NULL);
                delete temp;
                studentsSize--;
                cout << "Student: " << studentId << " is deleted." << endl;
            }

            else if( studentsHead == temp && temp -> getNextPointer() != NULL)
            {
                studentsHead = temp -> getNextPointer();
                temp -> setNextPointer( NULL );
                delete temp;
                studentsSize--;
                cout << "Student: " << studentId << " is deleted." << endl;
            }

            else if ( studentsHead == temp && temp -> getNextPointer() == NULL)
            {
                studentsHead = NULL;
                delete temp;
                studentsSize--;
                cout << "Student: " << studentId << " is deleted." << endl;
            }
        }
    }
}

void LibrarySystem::showStudent(const int studentId) const
{
    cout << "--------------------------" << endl;

    int operationStatus = 0;

    for( Student* currentStudent = studentsHead; currentStudent != NULL; currentStudent = currentStudent -> getNextPointer() )
    {
        if( currentStudent -> getId() == studentId && operationStatus == 0)
        {
            //cout << "Student is found." << endl;
            cout << "Student Name: " << currentStudent -> getStudentName() << endl;
            cout << "Student ID: " << currentStudent -> getId() << endl;
            operationStatus = 1;
        }
    }

    if( operationStatus == 0)
    {
            cout << "Student ID: " << studentId << " is not found!" << endl;
    }
}
