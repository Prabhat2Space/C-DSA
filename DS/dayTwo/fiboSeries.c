#include <stdio.h>
#ifndef NUM
#define NUM 10
#endif

int fibo(int num){
	if (num <=1)
		return num;
	return fibo(num-1) + fibo(num - 2);
}


int main(){
	int i;
	printf("printing Fibo Series:\n");
	for(i = 0; i < NUM;++i)
		printf("%d ---> %d\n", i+1, fibo(i));

}
