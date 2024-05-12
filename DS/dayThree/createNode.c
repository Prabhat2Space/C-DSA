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

Node* createNode(){
	Node *ptr = malloc(sizeof(struct Employee));
	if (ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = ptr;
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}


int main(){
	Node *ptr = createNode();
}
