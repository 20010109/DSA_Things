# Array List Implementation Guide

## Overview
Array List is defined as an array inside a List structure that contains a respective count variable. This document covers four variations of ArrayList implementation in C.

## Variation 1: Static Array (Pass by Value)

### Data Structure
```c
#define MAX 10
typedef struct {
    int elem[MAX];
    int count;
} List;

List L;
```

## Operations

| **Operation** | **Description** |
| :-- | :-- |
| List initialize(List L); | Sets count to 0 and returns List	|
| List insertPos(List L, int data, int position); | Inserts data at specified position if valid and array not full	L = insertPos(L, 4, 2); |
| List deletePos(List L, int position); | Deletes element at position and shifts elements left	L = deletePos(L, 1);|
| int locate(List L, int data);	| Returns position of data or -1 if not found	
| List insertSorted(List L, int data); | Inserts data in sorted position (assumes sorted array)	L = insertSorted(L, 8); |
| void display(List L); | Displays all elements up to count |

### Notes:
* Use `insertPos` for **INSERT FIRST** and **INSERT LAST**

* Use `deletePos` for **DELETE FIRST** and **DELETE LAST**

* Use `locate` + `deletePos` for **DELETE BY VALUE**

---

# *TO BE CONTINUED*