/*
    Harel Davolt
    h643b754
    Program #3

    These are the functions for the Fraction class.
*/

#include <algorithm>
#include "fraction.hpp"

// Default constructor. Sets all values to 1
Fraction::Fraction() : numerator(1), denominator(1), decimal(1)
{
}

// Constructor. Takes ints for top and bottom, calculates decimal.
Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
{
    decimal = to_decimal();
}

// Accessor function to get decimal equivalent
double Fraction::get_decimal()
{
    return decimal;
}

// Overloaded math operators
Fraction Fraction::operator+ (const Fraction &f)
{
    int n, d;
    if (denominator == f.denominator)
    {
        // Just use new numerator
        n = numerator + f.numerator;
        d = denominator;
        return Fraction(n, d).reduce();
    }
    else
    {
        // Make temporary fractions by common denominator and reduce
        int an, bn;
        an = numerator * f.denominator;
        bn = f.numerator * denominator;
        n = an + bn;
        d = denominator * f.denominator;
        return Fraction(n, d).reduce();
    }
}

Fraction Fraction::operator- (const Fraction &f)
{
    int n, d;
    if (denominator == f.denominator)
    {
        // Just use new numerator
        n = numerator - f.numerator;
        d = denominator;
        return Fraction(n, d).reduce();
    }
    else
    {
        // Make temporary fractions by common denominator and reduce
        int an, bn;
        an = numerator * f.denominator;
        bn = f.numerator * denominator;
        n = an - bn;
        d = denominator * f.denominator;
        return Fraction(n, d).reduce();
    }
}

Fraction Fraction::operator* (const Fraction &f)
{
    int n = numerator * f.numerator;
    int d = denominator * f.denominator;
    return Fraction(n, d).reduce();
}

Fraction Fraction::operator/ (const Fraction &f)
{
    int n = numerator * f.denominator;
    int d = denominator * f.numerator;
    return Fraction(n, d).reduce();
}

// Overloaded io operators
ostream& operator<< (ostream& out, const Fraction &f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}

istream& operator>> (istream& in, Fraction &f)
{
    in >> f.numerator;
    in.ignore();
    in >> f.denominator;
    // Make sure the decimal function gets called
    f.decimal = f.to_decimal();
    return in;
}

// Converts fraction to decimal
double Fraction::to_decimal()
{
    double n = numerator;
    double d = denominator;
    return n / d;
}

Fraction Fraction::reduce()
{
    int g = __gcd(numerator, denominator);
    if (g == 1)
    {
        return *this;
    }
    else
    {
        Fraction a;
        a.numerator = numerator / g;
        a.denominator = denominator / g;
        return a;
    }
}