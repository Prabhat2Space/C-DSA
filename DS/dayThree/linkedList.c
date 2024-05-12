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

Node* createNode();
void addAtBeg();
void disp();

Node *first = NULL;

int main(){
	addAtBeg();	
	addAtBeg();	
	addAtBeg();	
	disp();
	addAtBeg();	
	addAtBeg();	
	disp();
}

void addAtBeg(){
	Node *New = createNode();
	if (first == NULL)
		first = New;
	else{
		New->ptr = first;
		first = New;
	}
}


void disp(){
	Node *temp = first;
	while(temp != NULL){
		printf("Id: %d\tName: %s\tSal: %.2lf\n", temp->id,temp->name,temp->salary);
		temp = temp->ptr;
	}
}



Node* createNode(){
	Node *ptr = malloc(sizeof(struct Employee));
	if (ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
	}
	return ptr;
}


