#include <stdio.h>
#include <stdlib.h>

typedef struct Test{
	int data;
	struct Test *prev, *next;
}Node;

Node *first, *last;

Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();

int main(){
	first = last = NULL;
	int i;
	for(i = 0; i< 10; i+=2){
		addAtBeg(100 +i);
		addAtEnd(200 +i+1);
	}
	disp();
}

Node *createNode(int num){
	Node *New = malloc(sizeof(Node));
	if(New!=NULL){
		New->data = num;
		New->prev = New->next = NULL;
	}
	return New;
}
void addAtBeg(int num){
	Node *New = createNode(num);
	if (first == NULL)
		first = last = New;
	else{
		first->prev = New;
		New->next = first;
		first = New;
	}
	last->next = first;
	first->prev = last;
}

void addAtEnd(int num){
	Node *New = createNode(num);
	if (first == NULL)
		first = last = New;
	else{
		New->prev = last;
		last->next = New;
		last = New;
	}
	last->next = first;
	first->prev = last;
}

void disp(){
	printf("Forward : ");
	printForward();
	printf("Reverse: ");
	printReverse();
	printf("\n------------------------------\n");
}
void printForward(){
	Node *temp = first;
	if (temp != NULL){
		printf("%d  ", temp->data);
		while (temp->next!= first){
			printf("%d  ", temp->data);
			temp = temp->next;
		}
   	}else{
		printf("Empty List");
	}
	printf("\n");
}
void printReverse(){
	Node *temp = last;
	if (temp !=NULL){
		printf("%d  ", temp->data);
		while (temp->prev!= last){
			printf("%d  ", temp->data);
			temp = temp->prev;
		}
	}else {
		printf("Empty list");
	}
	printf("\n");

}
