// a C-like library converted to C++


struct Stash{ // no typedef!

	int size;
	int quantity;
	int next;
	unsigned char* storage;

	// can now include functions in C++
	void initialize(int size);
	void cleanup();
	int add(const void* element);
	void* fetch(int index);
	void inflate(int increase);

}