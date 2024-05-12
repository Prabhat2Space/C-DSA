#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
	int id;
	struct Employee *ptr; //Pointer for storing address
};
typedef struct Employee Node;

Node* createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void addAtPos(int,int);
void deleteAtPos(int);
void disp();

Node *first = NULL;

int main(){
	addAtBeg(1001);	
	addAtEnd(1002);	
	addAtEnd(1003);	
	disp();
	addAtPos(1004, 2);	
	addAtPos(1005, 3);	
	addAtPos(1010, 5);	
	disp();
	deleteAtPos(10);
	disp();
	deleteAtPos(4);
	disp();
}

void deleteAtPos(int pos){
	
	if (first == NULL){
		printf("List is empty...Nothing to do\n");
		return;	
	}
	Node *temp = first;
	if (pos == 1){
		first = first->ptr;
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

void addAtPos(int data, int pos){
	Node *New = createNode(data);
	if (first == NULL)
		first = New;
	else{
		int cnt = 1;	
		Node *temp = first;
		while (temp->ptr != NULL && cnt < pos-1){ //traversing to the last node
			temp = temp->ptr; 
			cnt++;
		}
		New->ptr = temp->ptr;
		temp->ptr = New;

	}
}


void addAtEnd(int data){
	Node *New = createNode(data);
	if (first == NULL)
		first = New;
	else{
		Node *temp = first;
		while (temp->ptr != NULL) //traversing to the last node
			temp = temp->ptr; 
		temp->ptr = New;
	}
}
void addAtBeg(int data){
	Node *New = createNode(data);
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
		printf("Id: %d\n", temp->id);
		temp = temp->ptr;
	}
	printf("---------------------------------\n");
}



Node* createNode(int data){
	Node *ptr = malloc(sizeof(struct Employee));
	if (ptr != NULL){
		ptr->id = data;
		ptr->ptr = NULL;
	}
	return ptr;
}


