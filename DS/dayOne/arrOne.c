#include <stdio.h>

#ifndef NUM 
#define NUM 100
#endif 

void printArr(int *, int );
void fillArr(int *, int );

int isPrime(int); // number 1
void processArr(int *, int );//number 2


int main()
{
	int arr[NUM]  = {0};//Partial Initialization
	printArr(arr, NUM);// 0 0 0 0 0 0 ...
	printf("Enter the first Value: ");
	scanf("%d", &arr[0]); // 101 
	fillArr(arr, NUM);
	printArr(arr, NUM);//101 102 .. 200
	processArr(arr,NUM); 
	printArr(arr, NUM);//101 0 103 0 0 0 107 .... 199 0 

}

void fillArr(int *arr, int size){
	int cnt;
	for(cnt = 1 ;cnt < size; ++cnt)
		arr[cnt] = arr[0] + cnt;
}
void printArr(int *arr, int size){
	int cnt;
	for(cnt = 0 ;cnt < size; ++cnt)
		printf("%d  ", arr[cnt]);
	printf("\n");
}

int isPrime(int num){
	int flag = 1, cnt;
	for (cnt = 2; cnt <= num/2; ++cnt)
		if (num % cnt == 0){
			flag = 0;
			break;
		}

	return flag;
}

void processArr(int *arr, int size){
	int cnt;
	for (cnt = 0; cnt < size; ++cnt)
		if (isPrime(arr[cnt]) == 0)
			arr[cnt] = 0;
}
