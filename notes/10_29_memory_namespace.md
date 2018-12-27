# Memory models and Namespaces

## Memory models

### Storage duration

* Automatic - variables declared inside a function definition.
* Static - Variables defined outside a function or elsewhere using `static`.
* Dynamic - Allocated with the `new` operator.

### Scope and Linkage

* Describes how widely visible aname is in a file
* A variable declared in a function can be used only in that function
* A variable declared above the functions in a file are available for all functions in that file.
* *Linkage* dexcribes how a variable can be shared in different units.
  * External
  * Internal
* Scope of variables
  * Block scope `{}`
  * Function scope - can encompass multiple blocks
  * Global scope - known throughout the file (don't use this)z
  * Function prototype scope - only within the prototype arguments
  * Class scope - members declared in a class
  * Namespace scope - Variables declared inside a namespace
* Register variables
  * `register int count_fast`
  * Allows for faster cpu access than regular memory.
  * It suggests to the compiler to use register memory.
  * Similar to `inline` where the compiler directly inserts the code.

## Static duration

* Three types of linkage
  * External
    * Global declaration in file
  * Internal
    * `static` keyword, variable declared at beginning of file
  * No linkage
    * `static` keyword, inside function
    * Created at program creation, but only used inside function
* Lasts for the duration of the program
* Declare a global variable or use the keyword `static`

### Storage class specifiers

* auto - default
* register
* static
* extern
  * Used to reference a variable that has already been declared in another file (not used much)
* mutable
  * Used to override `const` for a specific variable

### cv-qualifiers

* `const` - value is not to be changed.
* volatile
  * The value can be changed, even outside the program (e.g. hardware device)
  * Forces the compiler to keep unused variables.

## Namespaces

* Names can refer to variables, functions, structures, enumerators, classes, and members.
* As projects grow, name conflicts increase.
* Different namespaces can solve problems.
* A namespace is a new area to define "scope" of variables.
* Variable names in a namespace can also be used in another namespace without conflict
* Namespaces are not types; they are scope names
* We use the scope operator `::` to declare a namespace `std::cout`
* We declare a namespace with `namespace name {}`