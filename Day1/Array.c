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
