#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX 5
#endif

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr; //Pointer for storing address
};
typedef struct Employee Node;

Node* createNode(FILE *);
void insertNode(Node**, FILE*);
void printList(Node*);


int main(){ // local variable first
	Node *first = NULL;
	FILE *fPtr = fopen("myData.txt","r");
	if (fPtr != NULL){
		while(!feof(fPtr)){
			insertNode(&first,fPtr);	
		}
		printList(first);
	}
}

void insertNode(Node**first, FILE* data){
	Node *New = createNode(data);
	if (*first == NULL)
		*first = New;
	else if (New !=NULL){
			
		New->ptr = *first;
		*first = New;
	}
}

void printList(Node *temp){
	printf("List: \n");
	while(temp != NULL){
		printf("Id: %d\tName:%s\tSalary: %.2lf\n", temp->id,temp->name, temp->salary);
		temp = temp->ptr;
	}
}

Node* createNode(FILE *fPtr){
	Node *ptr= NULL;
	if (!feof(fPtr)){
		ptr = malloc(sizeof(struct Employee));
		int ret = fscanf(fPtr, "%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
		if (ret == EOF){
			free(ptr);
		    ptr=NULL;	
		}
	}
	return ptr;
}


