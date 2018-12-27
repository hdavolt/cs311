/*
    Harel Davolt
    h643b754
    Program #6

    This program tests the error handling for the arraydb class. It will 
    attempt to allocate too much memory for the array to catch a bad_alloc, and 
    it will catch our own out of bounds exception.

    Try to allocate huge array.
    Catch bad allocation.

    Allocate array of specific size
    Ask user for array index value
    Return error if out of bounds
*/

#include <iostream>
#include "arraydb.hpp"
#include "out_of_bounds.hpp"

int main()
{
    try
    {
        cout << "Trying to make a really big array!\n";
        // Note: The compiler warns about the error
        ArrayDb<double> big_array(5000000000);
        cout << "You shouldn't see this!\n";
    }
    catch (bad_alloc &ba)
    {
        cout << "Exception caught: " << ba.what() << "\n";
    }

    cout << "Creating an arraydb with size 50.\n";
    ArrayDb<int> small_array(50);
    for (int i = 0; i < 50; i++)
    {
        small_array[i] = i;
    }
    
    int index;
    cout << "Please enter an index to view: ";
    try
    {
        cin >> index;
        cout << "Index " << index << " is: " << small_array[index] << "\n";
    }
    catch (Bounds_except &be)
    {
        cout << be.what() << "\n";
    }
    cout << "Goodbye!\n";
}