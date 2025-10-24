Sorted Stack Insertion using Virtual Heap
By Zeus Elderfield

DSA
You are given a virtual heap implementation (VHeap) that manages memory manually using an array of nodes. A stack is represented using an index pointing to the top element inside this virtual heap.

Your task is to implement a function that inserts a new integer into the stack such that the stack always remains sorted in ascending order.

If the stack is empty, the element is directly inserted.

Otherwise, the element must be placed at the correct position while shifting nodes as needed.

You must use the VHeap structure for managing available nodes (through the avail pointer).

Input
1. The first line contains an integer N, the number of elements to be inserted.
2. The next N lines each contain an integer representing the element to be inserted into the stack.

Output
1. Print the stack elements from top to bottom after all insertions are completed.
2. Elements must be displayed in ascending order since the stack maintains sorted order.