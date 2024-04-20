#include<stdio.h>
//Structs are user defined data types that can group several related data into one real time representable unit. 
//Each variable inside the struct is called as Field or member of the struct. 
//structs can have only variables in it, however, other programming languages like C++ can allow structs to have functions also. 
struct Employee {
	int empId;
	char strName[50];
	char strAddress[200];
};

int main() {
	//U refer the struct by creating a variable of it. 
	Employee emp;
	printf("Enter the name, address and id of the Employee");
	scanf("%s %s %d", emp.strName, emp.strAddress, &emp.empId);
	printf("The info provided is: \n");
	printf("Name: %s\nAddress: %s\nId :%d ", emp.strName, emp.strAddress, emp.empId);
	return 0;
}
//PS: Newer compilers expect to initialize the struct variables by using {}
