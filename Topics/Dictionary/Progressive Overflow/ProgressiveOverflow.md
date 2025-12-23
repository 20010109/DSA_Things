# Progressive Overflow Hash Table

## Overview
This document describes the provided C program that implements a hash table with a primary area and an overflow area for handling collisions.

---

## Data Definitions

### Constants
```c
#define M 7
#define O 5
#define EMPTY -1
```
- `M` is the size of the primary hash table.
- `O` is the size of the overflow area.
- `EMPTY` represents an unused slot.

---

### Table Structure
```c
int table[M + O];
```
- The table is a single array divided logically into:
  - Indices `0` to `M-1`: primary area
  - Indices `M` to `M+O-1`: overflow area

---

## Hash Function
```c
int hash(int key) {
    return key % M;
}
```
- Computes the index within the primary area using modulo `M`.

---

## Functions

### insert
```c
void insert(int key)
```
- Computes the hashed index for the key.
- If the primary slot is empty, inserts the key there.
- If a collision occurs, searches the overflow area sequentially.
- Inserts the key into the first empty overflow slot.
- Prints an error message if the overflow area is full.

---

### display
```c
void display()
```
- Prints all indices of the table.
- Displays either `EMPTY` or the stored key for each slot.

---

## Program Flow (main)
```c
int main()
```
- Initializes all table entries to `EMPTY`.
- Inserts a predefined set of integer keys.
- Displays the final contents of the table.

---

## Notes
- Collisions in the primary area are handled by inserting into the overflow area.
- The overflow area is filled sequentially.

