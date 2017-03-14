// pointers to structs

typedef struct{ // why does the book have Structure3 here as well?

	char c;
	float f;
	int i;
	double d;

} Structure3;

int main(){
	Structure3 s1,s2;
	Structure3* sp = &s1;

	sp->c = 'a'; 	// reference struct member vars with -> when using a pointer
	sp->i = 1;
	sp->f = 3.14;
	sp->d = 0.00093;

	// now point to the other one
	sp = &s2;
	sp->c = 'b';
	sp->i = 2;
	sp->f = 4.14;
	sp->d = 1.00093;
}