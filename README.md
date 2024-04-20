# C-DSA
C DAC High Performance Computing 

# Data Structures in C.

## Data Structures in C.

## What is C Programming language?

```c
C is a mid level programming language that makes the assembly language work much easier.
Developed by Dennis Ritchie in 1972 at BELL LABS. 
It is a Procedural Programming language.
It can divide your program into small units called Functions, Multiple sets of data as structures. 
It can be programmed using a Text editor and saved with extension .c or .h.
In older times, UNIX, Windows, MYSQL, RDBMS software was built using C language.

```
**What is the difference b/w C and C++?**
```
C++ is an extension of C language with a new feature called Object Oriented Programming.
It is also called as C with Classes. It is a very similar syntax like C language.
```

**What is required for a programming language to be used?**
```
Every programming language has a set of grammer based on which U write the code(Statements).
This is called as SYNTAX. 
A sp software will be available to read UR statements, convert them into assembly language and make it run on the Computer as per the statements written by you. 
This is called COMPILER. GCC, Windows C are some of the popular compilers available for C language. U can also use Online Compilers that can execute on browsers. 
So to write the code, we need a Text editor like Notepad and to compile the code we need a Compiler like GCC, Windows, Visual Studio or many more.
In real time, we use Integrated Development Environment(IDE) for developing Complex programs. For C,C++ and its family MS Windows gives Visual Studio.
It is free and easily downloadable.
```
**How to start C Programming?**
```
Download a popular IDE like Visual Studio and create a project In the project type, select Console Application or Empty Project.
Add Files into the Source Files. All C files are saved with extension .c. Build the Application for Compilation and Execute it.
Short cuts: Ctrl + Shift + B -> Build the Project. Ctrl +F5 -> Execute the project.
```
///////////////////////////**Data Structures in C**//////////////////////////////////////

**What is a Data Structure?**
```
It is a way of organizing the data where it should be easy to be consumed later efficiently.
It will have 2 parts: interface and implementation. Every Data structure has an interface that represents a set of operations that the data structure shall support.
It provides a list of supported operations, type of parameters that can be accepted and return type of these operations. 
The other part of the Data structure is implementation that provide the internal representation of a data structure.
It involves the logic of achieving that functionality that is defined by the interface. THE DATA STRUCTURE means Organizing/Structuring the data in the memory.
One of the common and popular data structure is ARRAY in C.
```

**NOTE:**
Data structure is not a programming language, it is simply a set of algorithms that we can use in any programming language to structure 
the data that we have stored in the memory of the Application.

```
Structuring the data can be based on the requirement: Storing the data as per your requirement.
Linear Fashion: Arrays, Linked List.
One over the other: Stacks,Queues etc.
Hierarchical fashion: Trees
Connected Nodal fashion: Graphs.
```

**Arrays:**
```
Linear Data structure. Elements are stored in contigious memory locations. 
U can access the elements in the array randomly using the index. Limitation of Array is it can store only homogenious elements(Similar elements). 
Advantages: Random access, easy storing and iterations, replacement of multiple variables. 
Limitations: Fixed size, difficult to insert/delete. If the capacity is more and the storage is less, the memory gets wasted. 
It expects continous memory to get allocated. Main practical purpose of using Arrays is the faster ability in searching and where UR App needs frequent searches.
```

**Linked List:**
```
Similar to arrays in the form of Linear Data structure. 
Elements can be stored as and when its required and based on the memory available. 
It is Dynamic in size. Easy insertion and deletions. Advantages: Efficient memory allocation. 
No wastage of memory as capacity and size are always equal. Disadvantages: No Random access is possible.
If the head node is lost, the list is gone. Main practical purpose is for Apps that require frequent insertions and deletions.
```
