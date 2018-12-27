/*
    Harel Davolt
    h643b754
    Program #2

    These are the functions for the Odometer class.
*/

#include "odometer.hpp"

// Default constructor. Sets everything to zero.
Odometer::Odometer() : miles(0), gas_used(0), mileage(0)
{
}

// Constructor. Takes doubles for miles and gas used, calculates and stores
// mileage.
Odometer::Odometer(double m, double g) : miles(m), gas_used(g), mileage( m / g )
{
}

// Accessors. Returns data from class, one accessor for each variable (miles,
// gas used, and mileage).
double Odometer::get_miles()
{
    return miles;
}

double Odometer::get_gas_used()
{
    return gas_used;
}

double Odometer::get_mileage()
{
    return mileage;
}

// reset - Resets all readings to zero.
void Odometer::reset()
{
    miles = 0;
    gas_used = 0;
    mileage = 0;
}

// add_trip - takes doubles for miles driven and gas used. Adds to miles and gas
// already stored, and calculates new mileage.
void Odometer::add_trip(double m, double g)
{
    miles += m;
    gas_used += g;
    mileage += ( m / g );
}

// fuel_needed - takes number of miles planned, returns number of
// gallons needed based on mileage
// return plan / mileage
double Odometer::fuel_needed(double plan)
{
    return plan / mileage;
}