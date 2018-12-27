/*
    Harel Davolt
    h643b754
    Program #4

    This program performs functions to test the account class as well as the checking and savings account subclasses.

    Set output to two decimal places
    
    Try to create account with balance < 0
    Create account with balance and return it
    Add (credit) a balance and return it
    Subtract (debit) a balance and return it

    Try to create savings account with balance < 0
    Create savings account with balance and interest
    Show interest amount
    Credit interest amount to total

    Try to create checking account with negative balance
    Create checking account with fee
    Debit from checking with fee
    Try to debit too much from checking
    Credit to checking with fee
*/

#include <iostream>
#include "savings_account.hpp"
#include "checking_account.hpp"

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Try to create Account 1 with a negative balance.\n";
    Account act1(-9.00);

    cout << "Create Account 2 with a balance of $35.69\n";
    Account act2(35.69);
    cout << "Account 2 balance is: $" << act2.get_balance() << "\n";

    cout << "Credit $2.01 to Account 2.\n";
    act2.credit(2.01);
    cout << "Account 2 balance is now: $" << act2.get_balance() << "\n";
    
    cout << "Debit $2.01 from Account 2.\n";
    act2.debit(2.01);
    cout << "Account 2 balance is now: $" << act2.get_balance() << "\n";

    cout << "Try to debit $50 from Account 2.\n";
    act2. debit(50);
    cout << "Account 2 balance is: $" << act2.get_balance() << "\n";
    cout << "\n";

    cout << "Try to create Savings 1 with negative balance.\n";
    Savings_account sav1(-9, 0.1);

    cout << "Create Savings 2 with balance $24.28 and interest rate 2.02%\n";
    Savings_account sav2(24.28, 2.02);
    cout << "Savings 2 balance is: $" << sav2.get_balance() << "\n";
    cout << "Savings 2 interest amount is: $" << sav2.calculate_interest() 
         << "\n";
    
    cout << "Add interest amount to total.\n";
    sav2.credit(sav2.calculate_interest());
    cout << "Savings 2 balance is now: $" << sav2.get_balance() << "\n";
    
    cout << "Try to debit $30 from Savings 2.\n";
    sav2.debit(30);
    cout << "Savings 2 balance is: $" << sav2.get_balance() << "\n";
    cout << "\n";

    cout << "Try to create Checking 1 with negative balance.\n";
    Checking_account chk1(-9, 2);

    cout << "Create Checking 2 with balance of $20 and fee of $0.50\n";
    Checking_account chk2(20, .5);
    cout << "Checking 2 balance is: $" << chk2.get_balance() << "\n";

    cout << "Debit $5 from Checking 2 (plus fee).\n";
    chk2.debit(5);
    cout << "Checking 2 balance is now: $" << chk2.get_balance() << "\n";

    cout << "Try to debit $20 from Checking 2.\n";
    chk2.debit(20);
    cout << "Checking 2 balance is: $" << chk2.get_balance() << "\n";
    
    cout << "Credit $5 to Checking 2 (minus fee).\n";
    chk2.credit(5); 
    cout << "Checking 2 balance is now: $" << chk2.get_balance() << "\n";
    
    cout << endl;
    return 0;
}