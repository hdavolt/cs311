/*
    Harel Davolt
    h643b754
    Program #3

    This program performs operations on functions. It will present the user
    with a menu of choices including math operations as well as fraction
    reduction and showing a decimal equivalent.

    Set decimal output to two places
    int option
    loop (not exit option)
        print option menu
        switch (option)
            case 1: 
                add fractions
            case 2: 
                subtract fractions
            case 3: 
                multiply fractions
            case 4: 
                divide fractions
            case 5: 
                reduce a fraction
            case 6: 
                show decimal equivalent
            case 7: 
                exit
            default:
                error
*/
#include "fraction.hpp"

int main()
{
    int option;
    while (option != 7)
    {
        cout << "Fractions!\n";
        cout << "1. Add Fractions\n"
             << "2. Subtract Fractions\n"
             << "3. Multiply Fractions\n"
             << "4. Divide Fractions\n"
             << "5. Reduce a Fraction\n"
             << "6. Show the decimal equivalent\n"
             << "7. Exit\n";
        cout << "What would you like to do?\n";
        cin >> option;
        
        switch (option)
        {
            case 1:
            {
                Fraction a, b, c;
                cout << "Enter 1st Fraction (Numerator, Space, Denominator): ";
                cin >> a;
                cout << "Enter 2nd Fraction (Numerator, Space, Denominator): ";
                cin >> b;
                c = a + b;
                cout << "Result: " << c << "\n";
                break;
            }
            case 2:
            {
                Fraction a, b, c;
                cout << "Enter 1st Fraction (Numerator, Space, Denominator): ";
                cin >> a;
                cout << "Enter 2nd Fraction (Numerator, Space, Denominator): ";
                cin >> b;
                c = a - b;
                cout << "Result: " << c << "\n";
                break;
            }
            case 3:
            {
                Fraction a, b, c;
                cout << "Enter 1st Fraction (Numerator, Space, Denominator): ";
                cin >> a;
                cout << "Enter 2nd Fraction (Numerator, Space, Denominator): ";
                cin >> b;
                c = a * b;
                cout << "Result: " << c << "\n";
                break;
            }
            case 4:
            {
                Fraction a, b, c;
                cout << "Enter 1st Fraction (Numerator, Space, Denominator): ";
                cin >> a;
                cout << "Enter 2nd Fraction (Numerator, Space, Denominator): ";
                cin >> b;
                c = a / b;
                cout << "Result: " << c << "\n";
                break;
            }
            case 5:
            {
                Fraction a, b;
                cout << "Enter Fraction (Numerator, Space, Denominator): ";
                cin >> a;
                b = a.reduce();
                cout << "Result: " << b << "\n";
                break;
            }
            case 6:
            {
                Fraction a;
                double d;
                cout << "Enter Fraction (Numerator, Space, Denominator): ";
                cin >> a;
                d = a.get_decimal();
                cout << "Result: " << d << "\n";
                break;
            }
            case 7:
                break;
            default:
                cout << "Invalid Selection!\n";
                break;
        }
    cout << endl;
    }
    return 0;
}