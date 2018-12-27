/*
    Harel Davolt
    h643b754
    Program #4
    
    This is the savings account class, which inherits the account class. This
    class will hold the account balance as well as the interest rate on the
    account. It includes a constructor to take the balance and interest rate and
    a function to return the interest amount.

    Data:
        interest_rate: The interest rate of the account
    Functions:
        Default Constructor (everything is zero)
        Constructor (amount and interest rate)
        calculate_interest: returns the interest amount 
*/
#ifndef __SAVINGS_ACCOUNT__
#define __SAVINGS_ACCOUNT__

#include "account.hpp"

class Savings_account : public Account
{
    public:
        Savings_account();
        Savings_account(double bal, double i);
        double calculate_interest();
    private:
        double interest_rate;
};

#endif