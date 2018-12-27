/*
    Harel Davolt
    h643b754
    Program #5

    Template functions for ArrayDb class (NOTE: I had to move them to the 
    header file because I couldn't figure out how to avoid linker errors.)
*/



/* Found this solution online to avoid linker errors, but I couldn't make it 
work with the friend function.

template class ArrayDb<int>;
template class ArrayDb<char>;
template class ArrayDb<bool>;
template class ArrayDb<float>;
template class ArrayDb<double>;
template operator<< <int> ();
template operator<< <char>;
template operator<< <bool>;
template operator<< <float>;
template operator<< <double>; */