# Recursion

## Example: factorial

Reminder: `5! = 5 * 4 * 3 * 2 * 1`

Each factorial can be defined as that number times the factorial of the previous number.

## Designing recursive routine

* Base case
  * Must have an ending point where the problem is solved
  * Must execute a return (in factorial, where n = 1)
* General case or recursive case
  * The main problem that is executed recursively

## Limitations

* Recursion works best when algorithm uses a naturally recursive function or data structure.
* Recursive algorithms may involve extensive overhead
* Each call takes time to execute and can require extra memory

```c++
long fact(int x)
{
    if ((n == 1) || (n == 0))
        return 1;
    else
        return(n * fact(n - 1));
}
```