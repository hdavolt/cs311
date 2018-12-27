/*
    Harel Davolt
    h643b754
    Program #5

    This is the arraydb class. This class defines a dynamic array that tracks
    the size of the array and the values of its members, which can be any
    type. This class includes constructors, destructors, and overloaded
    operators. It also includes a function to return the size of the array

    Data:
        Array size
        Array pointer
    Function
        Default constructor
        Constructor (size and value with default value of 0)
        Copy Constructor with defined length
        Copy Constructor
        Destructor
        Get array size (returns integer)
        Overloaded [] (and const)
        Overloaded =
        Overloaded << (friend)
    */
#ifndef __ARRAYDB_HPP__
#define __ARRAYDB_HPP__

#include <iostream>
using namespace std;

template<class Ta>
class ArrayDb
{
    private:
        unsigned int size;
        Ta *arr_ptr;
    public:
        ArrayDb<Ta>();
        ArrayDb<Ta>(unsigned int s, Ta val = 0.0);
        ArrayDb<Ta>(const Ta *arr_in, unsigned int s);
        ArrayDb<Ta>(const ArrayDb &a);
        ~ArrayDb<Ta>();

        unsigned int get_size() const;
        Ta &operator[] (unsigned int i);
        const Ta &operator[] (unsigned int i) const;
        ArrayDb<Ta> &operator= (const ArrayDb<Ta> &a);
        template<class Tb>
        friend ostream &operator<< (ostream &out, const ArrayDb<Tb> &a);
};

#endif

// Default constructor
template<class Ta>
ArrayDb<Ta>::ArrayDb()
{
    arr_ptr = nullptr;
    size = 0;
}

// Constructor that takes a size and value, defaults to zero
template<class Ta>
ArrayDb<Ta>::ArrayDb(unsigned int s, Ta val)
{
    arr_ptr = new Ta[s];
    if (arr_ptr == nullptr)
    {
        cerr << "Can't allocate array!";
        exit(1);
    }
    size = s;
    for (unsigned int i = 0; i < size; i++)
        arr_ptr[i] = val;
}

// Create an ArrayDb from a given array and size
template<class Ta>
ArrayDb<Ta>::ArrayDb(const Ta *arr_in, unsigned int s)
{
    arr_ptr = new Ta[s];
    size = s;
    for (unsigned int i = 0; i < size; i++)
        arr_ptr[i] = arr_in[i];
}

// Copy constructor
template<class Ta>
ArrayDb<Ta>::ArrayDb(const ArrayDb &a)
{
    arr_ptr = new Ta[a.size];
    for (unsigned int i = 0; i < a.size; i++)
        arr_ptr[i] = a.arr_ptr[i];
}

// Destructor
template<class Ta>
ArrayDb<Ta>::~ArrayDb()
{
    if (arr_ptr != nullptr)
        delete [] arr_ptr;
}

// Return array size
template<class Ta>
unsigned int ArrayDb<Ta>::get_size() const
{
    return size;
}

// Overloaded brackets
template<class Ta>
Ta &ArrayDb<Ta>::operator[] (unsigned int i)
{
    if (i < 0 || i >= size)
    {
        cerr << "Out of bounds!";
        exit(1);
    }
    return arr_ptr[i];
}

// Overloaded brackets (const)
template<class Ta>
const Ta &ArrayDb<Ta>::operator[] (unsigned int i) const
{
    if (i < 0 || i >= size)
    {
        cerr << "Out of bounds!";
        exit(1);
    }
    return arr_ptr[i];
}

// Overloaded =
template<class Ta>
ArrayDb<Ta> &ArrayDb<Ta>::operator= (const ArrayDb<Ta> &a)
{
    if (this == &a)
        return *this;
    delete arr_ptr;
    arr_ptr = new Ta[a.size];
    for (unsigned int i = 0; i < a.size; i++)
        arr_ptr[i] = a.arr_ptr[i];
    return *this;
}

// Overloaded <<
template <class Ta>
ostream &operator<< (ostream &out, const ArrayDb<Ta> &a)
{
    unsigned int i;
    for (i = 0; i < a.size; i++)
    {
        out << a.arr_ptr[i] << " ";
        if (i % 10 == 9)
            out << "\n";
    }
    if (i % 10 == 0)
    {
        out << endl;
    }
    return out;
}