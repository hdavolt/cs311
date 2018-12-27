8-29 classes cont
========================
# Constructors

A constructor takes data into a class.  

1. A member function without a return type.
2. Has the same name as the class.
3. It must be public.
4. Can't be called in ordinary way.
5. Can be overloaded. *Overloaded functions* are functions with the same name but different parameters or signatures.  
	`int func(int, int);`
	`int func(double, double);`

## Default Constructor

A default constructor is a function that has no return type or paramaters. A default constructor should always be defined. If no default constructor is defined, the compiler will create an empty one for you.

```
Book(); // Within a class under public:

Book::Book();
{
	// Any code can go here, should be related to the class
	string title = "Default book";
	string author = "Default author";
}
```
If we create an class object with no parameters, then the default constructor will be called.

## Overloaded Contructors

These constructors use parameters so we can specify our input into the class. Once we supply an overloaded constructor, the compiler will no longer provide a default constructor.

```
class Book 
{
	public:
		Book(string t, string a);
	private:
		string title;
		string author;
};

Book::Book(string t, string a)
{
	title = t;
	author = a;
}
```

# Member (Private) Functions

Private functions have access to all private variables in a class.

```
class Rect 
{
	public:
		Rect(int h, int w); // Overloaded contstructor
	private:
		int h;
		int w;
		int a;
		int calc(); // We do not need to pass h and w, calc() already has access.
};

int Rect::calc() // We need to specify the class
{
	a = h * w;
	return a;
}

Rect:Rect(int h, int w)
{
	cout << "Enter height: ";
	cin >> h;
	cout << "Enter width: ";
	cin >> w;
}
```

Note: do not create an instance with blank parameters, such as `book a1();`. The compiler will not construct the instance properly. Use `book a1;` for the default constructor.

# Accessor functions

Public functions that access private variables. (Continued example)

```
public:
	int return_area(); // prototype in class

int Rect::return_area()
{
	return a; // a is a private variable
}

Rect r1(3, 8);
cout << r1.return_area() // Should return 24
```

# Definitions

instance = declaration of a class
object = general reference to class or instance
member function = a function associated with a class

# Explicit constructor calls

```
Rect nr;
nr = Rect(5, 4);
```
 
This will create an instance called nr, then call a constructor to set parameters.