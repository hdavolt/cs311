# Namespaces_2_Preprocessors

## Namespaces cont.

### Unnamed namespaces

C++ allows us to create unnamed namespaces. This allows us to shield global data.

```c++
namespace
{

}
```

* They are a replacement for static declaration of variables.
* They are usable in the same program an dare used for declaring unique identifiers.
* They are only accessible within the same file.

### Using a namespace

* Scope resolution - Uses the `::` scope resolution operator.
* The using directive `using namespace name`.
* The using declaration `using std::cout` for specific commands.
  * Can override the using directive.
  * Can be limited in scope.

### Nested namespaces

We can define a namespace inside another.

### Namespace alias

We can create aliases for namespaces `namespace alias = outername::innername`

### Classes and namespaces

We can define and prototype a class within a namespace. The definition can be written in the namespace or later using scope resolution.

We can define methods (functions) outside of a namespace using operators, `namespace::obj::func()`

### Inline namespaces

The keyword `inline` in a namespace means that anything in that namespace can be used by the outer  namespace.

## Preprocessors in C++

* The preprocessor includes the instructions for the compiler, these instructions are executed before the source code is completed.
* Begins with a # sign.
* No semicolon needed.
* We have already seen `#include`

### Example preprocessors

* `#define` - a replacement instruction.
  * `#define SIZE 5` will replace SIZE with 5 throughout the code.
  * `#define MAX(a,b) ((a > b) ? a : b)
  * Only substitutes; does not check for data types.