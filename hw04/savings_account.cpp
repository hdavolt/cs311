/*
    Harel Davolt
    h643b754
    Program #4

    These are the functions for the savings account class.
*/

#include "savings_account.hpp"

// Default constructor
Savings_account::Savings_account() : Account(), interest_rate(0)
{
}

// Constructor that takes balance and interest rate
Savings_account::Savings_account(double bal, double i) : Account(bal),      
    interest_rate(i)
{
}

// Function to return interest amount
double Savings_account::calculate_interest()
{
    double interest = balance * ( interest_rate / 100 );
    return interest;
}