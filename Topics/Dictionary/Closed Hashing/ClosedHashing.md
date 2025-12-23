# Closed Hash Table

## Overview
This document describes the behavior and structure of the provided C code implementing a hash table for characters using open addressing.

---

## Data Definitions

### Constants
```c
#define MAX 10
#define EMPTY '~'
#define DELETED '!'
```
- `MAX` defines the size of the hash table.
- `EMPTY` represents an unused slot.
- `DELETED` marks a slot where an element was removed.

---

### Dictionary Type
```c
typedef char Dictionary[MAX];
```
- The dictionary is a fixed-size array of characters.

---

## Hash Function
```c
int hash(char elem){
    return elem % MAX;
}
```
- Computes the index using the ASCII value of the character modulo `MAX`.

---

## Functions

### initDictionary
```c
void initDictionary(Dictionary D)
```
- Initializes all slots in the dictionary to `EMPTY`.

---

### displayDictionary
```c
void displayDictionary(Dictionary D)
```
- Displays the index and content of each slot.
- Prints `EMPTY`, `DELETED`, or the stored character.

---

### isMember
```c
Boolean isMember(Dictionary D, char elem)
```
- Searches for a character starting at its hashed index.
- Moves sequentially through the table until the element is found, an `EMPTY` slot is encountered, or the table is fully scanned.
- Returns `TRUE` if found, otherwise `FALSE`.

---

### insertUnique
```c
void insertUnique(Dictionary D, char elem)
```
- Inserts a character if it does not already exist in the dictionary.
- Starts at the hashed index and checks subsequent slots sequentially.
- Inserts into the first `EMPTY` or `DELETED` slot encountered.

---

### deleteMember
```c
void deleteMember(Dictionary D, char elem)
```
- Searches for the specified character.
- If found, marks its slot as `DELETED`.

---

## Program Flow (main)
```c
int main()
```
- Initializes the dictionary.
- Inserts a set of characters.
- Deletes selected characters.
- Tests membership for a character.
- Displays the final state of the dictionary.

---

## Notes
- The dictionary stores only unique characters.
- Deleted slots are marked to preserve search correctness.

