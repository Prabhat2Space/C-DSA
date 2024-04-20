## Code1 : User input to calculate the average marks and displays the list of all entered marks.

```c
#include<stdio.h>
int main() {
	int marks[20], i, n, sum = 0, avg = 0;
	printf("Enter the number of elements: \n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter the marks at %d: ", i + 1);
		scanf("%d", &marks[i]);
		sum += marks[i];
	};
	printf("All the marks are set, lets see the average\n");
	avg = sum / n;
	printf("The Avg score is %d", avg);
	printf("The total Marks List: \n");
	for (int i = 0; i < n; i++)
	{
		printf("Marks at %d: %d\n", i + 1, marks[i]);
	}
	return 0;
}

```

**Output**
```
Enter the number of elements:
5
Enter the marks at 1: 80
Enter the marks at 2: 75
Enter the marks at 3: 90
Enter the marks at 4: 85
Enter the marks at 5: 95
All the marks are set, let's see the average.
The average score is 85.
The total Marks List:
Marks at 1: 80
Marks at 2: 75
Marks at 3: 90
Marks at 4: 85
Marks at 5: 95

```
## Code2 : Demonstrates the usage of const keyword in C
```c
#include<stdio.h>
//const helps in storing values that are not intended to be modified. It will be unchangable and readonly. 
int main() {
	const int x = 123;
	printf("%d", x);
	//x = 234;//Compile error if we try to change the const. 
	printf("%d", x);
	return 0;
}
```
Consts are set at compile time, so when we refer them in the code, the value wil be a literal and 
there will be no need to evaluate the value again by the runtime, thus making it more optimized compared to normal variables 
which are extracted everytime U refer them in the code. 
It is recommended to name a const with UPPERCASE. 

**Output**
```
123
```

## Code3 : use of variables and data types in C 
```c
#include<stdio.h>

int main() {
    // Declaring and initializing variables
    int myNum = 123;   // Integer variable to store whole numbers
    float fNum = 4356.56;   // Floating-point variable to store decimal numbers
    char myChar = 'P';   // Character variable to store single characters
    // Printing the values of variables
    printf("%d\n", myNum);   // %d is used as the format specifier for integers
    printf("%f\n", fNum);   // %f is used as the format specifier for floating-point numbers
    printf("%c\n", myChar);   // %c is used as the format specifier for characters
    return 0;
}
```
**Output**
```
123
4356.560059
P
```
Any kind of data that is required for computing the program should be stored into locations called VARIABLES. 
Every variable has to be declared before being using. 
The variable is created using format specifier. It means that a variable of a certain kind, can store data of that kind only
A variable can hold only one data at a time.
A variable is created based on the type of data, so data types play an important role in creating the variable. 

printf looks for format specifier while printing variables. %d for digits, %f for floating points, %lf for double,
%c for charecters, %s for strings. strings are not the part of primitive data types of C. They are type defs and are like Arrays. 

This program demonstrates the usage of the `scanf()` and `fgets()` functions in C programming to take input from the user:

```c
#include<stdio.h>

int main() {
    int num;
    float fTest;
    char strName[50]; // Array to store a string

    // Prompting the user to enter a name
    printf("Enter the Name: ");
    
    // Using fgets() to read a string with spaces
    fgets(strName, sizeof(strName), stdin);

    // Printing the entered name
    printf("The name is %s", strName);

    return 0;
}
```
## Code4 : Program demonstrates the usage of the scanf() and fgets() functions

```c
#include<stdio.h>

int main() {
    int num;
    float fTest;
    char strName[50]; // Array to store a string
// Prompting the user to enter a name
    printf("Enter the Name: ");
    // Using fgets() to read a string with spaces
    fgets(strName, sizeof(strName), stdin);
// Printing the entered name
    printf("The name is %s", strName);
    return 0;
}
```
**Output**
```
Enter the Name: Admiral Prabhat
The name is Admiral Prabhat
```

Explanation:
- In this program, we use the `fgets()` function to read a string input from the user, including spaces.
- The `fgets()` function reads input from the standard input stream (`stdin`) and stores it into the character array `strName`.
- The `sizeof(strName)` parameter specifies the maximum number of characters that `fgets()` can read, preventing buffer overflow.
- After reading the input, the program prints the entered name using the `printf()` function.

`fgets()` vs `scanf()`:
- `fgets()` is preferred for reading string inputs because it can handle spaces and prevents buffer overflow, unlike `scanf()`.
- `scanf()` has limitations in handling spaces, and it may discard characters after encountering a space or newline character.
- By using `fgets()`, we ensure that the entire input line, including spaces, is read and stored in the character array.

In this program, the commented-out lines demonstrate how `scanf()` can be used to read other types of inputs like integers and floating-point numbers. However, `scanf()` is not recommended for reading string inputs due to its limitations in handling spaces and potential buffer overflow issues.
