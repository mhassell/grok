// static casts - for well and reasonably well behaved casts, like one might
// use when casting from a more restrictive to a less restrictive type
// such as int -> float or int -> long (there's no loss of info here)

void func(int) {};

int main(){
	int i = 0x7fff;
	long l;
	float f;

	// castless conversions
	l = i;
	f = i;

	// also work
	l = static_cast<long>(i);
	f = static_cast<float>(i);

	// narrowing conversions (casting to a more restrictive type)

	i = l;  // may lose digits
	i = f;  // may lose info (like what?) 

	// eliminates warnings
	i = static_cast<int>(l);
	i = static_cast<int>(f);
	char c = static_cast<char>(i); // interesting!

	// forcing a conversion from void*
	void* vp = &i;
	// dangerous conversion (how so?)
	float* fp = (float*) vp;

	// new way is just as dangerous
	fp = static_cast<float*>(vp);

	// implicit type conversions
	double d = 0.0;
	int x = d; // automatic conversion
	x = static_cast<int>(d);

	//another automatic conversion (hmmm, this could cause problems, and doesn't throw an error
	// or warning when compiling!)
	func(d);
	func(static_cast<int>(d));

}