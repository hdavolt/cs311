/*
    Harel Davolt
    h643b754
    Program #6

    This is the out of bounds error handler for the arraydb class. It will 
    catch out of bounds access errors.
*/

#ifndef __OUT_OF_BOUNDS_HPP__
#define __OUT_OF_BOUNDS_HPP__

#include <exception>

using namespace std;

class Bounds_except : public exception
{
    public:
        const char *what()
        {
            return "Out of bounds!";
        }
};

#endif