#include <stdio.h>

int factorial(int);

int main(){
	printf("Factorial(5): %d\n", factorial(5));
}

int factorial(int num){
	if (num <=1)
		return 1;
	return num * factorial(num-1);
}


