#include <stdio.h>

void funA(int);
void funB(int);

int main(){
	funA(1);
	printf("\n");
}

void funA(int num){
	if(num <= 10){
		printf("%d  ", num);
		funB(num+1);
	}
}

void funB(int num){
	if(num <= 10){
		printf("%d  ", num);
		funA(num+1);
	}
}
