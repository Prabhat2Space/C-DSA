## Code1: User input to calculate the average marks and displays the list of all entered marks.

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
