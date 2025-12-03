## POT EXERCISES (15 Minutes each)

**Activity Set**: Hospital Emergency Queue

**Activity 1 Description:** <br>
A hospital emergency department manages patients using priority values (higher number = more urgent). You must write a function that inserts a new patient’s priority (priority num) into a max-heap, maintaining the heap order.

**Code Template:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
	int patient_id;
	int priority_num;
	String patient_name;
	String reason;
} PatientPriorityInfo;

typedef struct {
	PatientPriorityInfo patients[32];
	int last;
} HEAP;

void insertPatient(HEAP heap, PatientPriorityInfo patient){
	// insert code here
}
```
**Activity 2 Description:** <br>
Write a function that deletes the first element from the heap, and displays its information. NOTE: After deletion, it must readjust the tree to satisfy POT property. 

Code Template:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
	int patient_id;
	int priority_num;
	String patient_name;
	String reason;
} PatientPriorityInfo;

typedef struct {
	PatientPriorityInfo patients[32];
	int last;
} HEAP;

void insertPatient(HEAP *heap, PatientPriorityInfo patient){
	// your code from activity 1
}

void deleteFirst(HEAP *heap){
	// insert your code here
}
```
