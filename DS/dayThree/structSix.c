#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr; //Pointer for storing address
};
typedef struct Employee Node;

int main(){
	Node *ptr = malloc(sizeof(struct Employee));
	if (ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = ptr;
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->ptr->id, ptr->ptr->name, ptr->ptr->salary);
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->ptr->ptr->id, ptr->ptr->ptr->name, ptr->ptr->ptr->salary);
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->ptr->ptr->ptr->ptr->ptr->id, ptr->ptr->ptr->ptr->ptr->name, ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->ptr->salary);
	}
}

