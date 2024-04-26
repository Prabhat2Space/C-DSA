## Code 1 : Demonstrate implementation of a linked list to manage employee records
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


## Code 2 : Demonstrate implementation of a linked list to manage employee records

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 5
#define COL 50

struct Employee {
    int id;
    char name[25];
    double salary;
    struct Employee *ptr;
};

typedef struct Employee Node;

Node* first = NULL;

// Prototypes
char* extractRecordFromString(char arr[], int i);
Node* createNode(char arr[]);
void disp();
void addAtEnd(char arr[]);
void deleteAtPosition();

int main() {
    char str[] = {
        "1001,Prabhat Shinde,192834.234:"
        "1002,Elon Musk,172324.234:"
        "1003,Jeff Bezos,12234.23:"
        "1004,Larry Ellison,14234.234:"
        "1005,Linus Torvalds,15234.2234"
    };

    char temp[50];
    for (int i = 0; i < ROW; i++) {
        strcpy(temp, extractRecordFromString(str, i));
        addAtEnd(temp);
    }

    disp();

    deleteAtPosition();
    disp();
    deleteAtPosition();
    disp();
    deleteAtPosition();
    disp();

    return 0;
}

char* extractRecordFromString(char str[], int i) {
    char* token = strtok(str, ":");
    while (i > 0) {
        token = strtok(NULL, ":");
        i--;
    }
    return token;
}

Node* createNode(char arr[]) {
    Node* ptr = malloc(sizeof(struct Employee));
    if (ptr != NULL) {
        char* token;

        token = strtok(arr, ",");
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

void disp() {
    Node* temp = first;
    while (temp != NULL) {
        printf("Id: %d, Name: %s, Salary:%.2lf\n", temp->id, temp->name, temp->salary);
        temp = temp->ptr;
    }
}

void addAtEnd(char arr[]) {
    Node* New = createNode(arr);
    if (first == NULL) {
        first = New;
    } else {
        Node* temp = first;
        while (temp->ptr != NULL) {
            temp = temp->ptr;
        }
        temp->ptr = New;
    }
}

void deleteAtPosition() {
    if (first == NULL) {
        printf("Nothing to delete! Exiting...");
        return;
    }
    int position;
    printf("Enter the position where you want to delete Node:\n");
    scanf("%d", &position);
    if (position == 1) {
        Node* temp = first;
        first = first->ptr;
        temp->ptr = NULL;
        free(temp);
        return;
    }
    Node* temp_prev = NULL;
    Node* temp = first;
    int count = 1;
    while (temp->ptr != NULL && count < position) {
        temp_prev = temp;
        temp = temp->ptr;
        count++;
    }
    if (count != position) {
        printf("Position %d does not exist in the linked list!\n", position);
        return;
    }
    temp_prev->ptr = temp->ptr;
    temp->ptr = NULL;
    free(temp);
}

```
**Output**
```
New Node: ID: 1001 Name: Prabhat Shinde Sal:192834.23
New Node: ID: 1002 Name: Elon Musk Sal:172324.23
New Node: ID: 1003 Name: Jeff Bezos Sal:12234.23
New Node: ID: 1004 Name: Larry Ellison Sal:14234.23
New Node: ID: 1005 Name: Linus Torvalds Sal:15234.22
Id: 1001, Name: Prabhat Shinde, Salary: 192834.23
Id: 1002, Name: Elon Musk, Salary: 172324.23
Id: 1003, Name: Jeff Bezos, Salary: 12234.23
Id: 1004, Name: Larry Ellison, Salary: 14234.23
Id: 1005, Name: Linus Torvalds, Salary: 15234.22
Enter the position where you want to delete Node:
2
Id: 1001, Name: Prabhat Shinde, Salary: 192834.23
Id: 1003, Name: Jeff Bezos, Salary: 12234.23
Id: 1004, Name: Larry Ellison, Salary: 14234.23
Id: 1005, Name: Linus Torvalds, Salary: 15234.22
Enter the position where you want to delete Node:
4
Id: 1001, Name: Prabhat Shinde, Salary: 192834.23
Id: 1003, Name: Jeff Bezos, Salary: 12234.23
Id: 1004, Name: Larry Ellison, Salary: 14234.23
Enter the position where you want to delete Node:
5
Position 5 does not exist in the linked list!
Id: 1001, Name: Prabhat Shinde, Salary: 192834.23
Id: 1003, Name: Jeff Bezos, Salary: 12234.23
Id: 1004, Name: Larry Ellison, Salary: 14234.23

```
Code step by step:

1. **Header Files**: The code includes necessary header files like `stdio.h`, `stdlib.h`, and `string.h`.

2. **Constants**: Macros are defined for the number of rows (`ROW`) and columns (`COL`) in the string array.

3. **Employee Structure**: The structure `Employee` is defined to hold information about an employee, including their ID, name, salary, and a pointer to the next employee.

4. **Type Definition**: The `Node` type is defined as a pointer to an `Employee` structure.

5. **Global Variable**: A global variable `first` of type `Node*` is declared to represent the first node in the linked list.

6. **Function Prototypes**: Prototypes for functions `extractRecordFromString`, `createNode`, `disp`, `addAtEnd`, and `deleteAtPosition` are declared.

7. **Main Function**: 
   - The main function initializes a string `str` containing employee records separated by colons.
   - It then iterates over each record, extracts it using `extractRecordFromString`, creates a node for each record using `createNode`, and adds the node to the end of the linked list using `addAtEnd`.
   - After adding all nodes, it displays the linked list using the `disp` function.
   - It then prompts the user to enter the position of the node to delete and calls the `deleteAtPosition` function accordingly.
   - The process of deletion is repeated twice more.

8. **extractRecordFromString Function**: 
   - This function takes a string array `str` and an index `i` as input.
   - It tokenizes the string using the delimiter `':'` and returns the token corresponding to index `i`.

9. **createNode Function**: 
   - This function creates a new node for an employee.
   - It takes a string `arr` containing employee information separated by commas as input.
   - It tokenizes the string to extract the ID, name, and salary of the employee and assigns them to the corresponding fields of the new node.
   - It initializes the `ptr` field of the node to `NULL` and prints the details of the new node.

10. **disp Function**: 
    - This function displays the details of all nodes in the linked list.
    - It traverses the linked list starting from the `first` node and prints the ID, name, and salary of each employee.

11. **addAtEnd Function**: 
    - This function adds a new node to the end of the linked list.
    - It takes a string `arr` containing employee information as input.
    - It creates a new node using the `createNode` function and adds it to the end of the linked list.

12. **deleteAtPosition Function**: 
    - This function deletes a node from the specified position in the linked list.
    - It prompts the user to enter the position of the node to delete.
    - If the position is `1`, it deletes the first node from the list.
    - Otherwise, it traverses the list to find the node at the specified position and deletes it.
    - If the specified position does not exist in the list, it displays an error message.

## Code 3 : Demonstrate implementation of a linked list to manage employee records

```c
#include<stdio.h>

struct Employee{
	int id;
	// make sure your char array is big enough
	// if its exactly same size as name
	// there will be no null terminator
	// and it will print garbage value
	// till it finds a null character.
	char name[25];
	double salary;
};

int main(){
	struct Employee var = {1001, "Admiral Univese", 989723.34};
	printf("ID: %d\tName: %s\tSal:%.2lf\n", var.id, var.name, var.salary);
}
```
**Output**
```
ID: 1001	Name: Admiral Univese	Sal:989723.34

```
This code defines a structure `Employee` with three members: `id` (integer), `name` (character array), and `salary` (double). In the `main` function, an instance of the `Employee` structure named `var` is created and initialized with values `{1001, "Admiral Universe", 989723.34}`. Then, the `printf` function is used to display the values of the `id`, `name`, and `salary` members of the `var` structure.

Here's a breakdown of the code:

1. **Structure Definition**: 
   - The `Employee` structure is defined with three members: `id` (integer), `name` (character array), and `salary` (double). 
   - Note the comment about ensuring that the `name` array has enough space to store the string and a null terminator.

2. **Main Function**: 
   - Inside the `main` function, an instance of the `Employee` structure named `var` is declared and initialized with the values `{1001, "Admiral Universe", 989723.34}`.
   - The `printf` function is then used to print the values of the `id`, `name`, and `salary` members of the `var` structure. 
   - The format specifier `%s` is used to print the string stored in the `name` member.
   - The format specifier `%.2lf` is used to print the `salary` member with two decimal places. 

3. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the `var` structure:
     ```
     ID: 1001    Name: Admiral Universe    Sal:989723.34
     ```
## Code 4 : Demonstrate  use structure pointers in C.

```c
     #include<stdio.h>

struct Employee{
	int id;
	// make sure your char array is big enough
	// if its exactly same size as name
	// there will be no null terminator
	// and it will print garbage value
	// till it finds a null character.
	char name[25];
	double salary;
};

int main(){
	struct Employee var = {1001, "Admiral Universe", 989723.34};
	
	struct Employee *ptr = &var;
	
	printf("ID: %d\tName: %s\tSal:%.2lf\n", var.id, var.name, var.salary);

	// using struct pointer to print variables:
	printf("ID: %d\tName: %s\tSal:%.2lf\n", (*ptr).id, (*ptr).name, (*ptr).salary);
	// using arrow operator to print variables from a struct pointer
	printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);

}
```
**Output**:
```
ID: 1001    Name: Admiral Universe    Sal:989723.34
ID: 1001    Name: Admiral Universe    Sal:989723.34
ID: 1001    Name: Admiral Universe    Sal:989723.34
     `
```
This code demonstrates how to use structure pointers in C. 

Here's a breakdown of the logic:

1. **Structure Definition**: 
   - The code defines a structure named `Employee` with three members: `id` (integer), `name` (character array), and `salary` (double). 
   - There's a comment explaining the importance of ensuring that the `name` array has enough space to accommodate the string and a null terminator.

2. **Main Function**: 
   - Inside the `main` function, an instance of the `Employee` structure named `var` is declared and initialized with the values `{1001, "Admiral Universe", 989723.34}`.
   
3. **Structure Pointer**: 
   - Another variable `ptr` of type `struct Employee*` (pointer to `Employee` structure) is declared and initialized with the address of the `var` structure using the `&` operator.
   
4. **Printing Member Values**:
   - The `printf` function is used to print the values of the `id`, `name`, and `salary` members of the `var` structure using both direct member access and pointer dereferencing.
     - The first `printf` statement prints the values using direct member access (`var.id`, `var.name`, `var.salary`).
     - The second `printf` statement demonstrates dereferencing the pointer `ptr` to access structure members using the `(*ptr).id`, `(*ptr).name`, and `(*ptr).salary` syntax.
     - The third `printf` statement uses the arrow operator (`->`) to directly access structure members through the pointer `ptr`.

5. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the `var` structure twice: once using direct member access and once using structure pointers. The output will be identical in both cases:
     ```
     ID: 1001    Name: Admiral Universe    Sal:989723.34
     ID: 1001    Name: Admiral Universe    Sal:989723.34
     ID: 1001    Name: Admiral Universe    Sal:989723.34
     ```
## Code 5 : Demonstrate  dynamic memory allocation for a structure using malloc and then initializing its members using a structure pointer.

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
};

int main(){
	// Another way to allocate space for a struct and assign values to struct
	// by using a struct pointer:
	struct Employee *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		ptr->id = 1001;
		strcpy(ptr->name, "Manoj Kumar Pandey");
		ptr->salary = 78000.12;
	// using arrow operator to print variables from a struct pointer
	printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
}
```
 **Output**:
```
ID: 1001	Name: Manoj Kumar Pandey	Sal:78000.12
```
This code demonstrates dynamic memory allocation for a structure using `malloc` and then initializes its members using a structure pointer. Here's a breakdown of the code:

1. **Structure Definition**: 
   - The code defines a structure named `Employee` with three members: `id` (integer), `name` (character array), and `salary` (double).

2. **Main Function**: 
   - Inside the `main` function:

3. **Dynamic Memory Allocation**: 
   - The `malloc` function is used to allocate memory dynamically for a structure of type `Employee` using `sizeof(struct Employee)`. The returned pointer `ptr` is of type `struct Employee*`.
   - If the allocation is successful (`ptr != NULL`), the code proceeds to initialize the structure members.

4. **Initializing Structure Members**: 
   - The structure members `id`, `name`, and `salary` are initialized using the arrow operator (`->`) to access structure members through the pointer `ptr`.
   - `ptr->id` is assigned `1001`.
   - `strcpy(ptr->name, "Manoj Kumar Pandey")` copies the string `"Manoj Kumar Pandey"` into the `name` member of the structure pointed to by `ptr`.
   - `ptr->salary` is assigned `78000.12`.

5. **Printing Structure Member Values**:
   - Finally, the `printf` function is used to print the values of the `id`, `name`, and `salary` members of the dynamically allocated structure.
   - The arrow operator (`->`) is used to access structure members through the pointer `ptr`.

6. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the dynamically allocated structure:
     ```
     ID: 1001    Name: Manoj Kumar Pandey    Sal:78000.12
     ```

7. **Memory Deallocation (Missing)**:
   - It's important to note that this code lacks memory deallocation using `free(ptr)` after the structure is no longer needed to avoid memory leaks.
  
  
## Code 6 : Demonstrate  dynamic memory allocation for a structure using malloc and initializes its members by accepting input from the user. 

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
};

int main(){
	// Yet Another way to allocate space for a struct and assign values to struct
	// by using a struct pointer:
	struct Employee *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		// using arrow operator to print variables from a struct pointer
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
}
```
**Output**:
```
Enter id, name, salary:1111,Manoj,98766
ID: 1111	Name: Manoj	Sal:98766.00
```
This code demonstrates dynamic memory allocation for a structure using `malloc` and initializes its members by accepting input from the user. Here's a breakdown of the code:

1. **Structure Definition**: 
   - The code defines a structure named `Employee` with three members: `id` (integer), `name` (character array), and `salary` (double).

2. **Main Function**: 
   - Inside the `main` function:

3. **Dynamic Memory Allocation**: 
   - The `malloc` function is used to allocate memory dynamically for a structure of type `Employee` using `sizeof(struct Employee)`. The returned pointer `ptr` is of type `struct Employee*`.

4. **Input from User**:
   - The `printf` function prompts the user to enter values for the `id`, `name`, and `salary` members of the structure.
   - The `scanf` function reads the input from the user. It expects the user to enter values in the format: `id,name,salary`. The input values are stored directly into the members of the structure pointed to by `ptr`. 
     - `%d` reads an integer value for `id`.
     - `%[^,]` reads a string (name) until it encounters a comma (`,`).
     - `%lf` reads a double value for `salary`.
   - Note: The `^` character inside the format string `[^,]` is used to specify that the input should read characters until a comma is encountered.

5. **Printing Structure Member Values**:
   - Finally, the `printf` function is used to print the values of the `id`, `name`, and `salary` members of the dynamically allocated structure.
   - The arrow operator (`->`) is used to access structure members through the pointer `ptr`.

6. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the dynamically allocated structure entered by the user.

7. **Memory Deallocation (Missing)**:
   - It's important to note that this code lacks memory deallocation using `free(ptr)` after the structure is no longer needed to avoid memory leaks.

## Code 7 : Demonstrate Dynamic memory allocation for a structure using malloc and initializes its members by accepting input from the user

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr; // Pointer for storing address
};

// using typedef:
typedef struct Employee Node;

int main(){
	// Yet Another way to allocate space for a struct and assign values to struct
	// by using a struct pointer.
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		// pointing the pointer ptr (next Node pointer) to itself.
		ptr->ptr = ptr;
		// using arrow operator to print variables from a struct pointer
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->ptr->id, ptr->ptr->name, ptr->ptr->salary);
			printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->ptr->ptr->id, ptr->ptr->ptr->name, ptr->ptr->ptr->salary);
	}
}
```
**Output**:
```
Enter id, name, salary:1111,Param,98655
ID: 1111	Name: Param	Sal:98655.00
ID: 1111	Name: Param	Sal:98655.00
ID: 1111	Name: Param	Sal:98655.00

```
This code demonstrates dynamic memory allocation for a structure using `malloc` and initializes its members by accepting input from the user. Additionally, it creates a self-referential structure by making the `ptr` member point to the structure itself. Let's break down the code:

1. **Structure Definition**: 
   - The code defines a structure named `Employee` with four members: `id` (integer), `name` (character array), `salary` (double), and `ptr` (pointer to a structure of type `Employee`).

2. **Using Typedef**: 
   - The `typedef` statement is used to create an alias `Node` for the structure `Employee`.

3. **Main Function**: 
   - Inside the `main` function:

4. **Dynamic Memory Allocation**: 
   - The `malloc` function is used to allocate memory dynamically for a structure of type `Employee` using `sizeof(struct Employee)`. The returned pointer `ptr` is of type `struct Employee*`.

5. **Input from User**:
   - The `printf` function prompts the user to enter values for the `id`, `name`, and `salary` members of the structure.
   - The `scanf` function reads the input from the user in the format: `id,name,salary`. The input values are stored directly into the members of the structure pointed to by `ptr`. 

6. **Self-Referential Structure**:
   - After assigning values to the structure members, the `ptr` member is assigned the address of the structure itself. This creates a self-referential structure where each structure contains a pointer to another structure of the same type.

7. **Printing Structure Member Values**:
   - The `printf` function is used to print the values of the `id`, `name`, and `salary` members of the dynamically allocated structure.
   - The arrow operator (`->`) is used to access structure members through the pointer `ptr`. 
   - Additionally, the `ptr` member of the structure itself is accessed using `ptr->ptr`.

8. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the dynamically allocated structure entered by the user. It will also display the values of these members through the self-referential `ptr` member.
  
## Code 8 : Demonstrate Dynamic memory allocation for a structure using malloc and initializes its members by accepting input from the user

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	// Pointer for storing address
	struct Employee *ptr;
};

// using typedef:
typedef struct Employee Node;

// this is the head of the linked list:
Node* first = NULL;

Node* createNode(){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");


		// Notice how we are reading the string! using , as a delimitor.
		// Also note that strings in C are just array of chars
		// the variable name is already a pointer to the first char
		// therefore, no need to use & there.

		scanf("%d, %[^,], %lf", &ptr->id, ptr->name, &ptr->salary);
		// pointing the pointer ptr (next Node pointer) to NULL.
		ptr->ptr = NULL;

		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}

void addAtBeg(){
	Node* New = createNode();
	if(first == NULL){
		first = New;
	}
	else{
		New->ptr = first;
		first = New;
	}
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Id: %d, Name: %s, Salary:%.2lf\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
}




int main(){
	addAtBeg();
	addAtBeg();
	addAtBeg();
	disp();
	addAtBeg();
	addAtBeg();
	disp();
}

```
**Output**:
```

Enter id, name, salary:1111,Paramveer,99866
ID: 1111	Name: Paramveer	Sal:99866.00
Enter id, name, salary:2222,Mahaveer,99966
ID: 2222	Name: Mahaveer	Sal:99966.00
Enter id, name, salary:3333,Veer,97600
ID: 3333	Name: Veer	Sal:97600.00
Id: 3333, Name: Veer, Salary:97600.00
Id: 2222, Name: Mahaveer, Salary:99966.00
Id: 1111, Name: Paramveer, Salary:99866.00
Enter id, name, salary:4444,Param,78999
ID: 4444	Name: Param	Sal:78999.00
Enter id, name, salary:5555,Somnath,99999
ID: 5555	Name: Somnath	Sal:99999.00
Id: 5555, Name: Somnath, Salary:99999.00
Id: 4444, Name: Param, Salary:78999.00
Id: 3333, Name: Veer, Salary:97600.00
Id: 2222, Name: Mahaveer, Salary:99966.00
Id: 1111, Name: Paramveer, Salary:99866.00

```
This code demonstrates dynamic memory allocation for a structure using `malloc` and initializes its members by accepting input from the user. Additionally, it creates a self-referential structure by making the `ptr` member point to the structure itself. Let's break down the code:

1. **Structure Definition**: 
   - The code defines a structure named `Employee` with four members: `id` (integer), `name` (character array), `salary` (double), and `ptr` (pointer to a structure of type `Employee`).

2. **Using Typedef**: 
   - The `typedef` statement is used to create an alias `Node` for the structure `Employee`.

3. **Main Function**: 
   - Inside the `main` function:

4. **Dynamic Memory Allocation**: 
   - The `malloc` function is used to allocate memory dynamically for a structure of type `Employee` using `sizeof(struct Employee)`. The returned pointer `ptr` is of type `struct Employee*`.

5. **Input from User**:
   - The `printf` function prompts the user to enter values for the `id`, `name`, and `salary` members of the structure.
   - The `scanf` function reads the input from the user in the format: `id,name,salary`. The input values are stored directly into the members of the structure pointed to by `ptr`. 

6. **Self-Referential Structure**:
   - After assigning values to the structure members, the `ptr` member is assigned the address of the structure itself. This creates a self-referential structure where each structure contains a pointer to another structure of the same type.

7. **Printing Structure Member Values**:
   - The `printf` function is used to print the values of the `id`, `name`, and `salary` members of the dynamically allocated structure.
   - The arrow operator (`->`) is used to access structure members through the pointer `ptr`. 
   - Additionally, the `ptr` member of the structure itself is accessed using `ptr->ptr`.

8. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the dynamically allocated structure entered by the user. It will also display the values of these members through the self-referential `ptr` member.
  
## Code 9 : Demonstrate function that dynamically allocates memory for a structure
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr; // Pointer for storing address
};

// using typedef:
typedef struct Employee Node;

Node* createNode(){
	// Yet Another way to allocate space for a struct and assign values to struct
	// by using a struct pointer.
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		// pointing the pointer ptr (next Node pointer) to itself.
		ptr->ptr = ptr;
		// using arrow operator to print variables from a struct pointer
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}

int main(){
	Node* ptr = createNode();
}
```
**Output**:
```
Enter id, name, salary:1111,Pratap,98777
ID: 1111	Name: Pratap	Sal:98777.00

```
This code defines a function `createNode` that dynamically allocates memory for a structure of type `Employee`, initializes its members with values entered by the user, creates a self-referential structure, and returns a pointer to the newly created structure. Let's break down the code:

1. **Structure Definition**: 
   - The code defines a structure named `Employee` with four members: `id` (integer), `name` (character array), `salary` (double), and `ptr` (pointer to a structure of type `Employee`).

2. **Using Typedef**: 
   - The `typedef` statement is used to create an alias `Node` for the structure `Employee`.

3. **Function `createNode`**:
   - This function dynamically allocates memory for a structure of type `Employee` using `malloc(sizeof(struct Employee))`. The returned pointer `ptr` is of type `struct Employee*`.

4. **Input from User**:
   - The `printf` function prompts the user to enter values for the `id`, `name`, and `salary` members of the structure.
   - The `scanf` function reads the input from the user in the format: `id,name,salary`. The input values are stored directly into the members of the structure pointed to by `ptr`. 

5. **Self-Referential Structure**:
   - After assigning values to the structure members, the `ptr` member is assigned the address of the structure itself. This creates a self-referential structure where each structure contains a pointer to another structure of the same type.

6. **Printing Structure Member Values**:
   - The `printf` function is used to print the values of the `id`, `name`, and `salary` members of the dynamically allocated structure.
   - The arrow operator (`->`) is used to access structure members through the pointer `ptr`. 

7. **Main Function**:
   - Inside the `main` function:
     - It calls the `createNode` function, which dynamically creates a structure, initializes its members with user input, and returns a pointer to the created structure. 
     - The returned pointer is stored in the `ptr` variable of type `Node*`.

8. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the dynamically allocated structure entered by the user. It will also create a self-referential structure where the `ptr` member points to the structure itself.

## Code 10 : Demonstrate dynamically allocates memory for a structure 
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr; // Pointer for storing address
};

// using typedef:
typedef struct Employee Node;

int main(){
	// Yet Another way to allocate space for a struct and assign values to struct
	// by using a struct pointer.
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		// using arrow operator to print variables from a struct pointer
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
}
```
**Output**
```
Enter id, name, salary:1111,Somnath,98777
ID: 1111	Name: Somnath	Sal:98777.00

```
This code dynamically allocates memory for a structure of type `Employee`, prompts the user to enter values for the structure members (`id`, `name`, and `salary`), and then prints the entered values. Let's break down the code:

1. **Structure Definition**: 
   - The code defines a structure named `Employee` with four members: `id` (integer), `name` (character array), `salary` (double), and `ptr` (pointer to a structure of type `Employee`).

2. **Using Typedef**: 
   - The `typedef` statement is used to create an alias `Node` for the structure `Employee`.

3. **Main Function**:
   - Inside the `main` function:
     - It dynamically allocates memory for a structure of type `Employee` using `malloc(sizeof(struct Employee))`. The returned pointer `ptr` is of type `struct Employee*`.

4. **Input from User**:
   - The `printf` function prompts the user to enter values for the `id`, `name`, and `salary` members of the structure.
   - The `scanf` function reads the input from the user in the format: `id,name,salary`. The input values are stored directly into the members of the structure pointed to by `ptr`. 

5. **Printing Structure Member Values**:
   - The `printf` function is used to print the values of the `id`, `name`, and `salary` members of the dynamically allocated structure.
   - The arrow operator (`->`) is used to access structure members through the pointer `ptr`. 

6. **Output**:
   - The output of the code will display the values of the `id`, `name`, and `salary` members of the dynamically allocated structure entered by the user.
  
## Code 11 : Demonstrate implementation of a linked list
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
	int number;
	struct Data* next;
};


typedef struct Data Node;


Node* first = NULL;

Node* createNode(int num){
	Node *ptr = malloc(sizeof(struct Data));
	if(ptr != NULL){
		ptr->number = num;
		ptr->next = NULL;
	}
	return ptr;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = New;
	}
	else{
		New->next = first;
		first = New;
	}
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Number: %d\n", temp->number);
		temp = temp->next;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = New;
	}
	else{
		Node* temp = first;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = New;
	}
}

void readFromFile(){
	char filedir[100];
	printf("Enter the full path of file to read from (or just filename if in same directory):\n");
	scanf("%s", filedir);

	FILE* fileptr;
	fileptr = fopen(filedir, "r");
	int filecontent[100] = {0}, i = 0;

	if(fileptr == NULL)
	{
		printf("File not found, exiting...");
		return;
	}
	else
	{

		while(!feof(fileptr)){
			fscanf(fileptr, "%d", &filecontent[i]);
			i++;
		}
		fclose(fileptr);
	}

	for(int x =0; x<i-1; x++){
		addAtEnd(filecontent[x]);
	}
}



int main(){
	readFromFile();
	disp();
}
```
**Output**
```
Enter the full path of file to read from (or just filename if in same directory):
file code
File not found, exiting...
```
This code is a simple implementation of a linked list in C. Let's break down the main components and functionality:

1. **Structure Definition**:
   - The code defines a structure named `Data`, which contains an integer `number` and a pointer `next` to the next node in the linked list.

2. **Using Typedef**:
   - The `typedef` statement is used to create an alias `Node` for the structure `Data`.

3. **Global Variables**:
   - `Node* first`: This pointer variable is used to store the address of the first node in the linked list.

4. **Function `createNode`**:
   - This function dynamically allocates memory for a new node and initializes its `number` and `next` fields. It takes an integer `num` as an argument and returns a pointer to the newly created node.

5. **Function `addAtBeg`**:
   - This function adds a new node with the given number `num` at the beginning of the linked list.

6. **Function `addAtEnd`**:
   - This function adds a new node with the given number `num` at the end of the linked list.

7. **Function `disp`**:
   - This function traverses the linked list from the first node to the last node and prints the value of the `number` field of each node.

8. **Function `readFromFile`**:
   - This function reads integers from a file specified by the user and adds them to the end of the linked list. The user is prompted to enter the full path of the file. It opens the file in read mode, reads integers until the end of the file (`feof`), and adds them to the linked list using the `addAtEnd` function.

9. **`main` Function**:
   - The `main` function calls the `readFromFile` function to read integers from a file and add them to the linked list. Then, it calls the `disp` function to display the contents of the linked list.

Overall, the code demonstrates how to create a linked list, add elements to it from a file, and display its contents.


## Code 12 : Demonstrate implementation of a linked list of employee records

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr;
};


typedef struct Employee Node;


Node* first = NULL;

Node* createNode(){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d, %[^,], %lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}

void addAtBeg(){
	Node* New = createNode();
	if(first == NULL){
		first = New;
	}
	else{
		New->ptr = first;
		first = New;
	}
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Id: %d, Name: %s, Salary:%.2lf\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
}

void addAtEnd(){
	Node* New = createNode();
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

void addAtPosition(){
	int position;
	printf("Enter the position where you want to insert Node:\n");
	scanf("%d", &position);
	if(position == 1){
		addAtBeg();
		return;
	}

	Node* New = createNode();

	if(first == NULL){
		first = New;
	}
	else{
		Node* temp = first;
		int count = 1;
		while(temp->ptr != NULL && count < position-1){
			temp = temp->ptr;
			count++;
		}
		New->ptr = temp->ptr;
		temp->ptr=New;
	}
}

int main(){
	addAtPosition();
	addAtPosition();
	addAtPosition();
	disp();
	addAtPosition();
	addAtPosition();
	disp();
}
```
**Output**
```
Enter the position where you want to insert Node:
3
Enter id, name, salary:3333,Param,95444
ID: 3333	Name: Param	Sal:95444.00
Enter the position where you want to insert Node:
2
Enter id, name, salary:2222,Shakti,96555
ID: 2222	Name: Shakti	Sal:96555.00
Enter the position where you want to insert Node:
1
Enter id, name, salary:1111,Shivay,98999
ID: 1111	Name: Shivay	Sal:98999.00
Id: 1111, Name: Shivay, Salary:98999.00
Id: 3333, Name: Param, Salary:95444.00
Id: 2222, Name: Shakti, Salary:96555.00
Enter the position where you want to insert Node:
```
This C program demonstrates the implementation of a linked list of employee records. Let's break down its functionality:

1. **Structure Definition**:
   - The code defines a structure named `Employee`, which contains fields for employee ID, name, salary, and a pointer `ptr` to the next employee record.

2. **Using Typedef**:
   - The `typedef` statement is used to create an alias `Node` for the structure `Employee`.

3. **Global Variables**:
   - `Node* first`: This pointer variable is used to store the address of the first node in the linked list.

4. **Function `createNode`**:
   - This function dynamically allocates memory for a new employee record and prompts the user to enter the employee's ID, name, and salary. It then initializes the fields of the new node and prints the entered details. Finally, it returns a pointer to the newly created node.

5. **Function `addAtBeg`**:
   - This function adds a new employee record at the beginning of the linked list. It calls the `createNode` function to create a new node and sets its `ptr` to point to the current first node. Then, it updates the `first` pointer to point to the newly created node.

6. **Function `addAtEnd`**:
   - This function adds a new employee record at the end of the linked list. It follows a similar approach to `addAtBeg`, but instead of traversing the entire list to find the end, it traverses until it reaches the last node and then adds the new node after it.

7. **Function `addAtPosition`**:
   - This function allows the user to specify the position at which a new employee record should be inserted. If the position is 1, it calls `addAtBeg` to insert at the beginning. Otherwise, it creates a new node and inserts it at the specified position by traversing the list to find the node at the previous position and updating pointers accordingly.

8. **Function `disp`**:
   - This function traverses the entire linked list starting from the `first` node and prints the details of each employee record.

9. **`main` Function**:
   - In the `main` function, `addAtPosition` is called multiple times to insert employee records at different positions in the list. Then, `disp` is called to display the contents of the linked list.

Overall, this program provides a basic demonstration of how to manipulate a linked list of employee records in C.

## Code 12 : Demonstrate implementation of a linked list of employee records
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr;
};


typedef struct Employee Node;


Node* first = NULL;

Node* createNode(){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d, %[^,], %lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}

void addAtBeg(){
	Node* New = createNode();
	if(first == NULL){
		first = New;
	}
	else{
		New->ptr = first;
		first = New;
	}
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Id: %d, Name: %s, Salary:%.2lf\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
}

void addAtEnd(){
	Node* New = createNode();
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


int main(){
	addAtEnd();
	disp();
	addAtEnd();
	disp();
	addAtEnd();
	disp();
	addAtEnd();
	disp();
	addAtEnd();
	disp();
}
```
**Output**
```
Enter id, name, salary:1111,Bhairava,68777
ID: 1111	Name: Bhairava	Sal:68777.00
Id: 1111, Name: Bhairava, Salary:68777.00
Enter id, name, salary:2222,Kalami,98777
ID: 2222	Name: Kalami	Sal:98777.00
Id: 1111, Name: Bhairava, Salary:68777.00
Id: 2222, Name: Kalami, Salary:98777.00
Enter id, name, salary:3333,Harera,99566
ID: 3333	Name: Harera	Sal:99566.00
Id: 1111, Name: Bhairava, Salary:68777.00
Id: 2222, Name: Kalami, Salary:98777.00
Id: 3333, Name: Harera, Salary:99566.00
Enter id, name, salary:4444,Vihar,99000
ID: 4444	Name: Vihar	Sal:99000.00
Id: 1111, Name: Bhairava, Salary:68777.00
Id: 2222, Name: Kalami, Salary:98777.00
Id: 3333, Name: Harera, Salary:99566.00
Id: 4444, Name: Vihar, Salary:99000.00
Enter id, name, salary:
```
This C program demonstrates the creation of a linked list of employee records and adds nodes to the end of the list. Let's break down its functionality:

1. **Structure Definition**:
   - The code defines a structure named `Employee`, which contains fields for employee ID, name, salary, and a pointer `ptr` to the next employee record.

2. **Using Typedef**:
   - The `typedef` statement is used to create an alias `Node` for the structure `Employee`.

3. **Global Variables**:
   - `Node* first`: This pointer variable is used to store the address of the first node in the linked list.

4. **Function `createNode`**:
   - This function dynamically allocates memory for a new employee record and prompts the user to enter the employee's ID, name, and salary. It then initializes the fields of the new node and prints the entered details. Finally, it returns a pointer to the newly created node.

5. **Function `addAtBeg`**:
   - This function adds a new employee record at the beginning of the linked list. It calls the `createNode` function to create a new node and sets its `ptr` to point to the current first node. Then, it updates the `first` pointer to point to the newly created node.

6. **Function `disp`**:
   - This function traverses the entire linked list starting from the `first` node and prints the details of each employee record.

7. **Function `addAtEnd`**:
   - This function adds a new employee record at the end of the linked list. It follows a similar approach to `addAtBeg`, but instead of traversing the entire list to find the end, it traverses until it reaches the last node and then adds the new node after it.

8. **`main` Function**:
   - In the `main` function, `addAtEnd` is called multiple times to insert employee records at the end of the list. After each insertion, `disp` is called to display the contents of the linked list.

Overall, this program provides a basic demonstration of how to create and manipulate a linked list of employee records in C, specifically adding nodes to the end of the list.
