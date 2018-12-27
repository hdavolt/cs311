#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct book_list {
    int num;
    string title;
    string author;
    string desc;
    int month_read;
    int year_read;
    int rating;
};

void printBooks(const book_list books[], const int num, const int count);
book_list getBook(const int num); // Asks for a book, changes it, and returns it

int main()
{
    book_list books[500];
    int count = 0; // By default (no file) count is 0 so nothing is loaded
    int choice;

    // Open reading ilist or create one
    ifstream ilist;
    ilist.open("reading_list.txt");
    if (ilist.fail()) {
        cout << "reading_list.txt was not found and will be created\n";
    } else {
        cout << "reading_list.txt loaded successfully\n";
        // Get number of books from first line of file
        ilist >> count;
    }

    // Fill struct array from file
    for (int i = 0; i < count; i++) {    
        ilist >> books[i].num;
        ilist.ignore();
        getline(ilist, books[i].title);
        getline(ilist, books[i].author);
        getline(ilist, books[i].desc);
        ilist >> books[i].month_read;
        ilist.ignore();
        ilist >> books[i].year_read;
        ilist.ignore();
        ilist >> books[i].rating;
        ilist.ignore();
    }

    ilist.close();
    
    // Print main menu
    do {
        cout << "Main Menu:\n"
             << setw(7) << "1. " << "Print Books\n"
             << setw(7) << "2. " << "Enter New Book\n"
             << setw(7) << "3. " << "Modify A Book\n"
             << setw(7) << "4. " << "Print Book Count\n"
             << setw(7) << "5. " << "Print By Rating\n"
             << setw(7) << "6. " << "Save and Exit\n";
        cout << "What is your choice? ";
        cin >> choice;
        cin.ignore();
    
        switch(choice) {
        case 1:
            printBooks(books, 0, count);
            break;
        case 2:
            books[count] = getBook(count + 1);
            count++;
            break;
        case 3:
            int modify;
            cout << "Enter part to modify: ";
            cin >> modify;
            cin.ignore();
            books[modify - 1] = getBook(modify);
            break;
        case 4:
            cout << "Total number of books: " << count << "\n";
            break;
        case 5:
            int rating;
            cout << "Enter rating: ";
            cin >> rating;
            cin.ignore();
            for (int i = 0; i < count; i++) {
                if (books[i].rating == rating)
                    printBooks(books, i, i + 1);
            }
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice!\n";
        }
    
    } while(choice != 6);
    
    // Save ilist to file.
    ofstream olist;
    olist.open("reading_list.txt");
    if  (olist.fail()) {
        cout << "Error saving list. Goodbye...\n";
        exit(1);
    }
    
    olist << count << "\n";
    for (int i = 0; i < count; i++) {
        olist << books[i].num << "\n"
              << books[i].title << "\n"
              << books[i].author << "\n"
              << books[i].desc << "\n"
              << books[i].month_read << "\n"
              << books[i].year_read << "\n"
              << books[i].rating << "\n";
    }

    cout << "reading_list.txt saved successfully\n";
    olist.close();

    cout << endl;
    return 0;
}

void printBooks(const book_list books[], const int num, const int count)
{
    for (int i = num; i < count; i++) {
        cout << books[i].num << "\n"
             << books[i].title << "\n"
             << books[i].author << "\n"
             << books[i].desc << "\n"
             << books[i].month_read << "/" << books[i].year_read << "\n"
             << books[i].rating << "\n";
    }
}

book_list getBook(const int num)
{
    book_list new_book;
    new_book.num = num;
    cout << "Enter title: ";
    getline(cin, new_book.title);
    cout << "Enter author: ";
    getline(cin, new_book.author);
    cout << "Enter description: ";
    getline(cin, new_book.desc);
    cout << "Enter month: ";
    cin >> new_book.month_read;
    cin.ignore();
    cout << "Enter year: ";
    cin >> new_book.year_read;
    cin.ignore();
    cout << "Enter rating: ";
    cin >> new_book.rating;
    cin.ignore();

    return new_book;
}