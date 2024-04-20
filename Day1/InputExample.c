#include<stdio.h>

//scanf is the API used to take inputs from the user. 
//With one scanf, U can ask the user to enter 2 or more inputs. 
int main() {
	int num;
	float fTest;
	char strName[50];//For storing strings...

	//printf("Enter a number to store"); //Ask the user to enter
	//scanf("%d", &num);//Store the input value in the location of the num with data format as %d(digits). 
	//printf("The saved value: %d", num);

	//printf("Enter the number and floating value");
	//scanf("%d %f", &num, &fTest);

	//printf("The entered values are %d and %f", num, fTest);
	
	printf("Enter the Name");
	//scanf("%s", strName);
	fgets(strName, sizeof(strName), stdin);//syntax of using fgets...
	printf("The name is %s", strName);
	return 0;
}
//scanf has limitation of taking space as a delimiter, which means that ENTER and SPACE wil be taken as closure and anything that is entered post that will be discared. 
//fgets is prefered instead of scanf for handling string based inputs. 
