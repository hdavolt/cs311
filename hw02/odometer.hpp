/* 
    Harel Davolt
    h643b754
    Program #2

    This is the odometer class. It tracks mileage and fuel efficieny, and has
    functions that will add miles driven / gas used to the odometer,
    calculate fuel efficiency, and reset the odometer.

    Data:
        miles - number of miles driven
        gas_used - gallons of gas used in driving
        mileage - fuel efficiency in miles per gallon
    Function:
        default constructor - sets miles, gas_used, mileage to 0.
        constructor - takes miles driven and gallons used, calculates mileage.
        accessors - accessor functions for miles driven, gallons used, and
        mileage
        reset - resets miles driven, gallons used, and mileage to zero.
        add_trip - adds miles driven and gallons used, updates mileage.
        fuel_needed - given number of miles planned, returns gallons needed
        based on fuel efficiency.
*/
class Odometer
{
    public:
        Odometer();
        Odometer(double mile, double gal);
        double get_miles();
        double get_gas_used();
        double get_mileage();
        void reset();
        void add_trip(double mile, double gal);
        double fuel_needed(double plan);
    private:
        double miles, gas_used, mileage;
};