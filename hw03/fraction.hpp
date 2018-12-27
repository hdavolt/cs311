/*
    Harel Davolt
    h643b754
    Program #3

    This is the fraction class. It includes fraction constructors and
    overloaded math operations for fractions. It also includes functions to
    find a decimal equivalent for a fraction and reduce fractions.

    Data:
        numerator - top number of fraction
        denominator - bottom number of fraction
        decimal equivalent - calculated decimal of fraction
    Functions:
        default constructor - sets all values to 1
        constructor - takes values for numerator / denominator, calculates
        decimal equivalent
        accessor for decimal - returns decimal equivalent
        math operators - overloaded math operations (+,-,*,/) for fractions
        io operators - overloaded operators << and >> for fractions
        to_decimal - function to calculate decimal equivalent
        reduce - function to reduce a fraction
*/

#ifndef __FRACTION_HPP__
#define __FRACTION_HPP__
#include <iostream>

using namespace std;

class Fraction
{
    public:
        Fraction();
        Fraction(int n, int d);
        double get_decimal();
        Fraction operator+ (const Fraction &f);
        Fraction operator- (const Fraction &f);
        Fraction operator* (const Fraction &f);
        Fraction operator/ (const Fraction &f);
        friend ostream& operator<< (ostream& out, const Fraction &f);
        friend istream& operator>> (istream& in, Fraction &f);
        double to_decimal();
        Fraction reduce();
    private:
        int numerator;
        int denominator;
        double decimal;
};
#endif