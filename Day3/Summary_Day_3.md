## Code 1 : use of recursion to calculate powers and illustrates basic input-output operations in C 
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ROW
#define ROW 5
#endif

#ifndef COL
#define COL 50
#endif

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr;
};

typedef struct Employee Node;

Node* first = NULL;

//prototypes here 
Node* createNode();
void disp();
void addAtEnd(char a[ROW][COL], int i);
void deleteAtPosition();

// TODO:
// rewrite all functions,
// so that you take inputs from a string array
// create a linked list from those inputs
// only take positions of those nodes from user
// and then take positions for deletions of those nodes from user.

// also note that deleteAtPosition() should only delete the exact position only!
// if the entered position is greater than count of linked list then it should show error msg.

int main(){
	char str[5][50]={
		"1001,Prabhat Shinde,192834.234", 
		"1002,Elon Musk,52324.234", 
		"1003,Jeff Bezos,5234.23",
		"1004,Larry Ellison,5234.234",
		"1005,Linus Torvalds,5234.2234"
	};
	
	for(int i=0; i<ROW; i++){
		addAtEnd(str, i);
	}

	disp();
	
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();

}


Node* createNode(char arr[ROW][COL], int i){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		char* token;

		token = strtok(arr[i], ",");
		ptr->id = atoi(token);

		token = strtok(NULL, ",");
		strcpy(ptr->name, token);

		token = strtok(NULL, ",");
		ptr->salary = strtod(token, NULL);
	
		ptr->ptr = NULL;

		printf("New Node: ID: %d Name: %s Sal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Id: %d, Name: %s, Salary:%.2lf\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
}

void addAtEnd(char arr[ROW][COL], int i){
	Node* New = createNode(arr, i);
	if(first == NULL){
		first = New;
	}
	else{
		Node* temp = first;
		while(temp->ptr != NULL){
			temp = temp->ptr;
		}
		temp->ptr = New;
	}
}


void deleteAtPosition(){
	if(first == NULL){
		printf("Nothing to delete! Exiting...");
		return;
	}
	int position;
	printf("Enter the position where you want to delete Node:\n");
	scanf("%d", &position);
	if(position == 1){
		Node* temp = first;
		first = first->ptr;
		temp->ptr = NULL;
		free(temp);
		return;
	}
	Node* temp_prev = NULL;
	Node* temp = first;
	int count = 1;
	while(temp->ptr != NULL && count < position){
		temp_prev = temp;
		temp = temp->ptr;
		count++;
	}
	temp_prev->ptr = temp->ptr;
	temp->ptr=NULL;
	free(temp);
}
```
**Output**
```
New Node: ID: 1001 Name: Prabhat Shinde Sal:192834.23
New Node: ID: 1002 Name: Elon Musk Sal:52324.23
New Node: ID: 1003 Name: Jeff Bezos Sal:5234.23
New Node: ID: 1004 Name: Larry Ellison Sal:5234.23
New Node: ID: 1005 Name: Linus Torvalds Sal:5234.22
Id: 1001, Name: Prabhat Shinde, Salary:192834.23
Id: 1002, Name: Elon Musk, Salary:52324.23
Id: 1003, Name: Jeff Bezos, Salary:5234.23
Id: 1004, Name: Larry Ellison, Salary:5234.23
Id: 1005, Name: Linus Torvalds, Salary:5234.22
Enter the position where you want to delete Node:
2
Id: 1001, Name: Prabhat Shinde, Salary:192834.23
Id: 1003, Name: Jeff Bezos, Salary:5234.23
Id: 1004, Name: Larry Ellison, Salary:5234.23
Id: 1005, Name: Linus Torvalds, Salary:5234.22
Enter the position where you want to delete Node:
3
Id: 1001, Name: Prabhat Shinde, Salary:192834.23
Id: 1003, Name: Jeff Bezos, Salary:5234.23
Id: 1005, Name: Linus Torvalds, Salary:5234.22
Enter the position where you want to delete Node:
```

Program demonstrates the implementation of a linked list to manage employee records. 

Explanation of the code:

1. **Structure Definition**: 
   - The structure `Employee` is defined to store information about an employee, including their ID, name, and salary.
   - It also contains a pointer `ptr` to the next node in the linked list.

2. **Global Variables**: 
   - `first`: It is a global pointer initialized to NULL, representing the first node of the linked list.

3. **Function Prototypes**:
   - `createNode`: Creates a new node for the linked list and initializes it with the provided employee data.
   - `disp`: Displays the contents of the linked list.
   - `addAtEnd`: Adds a new node at the end of the linked list.
   - `deleteAtPosition`: Deletes a node from the linked list based on the user-provided position.

4. **Main Function**:
   - An array of strings `str` is defined to store employee data in the format: "ID,Name,Salary".
   - The `addAtEnd` function is called in a loop to create and add nodes to the linked list using data from the `str` array.
   - The `disp` function is called to display the initial contents of the linked list.
   - The `deleteAtPosition` function is called multiple times to delete nodes from the linked list at user-specified positions, followed by displaying the updated linked list after each deletion.

5. **createNode Function**:
   - Dynamically allocates memory for a new node.
   - Parses the input string to extract employee ID, name, and salary using `strtok`.
   - Initializes the node with the extracted data and returns a pointer to it.

6. **disp Function**:
   - Traverses the linked list from the beginning (`first` node) to the end.
   - Prints the ID, name, and salary of each employee.

7. **addAtEnd Function**:
   - Adds a new node containing employee data at the end of the linked list.
   - If the list is empty, the new node becomes the first node.
   - Otherwise, it traverses the list to find the last node and adds the new node after it.

8. **deleteAtPosition Function**:
   - Deletes a node from the specified position in the linked list.
   - If the position is 1 (first node), it updates the `first` pointer.
   - Otherwise, it traverses the list to find the node at the specified position, updates the previous node's pointer, and frees the memory occupied by the deleted node.

Overall, this program demonstrates the creation, display, and deletion of nodes in a linked list representing employee records. It interacts with the user to specify the positions for deletion.
