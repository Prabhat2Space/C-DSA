## Code 1 : use of recursion to calculate powers and illustrates basic input-output operations in C 

```c

#include<stdio.h>

long long power(long long base, long long expo){
	if(expo == 0){
		return 1;
	}
	return base*power(base, expo-1);
}

void main(){
	long long base, expo;
	printf("Enter the base and the exponent (both non-negative integer):\n");
	scanf("%ld %ld", &base, &expo);

	printf("%ld raised to %ld is %ld\n", base, expo, power(base, expo));
}

```

**Output**
```
Enter the base and the exponent (both non-negative integer):
2 3
2 raised to 3 is 8


```
** From a compiler's point of view, let's analyze the given C code and explain the concepts used in it: **

** Header Inclusion: The code begins with #include<stdio.h>, which is a preprocessor directive to include the standard input-output library in the program.
This allows the program to use functions like printf() and scanf().
Function Declaration: The code defines a function power() that calculates the power of a base number raised to an exponent.
The function takes two parameters, base and expo, both of type long long, and returns a long long value. This function recursively computes the power using repeated multiplication.
Recursion: The power() function uses recursion to compute the power. It checks if the exponent is 0, in which case it returns 1 (base case). Otherwise, it multiplies the base by the result of power(base, expo-1).
Input and Output: In the main() function, the program prompts the user to enter the base and the exponent using printf() and reads the input using scanf(). 
It then calls the power() function with the provided base and exponent, and prints the result using printf().
Integer Overflow: It's worth noting that this code may encounter integer overflow for large inputs, especially for the result of base^expo. Since the return type and input types are long long, it mitigates the risk, but care should be taken when dealing with very large exponents. **

## Code 2 : Code to generate a Fibonacci series up to the nth term
```c
#include<stdio.h>
#include<string.h>

long long fibo(long long num){
	if (num <= 1){
		return num;
	}
	return fibo(num-1) + fibo(num-2); 
}

void main(){
	long long num;
	printf("Enter the n-th term till were you want to generate fibonacci series:\n");
	scanf("%ld", &num);
	printf("Fibonacci series is as follows:\n");
	for(int i=0; i<num; i++){
		printf("%d ----> %d\n", i+1, fibo(i));
	}
}
```
Header files:
#include<stdio.h>: This header file is included to use the standard input-output functions like printf and scanf.
#include<string.h>: This header file is included, but it's not necessary for this code.
Function fibo:
This function calculates the nth Fibonacci number recursively.
If the input num is 0 or 1, it returns num itself (base cases).
Otherwise, it recursively calls itself with num-1 and num-2 and returns the sum of the results.
Main function:
It prompts the user to enter the value of n (the number of terms in the Fibonacci series).
It reads the value of n from the user.
It then iterates from 0 to n-1 and prints the index (starting from 1) along with the corresponding Fibonacci number calculated using the fibo function.

**Output**
```
Enter the n-th term till where you want to generate the Fibonacci series:
10
Fibonacci series is as follows:
1 ----> 0
2 ----> 1
3 ----> 1
4 ----> 2
5 ----> 3
6 ----> 5
7 ----> 8
8 ----> 13
9 ----> 21
10 ----> 34
```

## Code 3 : Control flow of functions in C 
```c
#include<stdio.h>

// learning about control flow of functions

void fun();
void funOne();
void funTwo();
void funThree();


int main(){
	printf("1. in main()\n");
	fun();
	printf("2. in main()\n");
}

void fun(){
	printf("1. in fun()\n");
	funOne();
	printf("2. in fun()\n");
}

void funOne(){
	printf("1. in funOne()\n");
	funTwo();
	printf("2. in funOne()\n");
}

void funTwo(){
	printf("1. in funTwo()\n");
	funThree();
	printf("2. in funTwo()\n");
}

void funThree(){
	printf("funthree() called.\n");
}
```
**Output**
```
1. in main()
1. in fun()
1. in funOne()
1. in funTwo()
funthree() called.
2. in funTwo()
2. in funOne()
2. in fun()
2. in main()

```
Function Definitions:
The code defines five functions: main(), fun(), funOne(), funTwo(), and funThree().
Each function is responsible for printing a message indicating its entry and exit points.
Main Function:
main() serves as the entry point of the program.
It prints "1. in main()" and then calls the function fun().
After fun() returns, it prints "2. in main()" and exits.
Function Calls:
fun() calls funOne().
funOne() calls funTwo().
funTwo() calls funThree().
Control Flow:
The flow of execution starts from main().
It calls fun(), which in turn calls funOne(), funTwo(), and funThree() sequentially.
After funThree() finishes executing, control returns back to funTwo(), and then to funOne() and finally to fun().
Once fun() completes execution, control returns to main().
Output:
The output of the program shows the sequence of function calls and their respective entry and exit points.
Each function prints a message when it is entered and when it is about to exit.
The output helps understand the order in which functions are called and the flow of control between them.


## Code 4 : Program demonstrates finding factorial of numbers

```c
#include<stdio.h>

long long fact(long long f){
	if(f <= 1){
		return 1;
	}
	return f*fact(f-1);
}

void main(){
	long long f;
	printf("Enter a number for finding factorial:\n");
	scanf("%ld", &f);

	printf("Factorial of %ld is %ld\n", f, fact(f));
}

```
**Output**
```
Enter a number for finding factorial:
10
Factorial of 10 is 3628800
```

Function Definitions:
The code defines a function fact() that calculates the factorial of a given number recursively.
Main Function:
The main() function serves as the entry point of the program.
It prompts the user to enter a number for which the factorial needs to be calculated.
It then reads the input number and calls the fact() function to calculate the factorial.
Finally, it prints the calculated factorial.
Function Call:
The fact() function is called recursively to calculate the factorial.
Control Flow:
The flow of execution starts from the main() function.
It takes user input, calls the fact() function to calculate the factorial, and then prints the result.
The fact() function recursively calls itself until the base case is reached (when f <= 1), and then returns the factorial value.
Output:
The output of the program shows the factorial of the input number provided by the user.

## Code 5 : Program demonstrates Array reversing

```c
#include<stdio.h>

void revarr(int* arr, int first, int last);

void main(){
	int size;
	printf("Enter the size of an array:\n");
	scanf("%d", &size);
	int arr[size];
	printf("Enter value of each array element:\n");
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}

	printf("\nArray before reversing:\n");
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\nArray after reversing:\n");
	
	revarr(arr, 0, size-1);
	
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

}

void revarr(int* arr, int first, int last){
	if(first >= last)
		return;

	arr[first] ^= arr[last];
	arr[last] ^= arr[first];
	arr[first] ^= arr[last];
	
	revarr(arr, first+1, last-1);
	return;
}
```
**Output**
```
Enter the size of an array:
5
Enter value of each array element:
5
8
9
6
4

Array before reversing:
5 8 9 6 4 
Array after reversing:
4 6 9 8 5 
```

Code is designed to reverse an array using recursion.

How it works:

The main() function prompts the user to enter the size of the array and then the values of each element of the array.
It prints the array before reversing.
It calls the revarr() function to reverse the array.
Finally, it prints the array after reversing.

Logic of the revarr() function:

The revarr() function takes three arguments: the array pointer (arr), the index of the first element (first), and the index of the last element (last).
It uses bitwise XOR (^) operations to swap the elements at the first and last indices.
Then, it recursively calls itself with the updated first and last indices (incrementing first and decrementing last) until first is greater than or equal to last.
Finally, when the base condition (first >= last) is met, the function returns without any further recursion.

## Code 6 : Program Demonstrates Reverse Order Using Recursion.

```c
#include<stdio.h>

void recur(int);

int main(){
    recur(1);
    printf("\n");
}

void recur(int num){
    if(num<=10){
        printf("%d ", num); // Print the number
        recur(num+1); // Call recur with num+1
        printf("%d ", num); // Print the number again after recursion
    }
}

```
**Output**
```
1 2 3 4 5 6 7 8 9 10 10 9 8 7 6 5 4 3 2 1 
```
The code is designed to print numbers from 1 to 10 and then from 10 to 1 using recursion. Here's how it works:

The main() function calls the recur() function with the initial value of 1.
The recur() function takes an integer num as an argument and prints num if it's less than or equal to 10.
Then, it calls itself recursively with num+1 until num becomes greater than 10.
As the recursion unwinds, it prints num again in reverse order.

## Code 7 : Program Demonstrates the heap sort algorithm to sort an array of integers.

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef NUM
#define NUM 10
#endif


void heapSort(int* arr, int n);
int heapify(int* arr, int n, int i);
void swap(int* a, int* b);
void printArr(int*, int);
void fillArr(int*, int);

void main(){
	// using random number function to store values randomly.
	srand(time(NULL));
	int arr[NUM];
	fillArr(arr, NUM);
	printf("Before sorting:\n");
	printArr(arr, NUM);

	heapSort(arr, NUM);

	printf("After sorting:\n");
	printArr(arr, NUM);

}

void heapSort(int *arr, int n){
	for(int i = n/2 -1; i>=0; i--){
		heapify(arr, n, i);
	}

	for(int i=n-1; i>=0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int heapify(int* arr, int n, int i){
	int largest = i;
	
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(l < n && arr[l] > arr[largest]){
		largest = l;
	}

	if(largest != i){
		swap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int* arr, int size){
	int cnt;
	for(cnt=0; cnt<size; ++cnt){
		printf("%d ", arr[cnt]);
	}
	printf("\n");
}

void fillArr(int* arr, int size){
	int cnt;
	for(cnt=0; cnt<size; cnt++){
		arr[cnt] = rand() % (NUM*10);
	}
}
```
**Output**
```
Before sorting:
96 8 92 2 99 91 75 14 40 90 
After sorting:
2 8 14 40 75 90 91 92 96 99

```
This program demonstrates the implementation of heap sort algorithm to sort an array of integers in ascending order. 

Explanation of the code:

1. The `heapSort` function takes an integer array `arr` and its size `n` as input. It sorts the array using the heap sort algorithm.

2. In the `heapSort` function:
   - First, it creates a max heap by calling the `heapify` function for each non-leaf node in the array, starting from the last non-leaf node down to the root.
   - Then, it repeatedly extracts the maximum element from the heap (which is always at the root), places it at the end of the array, and heapifies the reduced heap.

3. The `heapify` function takes three parameters: the array `arr`, its size `n`, and an index `i` representing the root of a subtree. It ensures that the subtree rooted at index `i` satisfies the max heap property.
   - It first initializes the largest element as the root (`i`).
   - It then compares the root with its left and right child nodes (if they exist), and updates the largest element index accordingly.
   - If the largest element is not the root, it swaps the root with the largest element and recursively calls `heapify` on the affected subtree.

4. The `swap` function swaps the values of two integers passed as arguments.

5. The `printArr` function prints the elements of the array `arr` of size `size` to the console.

6. The `fillArr` function fills the array `arr` of size `size` with random integer values.

In the `main` function:
- It initializes the random number generator seed using the `srand` function based on the current time.
- It creates an array `arr` of size `NUM` and fills it with random integer values using the `fillArr` function.
- It prints the array before sorting using the `printArr` function.
- It sorts the array using the `heapSort` function.
- It prints the sorted array using the `printArr` function.

## Code 8 : Program Demonstrates implementation of the Quick Sort algorithm to sort an array of integers in ascending order.

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef NUM
#define NUM 10
#endif


void quickSort(int* arr, int l, int r);
int partition(int* arr, int l, int r);
void swap(int* a, int* b);
void printArr(int*, int);
void fillArr(int*, int);

void main(){
	// using random number function to store values randomly.
	srand(time(NULL));
	int arr[NUM];
	fillArr(arr, NUM);
	printf("Before sorting:\n");
	printArr(arr, NUM);

	quickSort(arr, 0, NUM-1);

	printf("After sorting:\n");
	printArr(arr, NUM);

}

void quickSort(int *arr, int l, int r){
	if(l < r){
		int pivot = partition(arr, l, r);
		quickSort(arr, l, pivot-1);
		quickSort(arr, pivot+1, r);
	}
}

int partition(int* arr, int l, int r){
	int pivot = arr[r];
	
	int i = l-1;
	for(int j = l; j <=r; j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i], &arr[j]);	
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int* arr, int size){
	int cnt;
	for(cnt=0; cnt<size; ++cnt){
		printf("%d ", arr[cnt]);
	}
	printf("\n");
}

void fillArr(int* arr, int size){
	int cnt;
	for(cnt=0; cnt<size; cnt++){
		arr[cnt] = rand() % (NUM*10);
	}
}
```
**Output**
```
Before sorting:
84 84 92 6 97 60 82 50 57 64 
After sorting:
6 50 57 60 64 82 84 84 92 97 
```
Program Demonstrates implementation of the Quick Sort algorithm to sort an array of integers in ascending order.

Explanation of the code:

1. The `quickSort` function takes an integer array `arr`, the left index `l`, and the right index `r` as input. It sorts the subarray `arr[l...r]` using the Quick Sort algorithm.
2. In the `quickSort` function:
   - It first checks if the left index `l` is less than the right index `r`. If not, it returns, indicating that the subarray is already sorted.
   - It selects a pivot element from the subarray (in this implementation, the last element `arr[r]` is chosen as the pivot).
   - It partitions the subarray around the pivot element by rearranging the elements such that all elements smaller than the pivot are placed before it, and all elements larger than the pivot are placed after it. The partitioning is done using the `partition` function.
   - It recursively calls `quickSort` for the left and right partitions of the subarray (elements less than and greater than the pivot, respectively).
3. The `partition` function takes three parameters: the array `arr`, the left index `l`, and the right index `r`. It partitions the subarray `arr[l...r]` around a pivot element and returns the index of the pivot after partitioning.
   - It initializes an index `i` to `l-1`.
   - It iterates through the subarray from index `l` to `r`. For each element `arr[j]`, if it is less than the pivot, it swaps `arr[j]` with `arr[i+1]` and increments `i`. This effectively moves all elements smaller than the pivot to the left side of the array.
   - Finally, it swaps the pivot element (located at index `r`) with the element at index `i+1` to place the pivot at its correct position in the sorted array.
4. The `swap` function swaps the values of two integers passed as arguments.
5. The `printArr` function prints the elements of the array `arr` of size `size` to the console.
6. The `fillArr` function fills the array `arr` of size `size` with random integer values.

In the `main` function:
- It initializes the random number generator seed using the `srand` function based on the current time.
- It creates an array `arr` of size `NUM` and fills it with random integer values using the `fillArr` function.
- It prints the array before sorting using the `printArr` function.
- It sorts the array using the `quickSort` function.
- It prints the sorted array using the `printArr` function.

## Code 9 : Program Demonstrates implementation of Tower of Hanoi problem solution using recursion.

```c
#include<stdio.h>

void hanoi(long long no_of_disks, int from_rod, int to_rod, int aux_rod);

void main(){
	long long n;
	printf("Enter the number of disks!\n");
	scanf("%ld", &n);
	int from_rod = 1, to_rod = 3, aux_rod = 2;

	hanoi(n, from_rod, to_rod, aux_rod);
}

void hanoi(long long n, int from_rod, int to_rod, int aux_rod){
	if(n == 0){
		return;
	}

	hanoi(n-1, from_rod, aux_rod, to_rod);
	printf("Move disk %ld from rod %d to rod %d\n", n, from_rod, to_rod);
	hanoi(n-1, aux_rod, to_rod, from_rod);
}
```
**Output**
```
Enter the number of disks!
3
Move disk 1 from rod 1 to rod 3
Move disk 2 from rod 1 to rod 2
Move disk 1 from rod 3 to rod 2
Move disk 3 from rod 1 to rod 3
Move disk 1 from rod 2 to rod 1
Move disk 2 from rod 2 to rod 3
Move disk 1 from rod 1 to rod 3

```
This program demonstrates the Tower of Hanoi problem solution using recursion. 

Explanation of the code:

1. The `hanoi` function is a recursive function that implements the Tower of Hanoi problem solution.
   - It takes four parameters:
     - `n`: The number of disks to move.
     - `from_rod`: The rod from which the disks are to be moved.
     - `to_rod`: The rod to which the disks are to be moved.
     - `aux_rod`: The auxiliary rod to use for the movement.
   - If `n` is 0 (no disks to move), the function returns without performing any action.
   - Otherwise, it recursively calls itself twice:
     - First, it moves `n-1` disks from the `from_rod` to the `aux_rod`, using `to_rod` as the auxiliary rod.
     - Then, it moves the remaining disk (the largest one) from the `from_rod` to the `to_rod`.
     - Finally, it recursively moves the `n-1` disks from the `aux_rod` to the `to_rod`, using `from_rod` as the auxiliary rod.
2. The `main` function takes input from the user for the number of disks (`n`).
3. It initializes the rod numbers (`from_rod`, `to_rod`, `aux_rod`) as 1, 3, and 2 respectively.
4. It calls the `hanoi` function with the input parameters (`n`, `from_rod`, `to_rod`, `aux_rod`).
5. The `hanoi` function recursively solves the Tower of Hanoi problem by moving disks from one rod to another, following the rules of the puzzle. It prints each movement step to the console, indicating which disk is moved and from which rod to which rod.
