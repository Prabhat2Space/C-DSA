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

Node* createNode(char *);
void addAtBeg(Node**, char*);
void addAtEnd(Node**, char* );
void addAtPos(Node**, char *,int);
void deleteAtPos(Node**, int);
void disp(Node*);


int main(){ // local variable first
	char myData[] = "1001,Vaibhav Rathod,92374.345:1002,Amithab Rao,89374.56:1003,Sachin Wankade,87345.435:1004,Rahul Ghorpade,86345.34:1005,Nithin Reddy,93745.456";
	Node *first = NULL;
	char *str = strtok(myData,":");
	while(str != NULL){
		addAtEnd(&first,str);	
		str = strtok(NULL,":");
	}
	disp(first);
}

void deleteAtPos(Node**first,  int pos){
	
	if (*first == NULL){
		printf("List is empty...Nothing to do\n");
		return;	
	}
	Node *temp = *first;
	if (pos == 1){
		*first = (*first)->ptr;
	}else{
		int cnt = 1;
		Node *prev= NULL;
		while (temp!=NULL && cnt < pos){
			prev = temp;
			temp = temp->ptr;
			cnt++;
		}
		if (temp == NULL){
			printf("%d: No such position\n",pos);
			return;
		}
		prev->ptr = temp->ptr;
	}
	free(temp);	
}

void addAtPos(Node**first, char* data, int pos){
	Node *New = createNode(data);
	if (*first == NULL)
		*first = New;
	else{
		int cnt = 1;	
		Node *temp = *first;
		while (temp->ptr != NULL && cnt < pos-1){ //traversing to the last node
			temp = temp->ptr; 
			cnt++;
		}
		New->ptr = temp->ptr;
		temp->ptr = New;

	}
}


void addAtEnd(Node**first, char *data){
	Node *New = createNode(data);
	if (*first == NULL)
		*first = New;
	else{
		Node *temp = *first;
		while (temp->ptr != NULL) //traversing to the last node
			temp = temp->ptr; 
		temp->ptr = New;
	}
}
void addAtBeg(Node**first, char* data){
	Node *New = createNode(data);
	if (*first == NULL)
		*first = New;
	else{
		New->ptr = *first;
		*first = New;
	}
}

void disp(Node *temp){
	printf("List: \n");
	while(temp != NULL){
		printf("Id: %d\tName:%s\tSalary: %.2lf\n", temp->id,temp->name, temp->salary);
		temp = temp->ptr;
	}
	printf("\n---------------------------------\n");
}

Node* createNode(char *myData){
	Node *ptr = malloc(sizeof(struct Employee));
	if (ptr != NULL){
		sscanf(myData, "%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
	}
	return ptr;
}


