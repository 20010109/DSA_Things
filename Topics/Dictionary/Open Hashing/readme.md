# 🧩 Open Hashing (Separate Chaining) in C

This program implements a **hash table using open hashing (separate chaining)**, where collisions are handled through linked lists.  
It demonstrates how to **insert**, **search**, **delete**, and **display** elements in a hash table.

---

## 📘 Overview

In **open hashing**, each slot in the hash table contains a **linked list (chain)** of keys that hash to the same index.  
When two or more keys share the same hash index, they are stored in that list.

This project uses:
- A fixed table size (`SIZE = 10`)
- The hash function:  
```c
  hash = key % SIZE;
```

## 🧱 Data Structures
```c
typedef struct Node {
    int data;
    struct Node* link;
} Node, *NodePtr;

typedef struct {
    NodePtr List[SIZE];
} Dictionary;
```
* Each index in the Dictionary contains a pointer to the head of a linked list.
* Each Node stores an integer value (data) and a pointer to the next node (link).

## ⚙️ Core Functions

| Function                              | Description                                                    |
| ------------------------------------- | -------------------------------------------------------------- |
| `void initDictionary(Dictionary* D)`  | Initializes all table indices to `NULL`.                       |
| `int hashFunction(int key)`           | Returns the hash index using `key % SIZE`.                     |
| `void insert(Dictionary *D, int key)` | Inserts a new key into its respective chain.                   |
| `int search(Dictionary D, int key)`   | Searches for a key and returns its value or `-1` if not found. |
| `void delete(Dictionary *D, int key)` | Deletes a key from the hash table if found.                    |
| `void display(Dictionary D)`          | Displays all chains and their elements.                        |
| `NodePtr createNode(int key)`         | Allocates and initializes a new node.                          |


## 💻 Example Code (Main Function)

```c
int main(){
    Dictionary D;
    initDictionary(&D);

    int SetA[] = {1 ,32 ,23 ,14 ,5, 15, 25, 35, 7, 17, 21, 52, 33};

    for(int i = 0; i < sizeof(SetA) / sizeof(int); i++){
        insert(&D, SetA[i]);
    }

    display(D);

    delete(&D, 23);
    delete(&D, 25);

    printf("After Deletion.\n");
    display(D);
}
```

## 🧪 Test Case with Collisions

Given Hash Function:

```c
hash = key % 10;
```

Insert the following keys:

```plaintext
{1, 32, 23, 14, 5, 15, 25, 35, 7, 17, 21, 52, 33}
```

Sample Collision Groups:

| Hash Index | Keys Colliding |
| ---------- | -------------- |
| 2          | 32, 52         |
| 3          | 23, 33         |
| 5          | 5, 15, 25, 35  |
| 7          | 7, 17          |
| 1          | 1, 21          |

Example Output (Display):
```c
--- Display ---
    0|Empty
    1|1    |21   |
    2|32   |52   |
    3|23   |33   |
    4|14   |
    5|5    |15   |25   |35   |
    6|Empty
    7|7    |17   |
    8|Empty
    9|Empty
```

After Deletion (remove 23 and 25):

```c
--- Display ---
    0|Empty
    1|1    |21   |
    2|32   |52   |
    3|33   |
    4|14   |
    5|5    |15   |35   |
    6|Empty
    7|7    |17   |
    8|Empty
    9|Empty
```

## 🔍 Search Function (Optional Utility)
```c
void searchKey(Dictionary D, int key){
    int s = search(D, key);
    if(s != -1){
        printf("%d found!\n", key);
    } else {
        printf("%d not found!\n", key);
    }
}
```

## 🧠 Key Concepts Demonstrated

* Open Hashing / Separate Chaining
* Dynamic memory allocation
* Linked list traversal and manipulation
* Basic hash table operations (insert, delete, search, display)
