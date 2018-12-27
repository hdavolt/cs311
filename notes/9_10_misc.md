9-10 misc
========================
Note on odometer homework: add_trip should be a separate function, not part of the overloaded constructor.

# Initialization Section

```
// Default constructor with initialization section
Rectangle::Rectangle (void) : len(100), width(200)

// Don't use parenthesis when declaring a class object without parameters
Rectangle r2; (this will set len to 100 and width to 200)
```

# Const

`const` is a modifier of a variable

```
void func(const Rect &r)
```
Use const to pass by reference but not allow changes.

# Inline Functions

Inline functions are functions written inside the class declaration. C++ normally doesn't do this; we would write class functions separately. If we put a function inside a class definition, the compiler will replace the function call. For example `inline void print()`.

# Static Members

A `static` variable inside a class declaration is a variable that is shared by all instances (objects) of a class.  
`static int num_of_stocks`. We initialize these variables at a gloval level `int Stock::num_of_stocks = 10`. We can also perform actions on these variables within class constructors, which will be called when a new instance is created. (For example, to count the number of stocks created.) If an array of n instances is created, the constructor will be called n times.

# Destructor

The program keeps track of an object from the time an object is constructed until it expires. At the time the object expires *(goes out of scope)* a **destructor** is called.  *Scopes: block, global, and function scope*

Destructor:
* Has no return type.
* Accepts no parameters (can't be overloaded).
* The name is `Class::~Class()` (The tilde is the key)
* Will not be created by compiler by default.

Note that declaration does not go out of scope, but assignment does! (She will explain more later)

# Operator Overloading

**Polymorphism** -- the ability to create multiple definitions for functions (function overloading) and operators (operator overloading).
*Example operators: + - / % <<*

When we write `x + y`, what happens is a function call to `+(x,y)`.  
To overload a function, we use `<ret_type>operator<op>(params)`  
An example of an overloaded operator is the string + operator.  
See example for overloaded operator to add vectors (Using `v3 = v1 + v2` which calls `v1.operator+ (v2)`)