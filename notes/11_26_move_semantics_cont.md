# Move semantics continued

## More implicit class members

1. destructor
2. copy constructor
3. copy assignment
4. move constructor
5. move assignment

These will be created if not explicity defined; by default, they won't do anything.

## Shallow copy vs Deep copy

* A *shallow copy* copies pointers with the same address.
* A *deep copy* copies pointers with new addresses (and memory).

A default copy constructor does a shallow copy, which we don't usually want.

To make a deep copy we need to duplicate the data in an overloaded constructor

## Move constructor

If we provide a copy constructor, a default move constructor is no longer created.

A default move constructor works like a default copy constructor, which we usually don't want.

A true move constructor creates a new reference to the original data and removes the original reference.

Generally, when passing large amounts of data, we want to use a move constructor.