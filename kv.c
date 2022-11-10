#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void kv(int a, int b, int c){
	double x1, x2;
	
	double d = b*b-4*a*c;
	
	if(d > 0){
		x1 = ((-b)+sqrt(d)) / (2*a);
		x2 = ((-b)-sqrt(d)) / (2*a);
		
		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);
	}
	if(d < 0){
		printf("D < 0!\n");
	}
	if(d == 0){
		x1 = -(b / (2*a));
		printf("x1 = x2 = %f\n", x1);
	}
}

int main(int argc, char **argv){
	
	int a, b, c;
	
	if(argc != 4){
		printf("\nError. %d arguments found\n", argc-1);
		exit(1);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	
	printf("Enter a: %d\n", a);
	printf("Enter b: %d\n", b);
	printf("Enter c: %d\n", c);
	
	kv(a,b,c);
	
	return 0;
}
