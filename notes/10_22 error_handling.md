# 10-22 error handling

Up until now if we encountered an error, we would simply exit a program.

However, c++ allows us to handle errors, and create our own exceptions.

## try / catch block

This block allows us to enclose code that may cause an exception (try), and to run code when an exception is found (catch).

Again, C++ does some of these for us, but we will often have to write our own.

For example, if we try to divide by zero (at least on linux), an exception will be called. We can catch that exception and provide a custom output without ending our program.

### General rules

1. Specifies the type of exception it can catch.
2. Contains an exception header. (`...` catches all types).
3. If no exception is thrown in the `try` block, the `catch` block won't run.
4. The code will continue to run after the `catch` block.
5. If an exception is thrown in a `try` block, the remaining lines are ignored.
6. The program searches `catch` blocks in order, and runs the first one it finds.
7. We can specify a default `catch`

```c++
catch (int x)
{
    //exception handling code
}
```

In this catch block:

1. `x` is the catch block parameter
2. `int` specifies that block can catch an exception of type int
3. Only one parameter per block is allowed.

### Throwing an exception

For `try/catch` to work, the exception must be thrown in the `try` block.

The line `throw 4` throws the int 4; we can also throw strings, objects, etc.

### Catch order

Be careful how catch blocks are ordered! If using a generic `catch` block, it should be after all the others.

### Exception classes

C++ provides support to handle exceptions via hierarchy of classes.

The function `what` returns the string containing the exception object thrown by the built-in exception classes.

The `class exception` is the base class of the exception classes provide by c++, found in the header file `exception`.

Two classes of `exceptions`:

1. `runtime_error`
2. `logic_error`

### Creating an exception class

- Programmers can create their own exception classes
- To throw your own exceptions, use the `throw` statement
- Any class can be an exception class

```c++
class My_exception : public exception
{
}

// To call the exception
throw My_exception();
```

### Rethrowing an exception

After the exception passes control to the `catch` block, we can rethrow an eception; for example, if we only want to take part of an exception.

A function specifies the exceptions it throws in its heading:

```c++
void Get_exception() throw (exception)
{
}

catch (exception)
{
    throw; // rethrowing an exception
}
```

## Exception handling techniques

When an exceptions occurs, the programmer usually has three choices:

- Terminate the program
- Include code to recover from the exception and fix the problem
- Log the error and continue