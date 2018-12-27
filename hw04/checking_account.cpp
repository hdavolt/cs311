/*
    Harel Davolt
    h643b754
    Program #4

    These are the functions for the checking account class.
*/

#include "checking_account.hpp"
#include <iostream>

using namespace std;

// Default constructor that sets everything to zero
Checking_account::Checking_account() : Account(), fee(0)
{
}

// Constructor that takes balance and fee
Checking_account::Checking_account(double bal, double f) : Account(bal), fee(f)
{
}

// Redefined Debit function
bool Checking_account::debit(double a)
{
    if (Account::debit(a) == false)
    {
        cerr << "No fee charged.\n";
        return(false);
    }
    else
    {
        Account::debit(fee);
        return(true);
    }
}

// Redefined Credit function
void Checking_account::credit(double a)
{
    Account::credit(a);
    Account::debit(fee);
}