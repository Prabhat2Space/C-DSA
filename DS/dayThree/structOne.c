#include <stdio.h>

struct Employee{
	int id;
	char name[25];
	double salary;
};

int main(){
	struct Employee var = {1001, "Veera Prathapa Reddy", 98723.34};

	printf("ID: %d\tName: %s\tSal:%.2lf\n", var.id, var.name, var.salary);
}

