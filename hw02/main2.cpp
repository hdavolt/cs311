/*
    Harel Davolt
    h643b754
    Program #2

    This is a program that tests the odometer class functions. This program
    will set up three odometers with different parameters, perform functions
    on them, and output the result.

    Set output to show fixed decimal numbers to one point
    Declare 3 Odometer instances
        First uses default constructor
        Second and Third uses overloaded constructor
    Code to run for each instance:
        Print instance number
        Print miles
        Print gas used
        Print calculated mileage
    Functions on instance 1:
        Add miles and gas used
        Print new miles, gas used, and mileage
    Functions on instance 2:
        Call reset function
        Print values to verify they are 0
    Functions on instance 3:
        Set planned miles to travel
        Call function to return gallons needed based on planned usage
*/

#include "odometer.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    Odometer od0;
    Odometer od1(200, 12);
    Odometer od2(50, 2.3);

    cout << "Odometer 1 (default)\n";
    cout << "Miles driven: " << od0.get_miles() << "\n";
    cout << "Gallons used: " << od0.get_gas_used() << "\n";
    cout << "Mileage: " << od0.get_mileage() << "\n";

    cout << "\n";

    cout << "Odometer 2\n";
    cout << "Miles driven: " << od1.get_miles() << "\n";
    cout << "Gallons used: " << od1.get_gas_used() << "\n";
    cout << "Mileage: " << od1.get_mileage() << "\n";

    cout << "\n";

    cout << "Odometer 3\n";
    cout << "Miles driven: " << od2.get_miles() << "\n";
    cout << "Gallons used: " << od2.get_gas_used() << "\n";
    cout << "Mileage: " << od2.get_mileage() << "\n";

    cout << "\n";

    double new_miles = 152.9;
    double new_gas = 8.3;
    cout << "Adding " << new_miles << " miles and " << new_gas << " gallons to "
         << "Odometer 1\n";
    od0.add_trip(new_miles, new_gas);
    cout << "The new values for Odometer 1 are:\n";
    cout << "Miles driven: " << od0.get_miles() << "\n";
    cout << "Gallons used: " << od0.get_gas_used() << "\n";
    cout << "Mileage: " << od0.get_mileage() << "\n";

    cout << "\n";

    cout << "Resetting Odometer 2\n";
    od1.reset();
    cout << "Verifying Odometer 2 Reset:\n";
    cout << "Miles driven: " << od1.get_miles() << "\n";
    cout << "Gallons used: " << od1.get_gas_used() << "\n";
    cout << "Mileage: " << od1.get_mileage() << "\n";
    
    cout << "\n";

    double planned_miles = 421.8;
    cout << "Using Odometer 3, planning a trip of " << planned_miles
         << " miles with a mileage of " << od2.get_mileage() << " mpg.\n";
    cout << "We would need " << od2.fuel_needed(planned_miles) << " gallons "
         << "of fuel to make the trip.";

    cout << endl;
    return 0;
}
