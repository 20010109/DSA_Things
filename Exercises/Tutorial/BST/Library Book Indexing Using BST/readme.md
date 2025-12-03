## BST EXERCISES (15 Minutes each)

**Activity Set:** Library Book Indexing Using BST

**Activity 1 Description:**<br>
A library stores books using a Binary Search Tree based on book ID.
Write a function to insert a new book ID into the BST.

**Code Template:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
	int book_id;
	String book_name;
} Book;

typedef struct node {
	Book book;
	struct node *left;
	struct node *right;
} *BST;

void insertNode(BST *root, Book newBook){
	// insert code here
}
```
**Activity 2 Description:**<br>
A library stores books using a Binary Search Tree based on book ID.
Write a function to display the name of the book based on book ID.

**Code Template:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
	int book_id;
	String book_name;
} Book;

typedef struct node {
	Book book;
	struct node *left;
	struct node *right;
} *BST;

void insertNode(BST *root, Book newBook){
	// your code from activity 1
}

void displayBook(BST root, int book_id){
	// insert your code here
}
```

