// using typedef with struct

typedef struct{
	char c;
	int i;
	float f;
	double d;

} Structure2;

int main(){
	// with typedef we're pretending that Structure2 is a built in type, don't need struct Structure2 s1,s2;
	Structure2 s1, s2;   
	s1.c = 'a';
	s1.i = 1;
	s1.f = 3.14;
	s1.d = 0.00093;

	s2.c = 'a';
	s2.i = 1;
	s2.f = 3.14;
	s2.d = 0.00093;
}