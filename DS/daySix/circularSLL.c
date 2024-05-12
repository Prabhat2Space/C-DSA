
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
	int id;
	struct Employee *ptr; //Pointer for storing address
};
typedef struct Employee Node;

Node* createNode();
void addAtBeg();
void addAtEnd();
void disp();

Node *first = NULL;

int main(){
	int i;
	for(i=0;i<10;i+=2){
		addAtBeg(100+i);
		addAtEnd(100+i+1);
	}
	disp();
}

void addAtEnd(int num){
	Node *New = createNode(num);
	if (first == NULL){
		first = New;
		New->ptr = first;
	}else{
		Node *temp = first;
		while (temp->ptr != first) //traversing to the last node
			temp = temp->ptr; 
		temp->ptr = New;
	}
	New->ptr = first;
}
void addAtBeg(int num){
	Node *New = createNode(num);
	if (first == NULL){
		first = New;
		New->ptr = first;
	}else{
		New->ptr = first;
		Node *temp = first;
		while (temp->ptr != first) //traversing to the last node
			temp = temp->ptr; 
		first = New;
		temp->ptr = first;
	}
}


void disp(){
	Node *temp = first;
	printf("List : ");
	if (temp){
		while(temp->ptr != first){
			printf("%d ", temp->id);
			temp = temp->ptr;
		}
		printf("%d ",temp->id);
	}else{
		printf("Empty");
	}
	printf("\n");
}


Node* createNode(int num){
	Node *ptr = malloc(sizeof(struct Employee));
	if (ptr != NULL){
		ptr->id = num;
		ptr->ptr = NULL;
	}
	return ptr;
}


