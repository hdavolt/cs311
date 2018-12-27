9-12 operators misc
========================

# Friends

We cannot include `operator <<` in our class by itself because we need the stream.  
To fix this, we use `friend`.  
```
class Class 
{
	public:
		friend ostream& operator<<(ostream& out_stream, const Class & c);
};

ostream& operator<<(ostream& out_stream, const Class & c)
{
	// function code here
}
```

This will give the `operator<<` function access to both the stream and the private members of `Class`.  
