/*
    Harel Davolt
    h643b754
    Program #4

    This is the Checking account class, which inherits the Account class. This class includes the fee amount along with the account balance. This class will also redefine the debit and credit functions to charge a fee. The debit function will only charge a fee if the debit is successful.

    Data:
        fee: amount charged for debit or credit
    Functions:
        Default Constructor (everything is zero)
        Constructor (amount and fee)
        Debit (redefined)
        Credit (redefined)
*/

#ifndef __CHECKING_ACCOUNT__
#define __CHECKING_ACCOUNT__

#include "account.hpp"

class Checking_account : public Account
{
    public:
        Checking_account();
        Checking_account(double bal, double f);
        bool debit(double a);
        void credit(double a);
    private:
        double fee;
};

#endif