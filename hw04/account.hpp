/*
    Harel Davolt
    h643b754
    Program #4

    This is the Account class. It is the base for all other accounts. It stores
    the account balance as its only data. It includes a constructor to
    initialize the account balance and an accessor to return the balance. It's
    member functions are debit to take money out of an account (if possible),
    and credit to put money in.

    Data:
        balance - account balance
    Functions:
        constructor - takes a value greater than 0
        get_balance - returns account balance
        debit - reduce account balance if possible
        credit - increase account balance
*/
#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

class Account
{
    public:
        Account();
        Account(double bal);
        double get_balance();
        bool debit(double a);
        void credit(double a);
    protected:
        double balance;
};

#endif