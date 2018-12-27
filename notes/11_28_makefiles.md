# Makefiles

## What is make

* It is a program designed to make large, complex programs easier to compile
* It uses a "makefile", which include instructions on dependencies and compilation order

## Components

* Comments - indicated by `#`
* Rules
  * Tell how and when to make a file
  * Two parts - dependency line and action
* Dependency Line: `hello.o: hello.cpp`
  * This shows `hello.o` as a module that requires `hello.cpp` If `hello.cpp` is newer than `hello.o`, then the action line is ran:
  * Dependencies should be listed in descending order
* Action (shell) line: `g++ -c hello.cpp`
  * Tells how to build the target. Can be more than one line.
  * Checks for errors after lines are ran.
  * Checks for an exit status after shell line
  * An exit error (1) will stop make
  * We can prefix a shell line with `-` to force it to run (shouldn't do this)
* Macros
  * A short string that represents a larger string
  * We define macros with `MACRO=value`
  * We use macros with `$(MACRO)`
  * make will replace `$(MACRO)` with `value`
  * Macros can be recursive
* Inference rules
  * The `%` is used to indicate a wild card
  * Examples `%.o`