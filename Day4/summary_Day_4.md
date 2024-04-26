## Code 1 : Demonstrate  implementation of a singly linked list to manage employee records
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee {
	int id;
	struct Employee *next;	// Pointer for storing next address.
};

typedef struct Employee Node;

Node* createNode(int);
void addAtBeg(Node**, int);
void addAtEnd(Node**, int);
void addAtPos(Node**, int, int);
void deleteAtPos(Node**, int);
void disp(Node*);

// This modified code was written by instructor,
// screenshots were posted on group chat
// This code is very similar to previous ones,
// except this one eliminates all global variables.


int main() {

	// Head of linked list:
	Node *first = NULL;
	// Notice how we are passing head of linked list to every function,
	// this helps eliminate a global variable which was head of LL.
	// It also helps us use the same functions for multiple different linked lists
	// with different head pointers.
	//
	// Apart from that we are also passing Node data in parameters.
	//
	// If you notice, we are passing address of head pointer
	// this is because all function arguments are pass by value in C/C++
	// therefore in order to change that exact head pointer,
	// we have to pass a pointer to that pointer.
	
	addAtBeg(&first, 1001);
	addAtEnd(&first, 1002);
	addAtEnd(&first, 1003);
	disp(first);
	// Here we are also passing position as parameter:
	addAtPos(&first, 1004, 2);
	addAtPos(&first, 1005, 3);
	addAtPos(&first, 1010, 5);
	disp(first);
	deleteAtPos(&first, 10);
	disp(first);
	deleteAtPos(&first, 4);
	disp(first);
}

Node* createNode(int data){
	Node* ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		ptr->id = data;
		ptr->next = NULL;
	}
	return ptr;
}

void addAtBeg(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		New->next = *first;
		*first = New;
	}
}

void addAtEnd(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		Node* temp = *first;
  		// traversing to the last node
		while(temp->next != NULL){
			temp = temp->next;

		}
		temp->next = New;
	}
}

void addAtPos(Node** first, int data, int pos){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		int cnt = 1;
		Node* temp = *first;
		while(temp->next != NULL && cnt < pos-1){
			temp = temp->next;
			cnt++;
		}
		New->next = temp->next;
		temp->next = New;
	}
}

void deleteAtPos(Node** first, int pos){
	if(*first == NULL){
		printf("List is empty... Nothing to do\n");
		return;
	}
	Node* temp = *first;
	if(pos == 1){
		*first = (*first)->next;
	}
	else{
		int cnt = 1;
		Node* prev = NULL;
		while(temp!=NULL && cnt < pos){
			prev = temp;
			temp = temp->next;
			cnt++;
		}
		if(temp == NULL){
			printf("%d: No such position\n", pos);
			return;
		}
		prev->next = temp->next;
	}
	free(temp);
}

void disp(Node* temp){
	while(temp != NULL){
		printf("Id: %d\n", temp->id);
		temp = temp->next;
	}
	printf("------------------------------------------\n");
}

```
**Output**
```

Id: 1001
Id: 1002
Id: 1003
------------------------------------------
Id: 1001
Id: 1004
Id: 1005
Id: 1002
Id: 1010
Id: 1003
------------------------------------------
10: No such position
Id: 1001
Id: 1004
Id: 1005
Id: 1002
Id: 1010
Id: 1003
------------------------------------------
Id: 1001
Id: 1004
Id: 1005
Id: 1010
Id: 1003
------------------------------------------
```
This C program demonstrates the implementation of a singly linked list to manage employee records. Here's a breakdown of its components and functionality:

1. **Struct Definition**:
   - The code defines a structure named `Employee`, which contains an integer field `id` for the employee ID and a pointer `next` to the next node in the linked list.

2. **Using Typedef**:
   - The `typedef` statement is used to create an alias `Node` for the structure `Employee`.

3. **Function Prototypes**:
   - Function prototypes are declared for various operations such as creating a node, adding a node at the beginning, end, or a specified position of the linked list, deleting a node at a specified position, and displaying the linked list.

4. **Main Function**:
   - The `main` function initializes the head pointer `first` of the linked list to NULL.
   - It then demonstrates various operations on the linked list:
     - Adds nodes at the beginning, end, and specified positions.
     - Deletes nodes at specified positions.
     - Displays the contents of the linked list after each operation.

5. **Function `createNode`**:
   - This function dynamically allocates memory for a new node, initializes its `id` field with the provided data, sets its `next` pointer to NULL, and returns a pointer to the new node.

6. **Function `addAtBeg`**:
   - This function adds a new node with the provided data at the beginning of the linked list.
   - It updates the head pointer `first` to point to the newly added node.

7. **Function `addAtEnd`**:
   - This function adds a new node with the provided data at the end of the linked list.
   - It traverses the linked list to find the last node and updates its `next` pointer to point to the newly added node.

8. **Function `addAtPos`**:
   - This function adds a new node with the provided data at the specified position in the linked list.
   - It traverses the linked list to find the node at the specified position and updates the pointers to include the new node.

9. **Function `deleteAtPos`**:
   - This function deletes the node at the specified position in the linked list.
   - It traverses the linked list to find the node at the specified position, updates the pointers to skip over the node to be deleted, and frees the memory allocated for that node.

10. **Function `disp`**:
    - This function traverses the linked list from the head node and prints the `id` field of each node.
    - It helps in visualizing the contents of the linked list after each operation.

Overall, this program provides a comprehensive demonstration of creating, manipulating, and displaying a singly linked list of employee records in C. It also showcases the use of pointers to pointers to manage the head pointer of the linked list efficiently.
