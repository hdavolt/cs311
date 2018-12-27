8-27 Filestreams, structs, classes
========================
# Filestreams
We are already processing streams with `cin` and `cout`  
We can do the same with files. 

## Writing to a file  
In order to write to a file, we need an output stream. We do this using `ofstream`.  
We create a stream with a name, for example `ofstream out;`.  
Once we create `out`, we can do the same things we do with `cout`, except it outputs to a file. For example, `out << 2 << endl`.  
To open a file use (for example) `out.open("myfile.txt");`.  
After we are done with a file, we should close it with `out.close();`.  
For our purposes, the first line of the file should be the number of records.  

## Reading from a file  
We read from a file with `ifstream`, for example `ifstream in;`.  
We can then use `in` the same way we would use `cin`.  
We can get single words with `in >>` or lines with `getline()`.  
Remember that `in >>` keeps the newline in the stream, which will break `getline()`. We can fix this using `in.ignore()`.  
We can find out if a file opened using `in.fail()`.  

# Structs
We declare a struct using `struct`. For example:

```
struct book // Define a struct called book
{
	long isbn;
	string title;
	string author;
};

int main (void)
{
	book b; // Declare a book struct called b
	b.isbn = 100; // Set isbn of book b to 100
}
```

# Classes

## Defining and declaring
Instead of a `struct` for books we could use a class.  
Use lowercase for structs, uppercase for classes.  
Struct variables are public, but class variables are private.  
In order to access a class variable, we must make it `public` (they are `private` by default).  
In `class Book{}`, `Book` is an class *object*. We can create *instances* of the object by declaring them like variables (for example) `Book b1,b2;`.  

```
class Book
{
	public:
		long isbn;
		string title;
	private:
		string author;
}

int main()
{
	Book b1; // Declare a Book class called b1 
	b1.isbn = 100;
	b1.author = "John"; // We can't do this because author is private.

	return 0;
}
```

## Member Functions
A class can contain its own functions. We define them using the `::` scope operator.  
We can call the same function for different instances.

```
class Book
{
	private:
		long isbn;
		string title;
		string author;
	public:
		void enter_book(void);
}

void Book::enter_book(); // Prototypes function enter_book in the scope of class Book

void Book::enter_book()
{
	cout << "Enter isbn";
	cin >> isbn;
	cout << "Enter title";
	cin >> title;
	cout << "Enter author";
	cin >> author;
}

int main()
{
	Book b1,b2; // Two independent Book instances
	b1.enter_book; // Calls enter_book function
	b2.enter_book; // Calls same function for b2

	return 0;
}
```

## Encapsulation
*Encapsulation* is how we hide data inside a class, creating an *abstract data type*.  
For example, the `string` class is an abstract data type, because we don't know how it stores its data. To access `string`, we use member functions.  
Functions that change the data when it is entered are called *mutator functions*.

```
void Book::enter_book(long i, string t, string a)
{
	isbn = i;
	title = t;
	author = a;
}
```
Functions that retrieve data entered are called *accessor functions*.  
An **API** or *application programmer interface* is a description of how to use a class.  
