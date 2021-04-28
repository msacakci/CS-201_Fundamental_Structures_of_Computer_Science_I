using namespace std;
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

//Metehan Sacakci
//ID: 21802788

void algorithm1 ( int*& arr1, int size1, int*& arr2, int size2, int*& arr3, int size3 )
{
    //Append all items in arr1 in the same order to arr3.
    for( int i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }

    int i2;
    int numberInserted;

    for( int i = 0; i < size2; i++)
    {
        numberInserted = 0;
        for( int i2 = size3 - 1; i2 >= 0 ; i2--)
        {
            if( arr3[i2] != NULL && i2 != 0 )
            {
                if( arr3[i2] < arr3[i2 - 1])
                {
                   int temp = arr3[i2 - 1];
                   arr3[i2 - 1] = arr3[i2];
                   arr3[i2] = temp;
                }

                if( numberInserted == 0)
                {
                    if( arr3[i2] < arr2[i] )
                    {
                        arr3[i2 + 1] = arr2[i];
                        numberInserted = 1;
                        i2++;
                    }
                    else if( arr3[i2] > arr2[i] && i2 + 1 < size3)
                    {
                        arr3[i2 + 1] = arr3[i2];
                        arr3[i2] = arr2[i];
                        numberInserted = 1;
                        i2++;
                    }
                }
            }
        }
    }
}

void algorithm2 ( int*& arr1, int size1, int*& arr2, int size2, int*& arr3, int size3 )
{
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int arr1IsFinished = 0;
    int arr2IsFinished = 0;

    while( i3 < size3 )
    {
        if( arr1[i1] < arr2[i2] && arr1IsFinished == 0 )
        {
            if( i1 == (size1 - 1))
            {
                arr1IsFinished = 1;
            }

            arr3[i3] = arr1[i1];
            i1++;
        }
        else if( arr2[i2] < arr1[i1] &&  arr2IsFinished == 0 )
        {
            if( i2 == (size2 - 1))
            {
                arr2IsFinished = 1;
            }

            arr3[i3] = arr2[i2];
            i2++;
        }
        else if( arr1IsFinished == 1 && arr2IsFinished == 0 )
        {
            if( i2 == (size2 - 1))
            {
                arr2IsFinished = 1;
            }

            arr3[i3] = arr2[i2];
            i2++;
        }
        else if( arr2IsFinished == 1 && arr1IsFinished == 0 )
        {
            if( i1 == (size1 - 1))
            {
                arr1IsFinished = 1;
            }

            arr3[i3] = arr1[i1];
            i1++;
        }
        i3++;
    }
}

int main()
{
    cout << "-------------CASE 1-------------" << endl;
    //Algorithm 1 and Case 1
    cout << "Algorithm 1" << endl;

    //n = 1000
    cout << "n = 1000" << endl;


    int size1 = 1000;
    int* arr1 = new int[size1];

    int size2 = 1000;
    int* arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
        //arr1[i] = rand();
        //arr2[i] = rand();
    }

    //sort( arr1, (arr1 + (size1 - 1)));
    //sort( arr2, (arr2 + (size2 - 1)));

    int* arr3 = new int[ size1 + size2];

    double duration;
    clock_t startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 1 and n = 1000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 2000
    cout << "n = 2000" << endl;


    size1 = 2000;
    arr1 = new int[size1];

    size2 = 2000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 1 and n = 2000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 3000
    cout << "n = 3000" << endl;


    size1 = 3000;
    arr1 = new int[size1];

    size2 = 3000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 1 and n = 3000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 4000
    cout << "n = 4000" << endl;


    size1 = 4000;
    arr1 = new int[size1];

    size2 = 4000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }


    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 1 and n = 4000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 5000
    cout << "n = 5000" << endl;


    size1 = 5000;
    arr1 = new int[size1];

    size2 = 5000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 1 and n = 5000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

 //Algorithm 2 and Case 1
    cout << "Algorithm 2" << endl;

    //n = 10000000
    cout << "n = 10000000" << endl;


    size1 = 10000000;
    arr1 = new int[size1];

    size2 = 10000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 2 and n = 10000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 20000000
    cout << "n = 20000000" << endl;


    size1 = 20000000;
    arr1 = new int[size1];

    size2 = 20000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 2 and n = 20000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 30000000
    cout << "n = 30000000" << endl;


    size1 = 30000000;
    arr1 = new int[size1];

    size2 = 30000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 2 and n = 30000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 40000000
    cout << "n = 40000000" << endl;


    size1 = 40000000;
    arr1 = new int[size1];

    size2 = 40000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 2 and n = 40000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 50000000
    cout << "n = 50000000" << endl;


    size1 = 50000000;
    arr1 = new int[size1];

    size2 = 50000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 1, Algorithm 2 and n = 50000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    cout << "-------------CASE 2-------------" << endl;
    //Algorithm 1 and Case 2
    cout << "Algorithm 1" << endl;

    //n = 1000
    cout << "n = 1000" << endl;


    size1 = 1000;
    arr1 = new int[size1];

    size2 = 1000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
        //arr1[i] = rand();
        //arr2[i] = rand();
    }

    //sort( arr1, (arr1 + (size1 - 1)));
    //sort( arr2, (arr2 + (size2 - 1)));

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 1 and n = 1000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 2000
    cout << "n = 2000" << endl;


    size1 = 2000;
    arr1 = new int[size1];

    size2 = 2000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 1 and n = 2000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 3000
    cout << "n = 3000" << endl;


    size1 = 3000;
    arr1 = new int[size1];

    size2 = 3000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 1 and n = 3000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 4000
    cout << "n = 4000" << endl;


    size1 = 4000;
    arr1 = new int[size1];

    size2 = 4000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }


    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 1 and n = 4000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 5000
    cout << "n = 5000" << endl;


    size1 = 5000;
    arr1 = new int[size1];

    size2 = 5000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 1 and n = 5000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

 //Algorithm 2 and Case 3
    cout << "Algorithm 2" << endl;

    //n = 10000000
    cout << "n = 10000000" << endl;


    size1 = 10000000;
    arr1 = new int[size1];

    size2 = 10000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 2 and n = 10000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 20000000
    cout << "n = 20000000" << endl;


    size1 = 20000000;
    arr1 = new int[size1];

    size2 = 20000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 2 and n = 20000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 30000000
    cout << "n = 30000000" << endl;


    size1 = 30000000;
    arr1 = new int[size1];

    size2 = 30000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 2 and n = 30000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 40000000
    cout << "n = 40000000" << endl;


    size1 = 40000000;
    arr1 = new int[size1];

    size2 = 40000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 2 and n = 40000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 50000000
    cout << "n = 50000000" << endl;


    size1 = 50000000;
    arr1 = new int[size1];

    size2 = 50000000;
    arr2 = new int[size2];

    for( int i = 0; i < size1; i++)
    {
        arr2[i] = i + 1;
        arr1[i] = size1 + i + 1;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 2, Algorithm 2 and n = 50000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    cout << "-------------CASE 3-------------" << endl;
    //Algorithm 1 and Case 3
    cout << "Algorithm 1" << endl;

    //n = 1000
    cout << "n = 1000" << endl;


    size1 = 1000;
    arr1 = new int[size1];

    size2 = 1000;
    arr2 = new int[size2];

    int value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    //sort( arr1, (arr1 + (size1 - 1)));
    //sort( arr2, (arr2 + (size2 - 1)));

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 1 and n = 1000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 2000
    cout << "n = 2000" << endl;


    size1 = 2000;
    arr1 = new int[size1];

    size2 = 2000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 1 and n = 2000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 3000
    cout << "n = 3000" << endl;


    size1 = 3000;
    arr1 = new int[size1];

    size2 = 3000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 1 and n = 3000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 4000
    cout << "n = 4000" << endl;


    size1 = 4000;
    arr1 = new int[size1];

    size2 = 4000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 1 and n = 4000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 5000
    cout << "n = 5000" << endl;


    size1 = 5000;
    arr1 = new int[size1];

    size2 = 5000;
    arr2 = new int[size2];


    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm1( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 1 and n = 5000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i]  << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //Algorithm 2 and Case 3
    cout << "Algorithm 2" << endl;

    //n = 10000000
    cout << "n = 10000000" << endl;


    size1 = 10000000;
    arr1 = new int[size1];

    size2 = 10000000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 2 and n = 10000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 20000000
    cout << "n = 20000000" << endl;


    size1 = 20000000;
    arr1 = new int[size1];

    size2 = 20000000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 2 and n = 20000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 30000000
    cout << "n = 30000000" << endl;


    size1 = 30000000;
    arr1 = new int[size1];

    size2 = 30000000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }
    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 2 and n = 30000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 40000000
    cout << "n = 40000000" << endl;


    size1 = 40000000;
    arr1 = new int[size1];

    size2 = 40000000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 2 and n = 40000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    //n = 50000000
    cout << "n = 50000000" << endl;


    size1 = 50000000;
    arr1 = new int[size1];

    size2 = 50000000;
    arr2 = new int[size2];

    value = 0;
    while ( value < size2 )
    {
        arr1[value] = 2 * value;
        value++;
    }

    value = 0;
    while ( value < size1 )
    {
        arr2[value] = 1 + 2 * value;
        value++;
    }

    arr3 = new int[ size1 + size2];

    duration;
    startTime = clock();

    algorithm2( arr1, size1, arr2, size2, arr3, size1 + size2);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution of Case 3, Algorithm 2 and n = 50000000 took " << duration << " milliseconds." << endl;

    //for( int i = 0; i < size1 + size2; i++)
    //{
    //    cout << arr3[i] << endl;
    //}

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    cout << "------------------------------" << endl;

    return 0;
}
