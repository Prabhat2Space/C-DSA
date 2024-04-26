## Code 1 : Demonstrate singly linked list to manage employee records
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MAX
#define MAX 5
#endif

// This is the type of questions you can expect in data structures lab exam
// reading from a string using sscanf() and strtok(), reading from a file using fscanf()


// for gdb debugging segfaults:
// gcc -g nameoffile.c
// gdb -q a.out

struct Employee {
	int id;
	char name[25];
	double salary;
	struct Employee *ptr;	//Pointer for storing next node
};
typedef struct Employee Node;

Node* createNode(char*);
void addAtBeg(Node**, char*);
void addAtEnd(Node**, char*);
void addAtPos(Node**, char*, int);
void deleteAtPos(Node**, int);
void disp(Node*);

int main(){

	char myData[] = "1001,Vaibhav Rathod,5234.4234:1002,Amitabh Bachchan,5235.523:1003,Sachin Wankhede,5234.235:1004,Rahul Ghorpade,5234.523:1005,Nithin Reddy,523523.42";
	Node* first = NULL;
	char* str = strtok(myData, ":");
	while(str != NULL){
		addAtEnd(&first, str);
		str = strtok(NULL, ":");
	}
	disp(first);
}

void deleteAtPos(Node** first, int pos){
	if(*first == NULL){
		printf("List is empty...Nothing to do\n");
		return;
	}
	Node* temp = *first;
	if(pos == 1){
		*first = (*first)->ptr;
	}
	else{
		int cnt = 1;
		Node* prev = NULL;
		while(temp != NULL && cnt < pos){
			prev = temp;
			temp = temp->ptr;
			cnt++;
		}
		if(temp == NULL){
			printf("%d: No such position\n", pos);
			return;
		}
		prev->ptr = temp->ptr;
	}
	free(temp);
}

void addAtPos(Node** first, char* data, int pos){
	Node* New = createNode(data);
	if(*first == NULL)
		*first = New;
	else{
		int cnt = 1;
		Node* temp = *first;
		while(temp->ptr != NULL && cnt < pos-1){ // traversing to the last node
			temp = temp ->ptr;
			cnt++;
		}
		New->ptr = temp->ptr;
		temp->ptr = New;
	}
}


void addAtEnd(Node** first, char* data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		Node* temp = *first;
		while(temp->ptr != NULL){ // traversing to the last node
			temp = temp->ptr;
		}
		temp->ptr = New;
	}
}

void addAtBeg(Node** first, char* data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		New->ptr = *first;
		*first = New;
	}
}

void disp(Node* temp){
	printf("List:\n");
	while(temp != NULL){
		printf("Id: %d\tName:%s\tSalary: %.2f\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
	printf("\n----------------------------------------\n");
}

Node* createNode(char* myData){
	Node* ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		sscanf(myData, "%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
		
	}
	return ptr;
}
```
**Output**
```
List:
Id: 1001	Name:Vaibhav Rathod	Salary: 5234.42
Id: 1002	Name:Amitabh Bachchan	Salary: 5235.52
Id: 1003	Name:Sachin Wankhede	Salary: 5234.23
Id: 1004	Name:Rahul Ghorpade	Salary: 5234.52
Id: 1005	Name:Nithin Reddy	Salary: 523523.42

----------------------------------------
```
This code creates a linked list of employee records by parsing a string containing employee data. 

Let's go through the code and explain it step by step:

1. **Structure Definition**:
    ```c
    struct Employee {
        int id;
        char name[25];
        double salary;
        struct Employee *ptr;    // Pointer for storing next node
    };
    typedef struct Employee Node;
    ```
    - Defines a structure `Employee` to represent an employee with `id`, `name`, `salary`, and a pointer `ptr` to the next employee.
    - Defines a typedef `Node` for `struct Employee`.

2. **Function Prototypes**:
    ```c
    Node* createNode(char*);
    void addAtBeg(Node**, char*);
    void addAtEnd(Node**, char*);
    void addAtPos(Node**, char*, int);
    void deleteAtPos(Node**, int);
    void disp(Node*);
    ```
    - Declares functions for creating a node, adding nodes at the beginning, end, and at a specified position, deleting a node at a specified position, and displaying the linked list.

3. **Main Function**:
    ```c
    int main() {
        char myData[] = "1001,Vaibhav Rathod,5234.4234:1002,Amitabh Bachchan,5235.523:1003,Sachin Wankhede,5234.235:1004,Rahul Ghorpade,5234.523:1005,Nithin Reddy,523523.42";
        Node* first = NULL;
        char* str = strtok(myData, ":");
        while (str != NULL) {
            addAtEnd(&first, str);
            str = strtok(NULL, ":");
        }
        disp(first);
        return 0;
    }
    ```
    - Creates a string `myData` containing employee records separated by colon `:` as delimiters.
    - Initializes a pointer `first` to `NULL`.
    - Uses `strtok()` to tokenize `myData` using colon `:` as delimiter.
    - Calls `addAtEnd()` to add each employee record to the end of the linked list.
    - Displays the linked list using `disp()`.

4. **Other Functions**:
    - `addAtEnd()`, `addAtBeg()`, `addAtPos()`, `deleteAtPos()`: Functions to add or delete nodes at the end, beginning, or at a specified position in the linked list.
    - `disp()`: Function to display the linked list.
    - `createNode()`: Function to create a new node by parsing a string containing employee data.

5. **Explanation of `createNode()`**:
    ```c
    Node* createNode(char* myData) {
        Node* ptr = malloc(sizeof(struct Employee));
        if (ptr != NULL) {
            sscanf(myData, "%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
            ptr->ptr = NULL;
        }
        return ptr;
    }
    ```
    - Allocates memory for a new node using `malloc()`.
    - Parses the string `myData` to extract employee `id`, `name`, and `salary` using `sscanf()`.
    - Initializes the `ptr` (next pointer) of the node to `NULL`.
    - Returns the pointer to the newly created node.

Overall, this code efficiently parses the string containing employee data, creates a linked list of employee records, and displays the list. However, it's essential to ensure that the input string format matches the expected format for parsing to work correctly.

## Code 2 : Demonstrate singly linked list to manage employee records
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee {
    int id;
    char name[25];
    double salary;
    struct Employee *ptr;
};

typedef struct Employee Node;

Node* createNode(FILE*);
void addAtEnd(Node**, FILE*);
void disp(Node*);

int main() {
    Node* first = NULL;
    FILE* fPtr = fopen("myData.txt", "r");
    if (fPtr != NULL) {
        addAtEnd(&first, fPtr);
        fclose(fPtr);
        disp(first);
    } else {
        printf("Failed to open file.\n");
    }
    return 0;
}

void addAtEnd(Node** first, FILE* fPtr) {
    Node* New = createNode(fPtr);
    if (New != NULL) {
        if (*first == NULL) {
            *first = New;
        } else {
            Node* temp = *first;
            while (temp->ptr != NULL) {
                temp = temp->ptr;
            }
            temp->ptr = New;
        }
    }
}

void disp(Node* temp) {
    if (temp == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List:\n");
        while (temp != NULL) {
            printf("Id: %d\tName: %s\tSalary: %.2lf\n", temp->id, temp->name, temp->salary);
            temp = temp->ptr;
        }
    }
}

Node* createNode(FILE* fPtr) {
    Node* ptr = malloc(sizeof(Node));
    if (ptr != NULL) {
        int ret = fscanf(fPtr, "%d,%[^,],%lf\n", &ptr->id, ptr->name, &ptr->salary);
        if (ret != 3) {
            free(ptr);
            ptr = NULL;
        } else {
            ptr->ptr = NULL;
        }
    }
    return ptr;
}

```
**Output**
```
5555,Somnath,99999.00
4444,Param,78999.00
3333,Veer,97600.00
2222,Mahaveer,99966.00
1111,Paramveer,99866.00

```
This code aims to read employee data from a file named "myData.txt" and store it in a linked list of employee records. 

Let's break down the code before debugging and rewriting it:

Structure Definition:
Defines a structure Employee to represent an employee with id, name, salary, and a pointer ptr to the next employee.

Function Prototypes:
Declares functions for creating a node, adding nodes at the beginning, end, and at a specified position, deleting a node at a specified position, and displaying the linked list.

Main Function:
Opens the file "myData.txt" for reading.
If the file is successfully opened, it reads data from the file using addAtEnd() until the end of the file is reached.
Finally, it displays the linked list using disp().

Other Functions:
addAtEnd(), addAtBeg(), addAtPos(), deleteAtPos(): Functions to add or delete nodes at the end, beginning, or at a specified position in the linked list.
disp(): Function to display the linked list.
createNode(): Function to create a new node by reading employee data from the file.
Explanation of createNode():
Reads data from the file using fscanf() and parses it to extract employee id, name, and salary.
Allocates memory for a new node using malloc().
Initializes the ptr (next pointer) of the node to NULL.
Returns the pointer to the newly created node.

## Code 3 : Demonstrate linked list 
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee {
	int id;
	struct Employee *ptr;	//Pointer for storing 
};
typedef struct Employee Node;

Node* createNode(int);
void addAtBeg(Node**, int);
void addAtEnd(Node**, int);
void addAtPos(Node**, int, int);
void deleteAtPos(Node**, int);
void disp(Node*);

int main(){ // local variable first
	Node* first = NULL;
	Node* second = NULL;
	int i;
	for(i=0; i<10; i++){
		addAtEnd(&first, 100 + i * 10);
		addAtEnd(&second, 200 + i * 10);
	}
	disp(first);
	disp(second);
}

void deleteAtPos(Node** first, int pos){
	if(*first == NULL){
		printf("List is empty...Nothing to do\n");
		return;
	}
	Node* temp = *first;
	if(pos == 1){
		*first = (*first)->ptr;
	}
	else{
		int cnt = 1;
		Node* prev = NULL;
		while(temp != NULL && cnt < pos){
			prev = temp;
			temp = temp->ptr;
			cnt++;
		}
		if(temp == NULL){
			printf("%d: No such position\n", pos);
			return;
		}
		prev->ptr = temp->ptr;
	}
	free(temp);
}

void addAtPos(Node** first, int data, int pos){
	Node* New = createNode(data);
	if(*first == NULL)
		*first = New;
	else{
		int cnt = 1;
		Node* temp = *first;
		while(temp->ptr != NULL && cnt < pos-1){ // traversing to the last node
			temp = temp ->ptr;
			cnt++;
		}
		New->ptr = temp->ptr;
		temp->ptr = New;
	}
}


void addAtEnd(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		Node* temp = *first;
		while(temp->ptr != NULL){ // traversing to the last node
			temp = temp->ptr;
		}
		temp->ptr = New;
	}
}

void addAtBeg(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		New->ptr = *first;
		*first = New;
	}
}

void disp(Node* temp){
	printf("List: ");
	while(temp != NULL){
		printf("%d ", temp->id);
		temp = temp->ptr;
	}
	printf("\n----------------------------------------\n");
}

Node* createNode(int data){
	Node* ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		ptr->id = data;
		ptr->ptr = NULL;
	}
	return ptr;
}
```
**Output**
```
List: 100 110 120 130 140 150 160 170 180 190 
----------------------------------------
List: 200 210 220 230 240 250 260 270 280 290 
----------------------------------------

```
This code implements a linked list of `Employee` nodes and performs various operations on them, such as adding nodes at the beginning, end, or at a specified position, deleting nodes at a specified position, and displaying the linked list.

Let's break down the code:

1. **Structure Definition**:
   - Defines a structure `Employee` to represent an employee with an `id` and a pointer `ptr` to the next employee.

2. **Function Prototypes**:
   - Declares functions for creating a node, adding nodes at the beginning, end, or at a specified position, deleting a node at a specified position, and displaying the linked list.

3. **Main Function**:
   - Creates two linked lists (`first` and `second`) by adding nodes to them in a loop.
   - Displays both linked lists using the `disp()` function.

4. **Other Functions**:
   - `deleteAtPos()`: Deletes a node at a specified position in the linked list.
   - `addAtPos()`: Adds a node with given data at a specified position in the linked list.
   - `addAtEnd()`, `addAtBeg()`: Add nodes at the end and beginning of the linked list, respectively.
   - `disp()`: Displays the elements of the linked list.
   - `createNode()`: Creates a new node with the given data.

Overall, this code demonstrates basic linked list operations with `Employee` nodes.

Now, let's go through the execution flow:

1. In the `main()` function, two linked lists (`first` and `second`) are created.
2. Nodes are added to both linked lists in a loop, with data values ranging from 100 to 190 for the first list (`first`) and from 200 to 290 for the second list (`second`).
3. After adding nodes, both linked lists are displayed using the `disp()` function, showing the elements in each list.

This code illustrates how to manipulate linked lists and perform operations such as insertion, deletion, and display.

## Code 4 : Demonstrate doubly linked list.
```c
#include<stdio.h>
#include<stdlib.h>

typedef struct Test{
	int data;
	struct Test *prev, *next;
} Node;

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
	for(i=0; i<10; i+=2){
		addAtBeg(100+i);
		addAtEnd(200+i+1);
	}
	disp();
}

Node* createNode(int num){
	Node* New = malloc(sizeof(Node));
	if(New!=NULL){
		New->data = num;
		New->prev = New->next = NULL;
	}
	return New;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
	}
	else{
		first->prev = New;
		New->next = first;
		first = New;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
	}
	else{
		New->prev = last;
		last->next = New;
		last = New;
	}
}

void disp(){
	printf("Forward: ");
	printForward();
	printf("Reverse: ");
	printReverse();
	printf("\n-------------------------------\n");
}

void printForward(){
	Node* temp = first;
	while(temp!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printReverse(){
	Node* temp = last;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
```
**Output**
```
Forward: 108 106 104 102 100 201 203 205 207 209 
Reverse: 209 207 205 203 201 100 102 104 106 108 

-------------------------------
```
This code implements a doubly linked list with the `Test` structure to hold integer data. The program creates a doubly linked list, adds nodes at the beginning and end, and then prints the list both forward and in reverse.

Here's an overview of the code:

1. **Structure Definition**:
   - Defines a structure `Test` to represent a node in the doubly linked list. Each node contains an integer `data`, and two pointers `prev` and `next` to the previous and next nodes, respectively.

2. **Global Variables**:
   - Declares global variables `first` and `last` to keep track of the first and last nodes in the linked list.

3. **Function Prototypes**:
   - Declares functions for creating a new node, adding nodes at the beginning and end of the linked list, and displaying the linked list both forward and in reverse.

4. **Main Function**:
   - Initializes the global variables `first` and `last` to `NULL`.
   - Adds nodes to the doubly linked list by calling `addAtBeg()` and `addAtEnd()` functions in a loop.
   - Calls the `disp()` function to display the linked list.

5. **Other Functions**:
   - `createNode()`: Dynamically allocates memory for a new node, initializes its `data` field, and sets its `prev` and `next` pointers to `NULL`.
   - `addAtBeg()`: Adds a new node with the given data at the beginning of the linked list.
   - `addAtEnd()`: Adds a new node with the given data at the end of the linked list.
   - `disp()`: Displays the linked list by calling `printForward()` to print it in forward order and `printReverse()` to print it in reverse order.
   - `printForward()`: Prints the linked list in forward order by traversing it from the first node to the last node.
   - `printReverse()`: Prints the linked list in reverse order by traversing it from the last node to the first node.

Overall, this code demonstrates the implementation of a doubly linked list and its basic operations such as insertion and printing in both forward and reverse orders.


## Code 5 : Demonstrate doubly linked list delete a node with a specific data value.
```c
#include<stdio.h>
#include<stdlib.h>

typedef struct Test{
	int data;
	struct Test *prev, *next;
} Node;

Node *first, *last;

Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();
void deleteAtData(int);

int main(){
	first = last = NULL;
	int i;
	for(i=0; i<10; i+=2){
		addAtBeg(100+i);
		addAtEnd(200+i+1);
	}
	disp();

	deleteAtData(100);
	printf("After deleting 100\n");
	disp();
	deleteAtData(108);
	printf("After deleting 108\n");
	disp();
	deleteAtData(209);
	printf("After deleting 209\n");
	disp();
	deleteAtData(1000);
	printf("After deleting 1000\n");
	disp();
}

Node* createNode(int num){
	Node* New = malloc(sizeof(Node));
	if(New!=NULL){
		New->data = num;
		New->prev = New->next = NULL;
	}
	return New;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
	}
	else{
		first->prev = New;
		New->next = first;
		first = New;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
	}
	else{
		New->prev = last;
		last->next = New;
		last = New;
	}
}

void disp(){
	printf("Forward: ");
	printForward();
	printf("Reverse: ");
	printReverse();
	printf("\n-------------------------------\n");
}

void printForward(){
	Node* temp = first;
	while(temp!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printReverse(){
	Node* temp = last;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void deleteAtData(int data){
	if(first == NULL){
		printf("Nothing to delete! Returning...\n");
		return;
	}
	Node* temp = first;
	Node* temp_prev = NULL;
	while(temp != NULL && temp->data != data){
		temp_prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		printf("That data does not exist! Returning...\n");
		return;
	}
	else if(temp_prev == NULL){
		temp->next->prev = NULL;
		first = temp->next;
		temp->next = NULL;
	}
	else if(temp->next == NULL){
		temp_prev->next = NULL;
		temp->next = NULL;
		temp->prev = NULL;
		last = temp_prev;
	}
	else{
		temp->next->prev = temp_prev;
		temp_prev->next = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	free(temp);
}
```
**Output**
```
Forward: 108 106 104 102 100 201 203 205 207 209 
Reverse: 209 207 205 203 201 100 102 104 106 108 

-------------------------------
After deleting 100
Forward: 108 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 108 

-------------------------------
After deleting 108
Forward: 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 

-------------------------------
After deleting 209
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------
That data does not exist! Returning...
After deleting 1000
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------

```
This code implements a doubly linked list with the `Test` structure to hold integer data. It also includes a function `deleteAtData` to delete a node with a specific data value.

Here's an overview of the code:

1. **Structure Definition**:
   - Defines a structure `Test` to represent a node in the doubly linked list. Each node contains an integer `data`, and two pointers `prev` and `next` to the previous and next nodes, respectively.

2. **Global Variables**:
   - Declares global variables `first` and `last` to keep track of the first and last nodes in the linked list.

3. **Function Prototypes**:
   - Declares functions for creating a new node, adding nodes at the beginning and end of the linked list, displaying the linked list both forward and in reverse, and deleting a node with a specific data value.

4. **Main Function**:
   - Initializes the global variables `first` and `last` to `NULL`.
   - Adds nodes to the doubly linked list by calling `addAtBeg()` and `addAtEnd()` functions in a loop.
   - Displays the linked list before and after deletion by calling the `disp()` function.

5. **Other Functions**:
   - `createNode()`: Dynamically allocates memory for a new node, initializes its `data` field, and sets its `prev` and `next` pointers to `NULL`.
   - `addAtBeg()`: Adds a new node with the given data at the beginning of the linked list.
   - `addAtEnd()`: Adds a new node with the given data at the end of the linked list.
   - `disp()`: Displays the linked list by calling `printForward()` to print it in forward order and `printReverse()` to print it in reverse order.
   - `printForward()`: Prints the linked list in forward order by traversing it from the first node to the last node.
   - `printReverse()`: Prints the linked list in reverse order by traversing it from the last node to the first node.
   - `deleteAtData()`: Deletes the node with the specified data value from the linked list. If the node is found, it adjusts the pointers accordingly to maintain the integrity of the linked list structure and frees the memory allocated for the deleted node.

Overall, this code demonstrates the implementation of a doubly linked list with the ability to delete nodes based on their data value.

## Code 6 : Demonstrate doubly linked list delete a node with a specific data value.
```c
#include<stdio.h>
#include<stdlib.h>

typedef struct Test{
	int data;
	struct Test *prev, *next;
} Node;

Node *first, *last;

Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();
void deleteAtData(int);

int main(){
	first = last = NULL;
	int i;
	for(i=0; i<10; i+=2){
		addAtBeg(100+i);
		addAtEnd(200+i+1);
	}
	disp();
///*
	deleteAtData(100);
	printf("After deleting 100\n");
	disp();
	deleteAtData(108);
	printf("After deleting 108\n");
	disp();
	deleteAtData(209);
	printf("After deleting 209\n");
	disp();
	deleteAtData(1000);
	printf("After deleting 1000\n");
	disp();

//*/
}

Node* createNode(int num){
	Node* New = malloc(sizeof(Node));
	if(New!=NULL){
		New->data = num;
		New->prev = New->next = NULL;
	}
	return New;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		first->prev = New;
		New->next = first;
		first = New;
		first->prev = last;
		last->next = first;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		New->prev = last;
		last->next = New;
		last = New;
		first->prev = last;
		last->next = first;
	}
}

void disp(){
	printf("Forward: ");
	printForward();
	printf("Reverse: ");
	printReverse();
	printf("\n-------------------------------\n");
}

void printForward(){
	Node* temp = first;
	printf("%d ", temp->data);
	temp= temp->next;
	while(temp!= first){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printReverse(){
	Node* temp = last;
	printf("%d ", temp->data);
	temp = temp->prev;
	while(temp != last){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void deleteAtData(int data){
	if(first == NULL){
		printf("Nothing to delete! Returning...\n");
		return;
	}
	Node* temp = first->next;
	Node* temp_prev = first;

	while(temp != first && temp->data != data){
		temp_prev = temp;
		temp = temp->next;
	}
	if(temp == first && temp->data != data){
		printf("That data does not exist! Returning...\n");
		return;
	}
	else if(temp == first){
		temp->next->prev = last;
		last->next = temp->next;
		first = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else if(temp == last){
		temp_prev->next = first;
		first->prev = temp_prev;
		last = temp_prev;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else{
		temp->next->prev = temp_prev;
		temp_prev->next = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	free(temp);
}
```
**Output**
```
Forward: 108 106 104 102 100 201 203 205 207 209 
Reverse: 209 207 205 203 201 100 102 104 106 108 

-------------------------------
After deleting 100
Forward: 108 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 108 

-------------------------------
After deleting 108
Forward: 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 

-------------------------------
After deleting 209
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------
That data does not exist! Returning...
After deleting 1000
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------

```
This code implements a circular doubly linked list with the `Test` structure to hold integer data. It also includes a function `deleteAtData` to delete a node with a specific data value.

Here's an explanation of the code:

1. **Structure Definition**:
   - Defines a structure `Test` to represent a node in the circular doubly linked list. Each node contains an integer `data`, and two pointers `prev` and `next` to the previous and next nodes, respectively.

2. **Global Variables**:
   - Declares global variables `first` and `last` to keep track of the first and last nodes in the linked list.

3. **Function Prototypes**:
   - Declares functions for creating a new node, adding nodes at the beginning and end of the circular doubly linked list, displaying the linked list both forward and in reverse, and deleting a node with a specific data value.

4. **Main Function**:
   - Initializes the global variables `first` and `last` to `NULL`.
   - Adds nodes to the circular doubly linked list by calling `addAtBeg()` and `addAtEnd()` functions in a loop.
   - Displays the linked list before and after deletion by calling the `disp()` function.

5. **Other Functions**:
   - `createNode()`: Dynamically allocates memory for a new node, initializes its `data` field, and sets its `prev` and `next` pointers to `NULL`.
   - `addAtBeg()`: Adds a new node with the given data at the beginning of the circular doubly linked list.
   - `addAtEnd()`: Adds a new node with the given data at the end of the circular doubly linked list.
   - `disp()`: Displays the circular doubly linked list by calling `printForward()` to print it in forward order and `printReverse()` to print it in reverse order.
   - `printForward()`: Prints the circular doubly linked list in forward order by traversing it from the first node to the last node.
   - `printReverse()`: Prints the circular doubly linked list in reverse order by traversing it from the last node to the first node.
   - `deleteAtData()`: Deletes the node with the specified data value from the circular doubly linked list. If the node is found, it adjusts the pointers accordingly to maintain the integrity of the circular doubly linked list structure and frees the memory allocated for the deleted node.

Overall, this code demonstrates the implementation of a circular doubly linked list with the ability to delete nodes based on their data value.

## Code 7 : Demonstrate circular doubly linked list.
```c

#include<stdio.h>
#include<stdlib.h>

// TODO
// FLAMES game just like josepheus problem, using circular linked list


typedef struct Test{
	int data;
	struct Test *prev, *next;
} Node;

Node *first, *last;

Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();
void deleteAtData(int);

int main(){
	first = last = NULL;
	int i;
	for(i=0; i<10; i+=2){
		addAtBeg(100+i);
		addAtEnd(200+i+1);
	}
	disp();
///*
	deleteAtData(100);
	printf("After deleting 100\n");
	disp();
	deleteAtData(108);
	printf("After deleting 108\n");
	disp();
	deleteAtData(209);
	printf("After deleting 209\n");
	disp();
	deleteAtData(1000);
	printf("After deleting 1000\n");
	disp();

//*/
}

Node* createNode(int num){
	Node* New = malloc(sizeof(Node));
	if(New!=NULL){
		New->data = num;
		New->prev = New->next = NULL;
	}
	return New;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		first->prev = New;
		New->next = first;
		first = New;
		first->prev = last;
		last->next = first;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		New->prev = last;
		last->next = New;
		last = New;
		first->prev = last;
		last->next = first;
	}
}

void disp(){
	printf("Forward: ");
	printForward();
	printf("Reverse: ");
	printReverse();
	printf("\n-------------------------------\n");
}

void printForward(){
	Node* temp = first;
	printf("%d ", temp->data);
	temp= temp->next;
	while(temp!= first){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printReverse(){
	Node* temp = last;
	printf("%d ", temp->data);
	temp = temp->prev;
	while(temp != last){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void deleteAtData(int data){
	if(first == NULL){
		printf("Nothing to delete! Returning...\n");
		return;
	}
	Node* temp = first->next;
	Node* temp_prev = first;

	while(temp != first && temp->data != data){
		temp_prev = temp;
		temp = temp->next;
	}
	if(temp == first && temp->data != data){
		printf("That data does not exist! Returning...\n");
		return;
	}
	else if(temp == first){
		temp->next->prev = last;
		last->next = temp->next;
		first = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else if(temp == last){
		temp_prev->next = first;
		first->prev = temp_prev;
		last = temp_prev;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else{
		temp->next->prev = temp_prev;
		temp_prev->next = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	free(temp);
}
```
**Output**
```
Forward: 108 106 104 102 100 201 203 205 207 209 
Reverse: 209 207 205 203 201 100 102 104 106 108 

-------------------------------
After deleting 100
Forward: 108 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 108 

-------------------------------
After deleting 108
Forward: 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 

-------------------------------
After deleting 209
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------
That data does not exist! Returning...
After deleting 1000
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------

```
The provided code implements a circular doubly linked list along with functions to add nodes at the beginning and end, display the list in forward and reverse order, and delete a node with a specified data value.

Here's a breakdown of the code:

1. **Structure Definition**:
   - Defines a structure `Test` to represent a node in the circular doubly linked list. Each node contains an integer `data`, and two pointers `prev` and `next` to the previous and next nodes, respectively.

2. **Global Variables**:
   - Declares global variables `first` and `last` to keep track of the first and last nodes in the linked list.

3. **Function Prototypes**:
   - Declares functions for creating a new node, adding nodes at the beginning and end of the circular doubly linked list, displaying the linked list both forward and in reverse, and deleting a node with a specific data value.

4. **Main Function**:
   - Initializes the global variables `first` and `last` to `NULL`.
   - Adds nodes to the circular doubly linked list by calling `addAtBeg()` and `addAtEnd()` functions in a loop.
   - Displays the linked list before and after deletion by calling the `disp()` function.

5. **Other Functions**:
   - `createNode()`: Dynamically allocates memory for a new node, initializes its `data` field, and sets its `prev` and `next` pointers to `NULL`.
   - `addAtBeg()`: Adds a new node with the given data at the beginning of the circular doubly linked list.
   - `addAtEnd()`: Adds a new node with the given data at the end of the circular doubly linked list.
   - `disp()`: Displays the circular doubly linked list by calling `printForward()` to print it in forward order and `printReverse()` to print it in reverse order.
   - `printForward()`: Prints the circular doubly linked list in forward order by traversing it from the first node to the last node.
   - `printReverse()`: Prints the circular doubly linked list in reverse order by traversing it from the last node to the first node.
   - `deleteAtData()`: Deletes the node with the specified data value from the circular doubly linked list. If the node is found, it adjusts the pointers accordingly to maintain the integrity of the circular doubly linked list structure and frees the memory allocated for the deleted node.

Overall, this code provides a basic implementation of a circular doubly linked list with functionalities to manipulate the list.

## Code 8 : Demonstrate FLAMES game using a circular doubly linked list.
```c
#include<stdio.h>
#include<stdlib.h>

typedef struct Test{
	int data;
	struct Test *prev, *next;
} Node;

Node *first, *last;

// TODO:
// Write code for FLAMES game 
// which functions just like Josepheus problem,
// using circular linked list

Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();
void deleteAtData(int);

int main(){
	first = last = NULL;
	int i;
	for(i=0; i<10; i+=2){
		addAtBeg(100+i);
		addAtEnd(200+i+1);
	}
	disp();
///*
	deleteAtData(100);
	printf("After deleting 100\n");
	disp();
	deleteAtData(108);
	printf("After deleting 108\n");
	disp();
	deleteAtData(209);
	printf("After deleting 209\n");
	disp();
	deleteAtData(1000);
	printf("After deleting 1000\n");
	disp();

//*/
}

Node* createNode(int num){
	Node* New = malloc(sizeof(Node));
	if(New!=NULL){
		New->data = num;
		New->prev = New->next = NULL;
	}
	return New;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		first->prev = New;
		New->next = first;
		first = New;
		first->prev = last;
		last->next = first;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		New->prev = last;
		last->next = New;
		last = New;
		first->prev = last;
		last->next = first;
	}
}

void disp(){
	printf("Forward: ");
	printForward();
	printf("Reverse: ");
	printReverse();
	printf("\n-------------------------------\n");
}

void printForward(){
	Node* temp = first;
	printf("%d ", temp->data);
	temp= temp->next;
	while(temp!= first){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printReverse(){
	Node* temp = last;
	printf("%d ", temp->data);
	temp = temp->prev;
	while(temp != last){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void deleteAtData(int data){
	if(first == NULL){
		printf("Nothing to delete! Returning...\n");
		return;
	}
	Node* temp = first->next;
	Node* temp_prev = first;

	while(temp != first && temp->data != data){
		temp_prev = temp;
		temp = temp->next;
	}
	if(temp == first && temp->data != data){
		printf("That data does not exist! Returning...\n");
		return;
	}
	else if(temp == first){
		temp->next->prev = last;
		last->next = temp->next;
		first = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else if(temp == last){
		temp_prev->next = first;
		first->prev = temp_prev;
		last = temp_prev;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else{
		temp->next->prev = temp_prev;
		temp_prev->next = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	free(temp);
}
```
**Output**
```

Forward: 108 106 104 102 100 201 203 205 207 209 
Reverse: 209 207 205 203 201 100 102 104 106 108 

-------------------------------
After deleting 100
Forward: 108 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 108 

-------------------------------
After deleting 108
Forward: 106 104 102 201 203 205 207 209 
Reverse: 209 207 205 203 201 102 104 106 

-------------------------------
After deleting 209
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------
That data does not exist! Returning...
After deleting 1000
Forward: 106 104 102 201 203 205 207 
Reverse: 207 205 203 201 102 104 106 

-------------------------------

```
The provided code is a basic framework for implementing the FLAMES game using a circular doubly linked list. However, the code currently implements functions for creating a circular doubly linked list, adding nodes at the beginning and end, displaying the list in forward and reverse order, and deleting a node with a specific data value. It does not include the implementation of the FLAMES game itself.

Here's an overview of the existing code:

1. **Structure Definition**:
   - Defines a structure `Test` to represent a node in the circular doubly linked list. Each node contains an integer `data`, and two pointers `prev` and `next` to the previous and next nodes, respectively.

2. **Global Variables**:
   - Declares global variables `first` and `last` to keep track of the first and last nodes in the linked list.

3. **Function Prototypes**:
   - Declares functions for creating a new node, adding nodes at the beginning and end of the circular doubly linked list, displaying the linked list both forward and in reverse, and deleting a node with a specific data value.

4. **Main Function**:
   - Initializes the global variables `first` and `last` to `NULL`.
   - Adds nodes to the circular doubly linked list by calling `addAtBeg()` and `addAtEnd()` functions in a loop.
   - Displays the linked list before and after deletion by calling the `disp()` function.

5. **Other Functions**:
   - `createNode()`: Dynamically allocates memory for a new node, initializes its `data` field, and sets its `prev` and `next` pointers to `NULL`.
   - `addAtBeg()`: Adds a new node with the given data at the beginning of the circular doubly linked list.
   - `addAtEnd()`: Adds a new node with the given data at the end of the circular doubly linked list.
   - `disp()`: Displays the circular doubly linked list by calling `printForward()` to print it in forward order and `printReverse()` to print it in reverse order.
   - `printForward()`: Prints the circular doubly linked list in forward order by traversing it from the first node to the last node.
   - `printReverse()`: Prints the circular doubly linked list in reverse order by traversing it from the last node to the first node.
   - `deleteAtData()`: Deletes the node with the specified data value from the circular doubly linked list. If the node is found, it adjusts the pointers accordingly to maintain the integrity of the circular doubly linked list structure and frees the memory allocated for the deleted node.

To implement the FLAMES game using this circular doubly linked list, you would need to write additional functions to handle the game logic. These functions would manipulate the list based on the rules of the FLAMES game. For example, you would need functions to find the length of the list, locate the node to be removed based on the game rules, and update the list accordingly.
