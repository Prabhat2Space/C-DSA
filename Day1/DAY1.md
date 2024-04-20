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
## Code2 : Demonstrates the usage of const keyword in C programming
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
//consts are set at compile time, so when we refer them in the code, the value wil be a literal and 
there will be no need to evaluate the value again by the runtime, thus making it more optimized compared to normal variables 
which are extracted everytime U refer them in the code. 
//It is recommended to name a const with UPPERCASE. 

**Output**
```
123
```
