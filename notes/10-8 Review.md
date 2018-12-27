10-8 Review
========================

Notes allowed: one sheet of 8.5x11 paper, front and back

Things to know:

	- Classes and access types
	- Member functions
	- Prototypes
	- Constructors (Default and Overloaded) `Classname()`
		- Copy Constructors `Classname(const Classname&)`
		- Initialization section (with colon)
	- Overloaded cin and cout functions `operator>>(istream if)`
		- Remember that `cin` & `cout` should not be used in class functions! Only generic streams
	- Friend functions `friend ostream&`
	- Overloaded operators `+,-,*,/,%`
		- Difference between copy constructor and overloaded =
	- Destructors
	- Dynamic Memory
		- Allocating with `new` and `delete`
		- Accessing with pointers (array access or dereferencing)
		- Pointer offset vs pointer index
	- Test if a file exists; open and read the file
	- Inheritance
		- Declaring derived classes `class Derived : public Base`
		- `protected` access
	- Virtual functions & pure virtual functions
		- pure `virtual int area() = 0`
	- Template functions
		- Difference between template functions and overloaded functions
		- `template<class T>`
		- 