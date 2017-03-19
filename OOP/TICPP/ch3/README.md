Chapter 3 notes

extern vs static variables:

	1. extern is global (visible everywhere) and therefore persistent (value exists after function calls, for example). It also seems that it needs to be defined in another file for extern to work?

	2. static is persistent (isn't destroyed after a function call, for example, but isn't available outside of its scope)


typedefs:

	In the context of structs, we can typedef a struct as a convenient way to store variables.
	
	The syntax for this is typdef struct MyStruct { int i; char c; } newType;

	Let's pick this syntax apart.  The typedef struct Mystruct says that we're defining a new type of struct that will be of type newType.

	The MyStruct bit it what's throwing me right now - it seems that we're declaring it as well as defining it.
