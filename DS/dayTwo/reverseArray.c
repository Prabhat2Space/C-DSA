#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef NUM 
#define NUM 100
#endif 

void printArr(int *, int );
void fillArr(int *, int );
void reverseArr(int *,int, int );

int main(){
	int arr[NUM];
	srand(time(NULL));
	fillArr(arr, NUM);
	printArr(arr, NUM);
	reverseArr(arr,0,NUM-1); 
	printArr(arr, NUM);
}
void reverseArr(int *arr, int startPos, int endPos){
	if (startPos>=endPos)
		return;
	int temp = arr[startPos];
	arr[startPos] = arr[endPos];
	arr[endPos] = temp;
	reverseArr(arr, startPos + 1, endPos - 1);
}
void fillArr(int *arr, int size){
	int cnt;
	for(cnt = 0 ;cnt < size; ++cnt)
		arr[cnt] = rand() % (NUM * 10);
}

void printArr(int *arr, int size){
	int cnt;
	for(cnt = 0 ;cnt < size; ++cnt)
		printf("%d  ", arr[cnt]);
	printf("\n");
}


