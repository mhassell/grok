// getting crazy with this!

typedef struct {
	int i,j,k;
} ThreeDPoint;

int main(){
	ThreeDPoint p[10];  // an array of 10 3D points

	for(int i = 0; i<10; i++){
		p[i].i = i+1;   // this doesn't mess up the compiler
		p[i].j = i+2;
		p[i].k = i+3;
	}
}