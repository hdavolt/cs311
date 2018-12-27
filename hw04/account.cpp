/*
    Harel Davolt
    h643b754
    Program #4

    Functions for Account class
*/

#include "account.hpp"
#include <iostream>

using namespace std;

// Default constructor
Account::Account() : balance(0)
{
}

// Constructor that sets up account. Returns error on non-zero balance.
Account::Account(double bal)
{
    if (bal < 0)
    {
        cerr << "Invalid balance!\n";
    }
    else
    {
        balance = bal;
    }
}

// Returns account balance
double Account::get_balance()
{
    return balance;
}

// Takes money out of account, returns error if not possible
bool Account::debit(double a)
{
    if ((balance - a) < 0)
    {
        cerr << "Debit amount exceeded account balance!\n";
        return(false);
    }
    else
    {
        balance -= a;
        return(true);
    }
}

// Puts money in account
void Account::credit(double a)
{
    balance += a;
}