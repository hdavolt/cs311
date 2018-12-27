/*
    Harel Davolt
    h643b754
    Program #5
    
    This program tests the functions of the arraydb template class.

    Test default constructor

    For each data type (int, char, bool, float, double):
        Test constructors
        Test overloaded [] (at least one type)
        Test get_size function
        Test overloaded <<
    
    Create an arraydb from a static array

    Copy one arraydb to another (using constructor)

    Copy an array using overloaded =
*/

#include <iostream>
#include "arraydb.hpp"

using namespace std;

int main()
{
    // Create int arr with default constructor
    ArrayDb<int> emp_arr;
    cout << "Integer array with size " << emp_arr.get_size() << "\n";

    // Create int array with size 100 and same values
    ArrayDb<int> stat_arr(50, 5);
    cout << "Integer array with size " << stat_arr.get_size() 
         << " and values of 5\n";
    cout << "Values in array:\n" << stat_arr;
    
    ArrayDb<int> int_arr(50);
    cout << "Creating integer array with incremental numbers using []\n";
    for (unsigned int i = 0; i < int_arr.get_size(); i++)
    {
        int_arr[i] = i + 10;
    }
    cout << int_arr;

    cout << "Test char array:\n";
    ArrayDb<char> char_arr(30);
    char c = 'a';
    for (unsigned int i = 0; i < char_arr.get_size(); i++)
    {
        char_arr[i] = c;
        c++; // Always wanted to do this!
    }
    cout << char_arr;

    cout << "Test bool array:\n";
    ArrayDb<bool> bool_arr(20);
    bool b = 0;
    bool o = 1;
    for (unsigned int i = 0; i < (bool_arr.get_size()) - 1; i += 2)
    {
        bool_arr[i] = b;
        bool_arr[i + 1] = o;
    }
    cout << bool_arr;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Test float array:\n";
    ArrayDb<float> fl_arr(30);
    float f = 10.0;
    for (unsigned int i = 0; i < fl_arr.get_size(); i++)
    {
        fl_arr[i] = f + (i / 2.0);
    }
    cout << fl_arr;

    cout << "Test double array:\n";
    ArrayDb<double> db_arr(30);
    double d = -10.0;
    for (unsigned int i = 0; i < db_arr.get_size(); i++)
    {
        db_arr[i] = d - (i / 2.5);
    }
    cout << db_arr;

    cout << "Creating arraydb from static array.\n";
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "Static array: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\nArrayDb: ";
    ArrayDb<int> st_arr(arr, 10);
    cout << st_arr;

    cout << "Creating a new double array:\n";
    ArrayDb<double> db2_arr(30);
    cout << db2_arr;
    cout << "Copying double arrays with =\n";
    db2_arr = db_arr;
    cout << "New double array is now:\n";
    cout << db2_arr;
    
    return 0;
}