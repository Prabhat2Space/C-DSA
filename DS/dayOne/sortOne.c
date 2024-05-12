#ifndef NUM 
#define NUM 10
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int *, int );
void fillArr(int *, int );
void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int);

int main()
{
	srand(time(NULL));	
	int arr[NUM];
	fillArr(arr, NUM);
	printArr(arr, NUM);
	insertionSort(arr, NUM);
	printArr(arr, NUM);
}

void selectionSort(int *arr, int size){
	int i,j, mIndex;
	for (i = 0; i < size; ++i){
		mIndex = i;
		for(j = i +1; j<size; ++j)
			if (arr[j] < arr[mIndex])
					mIndex = j;
		int temp = arr[i];
		arr[i]=arr[mIndex];
		arr[mIndex] = temp;
	}
}

void insertionSort(int *arr, int size){
	int i, j, key;
	for (i=0; i < size; ++i){
		key = arr[i];
		j = i - 1;
		while (j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}
void bubbleSort(int *arr, int size){
	int i, j;
	for(i = 0; i < size - 1; ++i)
		for(j = 0;j < size -i - 1; ++j){
			if (arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= temp;
			}
		}
}

void printArr(int *arr, int size){
	int cnt;
	for(cnt = 0; cnt < size; ++cnt)
		printf("%d  ",arr[cnt]);
	printf("\n");
}

void fillArr(int *arr, int size){
	int cnt;
	for(cnt = 0; cnt < size;++cnt)
		arr[cnt] = rand() % (NUM * 10);

}
