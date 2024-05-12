#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
};

int main(){
	struct Employee *ptr = malloc(sizeof(struct Employee));
	if (ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
}

