	// Header file for a C-like library

typedef struct CStashTag {
	int size;
	int quantity;
	int next;
	// dynamically allocated memory
	unsigned char* storage;
}CStash;

void initialize(CStash* s, int size);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, int index);
int count(CStash* s);
void inflate(CStash* s, int increase);