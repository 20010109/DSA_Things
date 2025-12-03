# Deleting from the BeaST
by Edwin Bartlett

Practice deleting elements from BST

 

Steps (iterative):

1. Find the node to delete ('current') and its parent ('parent')
2. Handle case 3: Node with 2 children
    1. Find the in-order successor (minimum node in the right subtree) and its parent
    2. Copy successor's key to the current node (replacement)
    3. Update 'current' and 'parent' for the remaining logic to delete the successor's original location.
3. Case 1 & 2: Node with 0 or 1 child (or the successor after Case 3)
 

Also try:

* Recursive and iterative delete function

Sample Output 1
```c
--- Building BST for Deletion Test ---
Inserted: "Mango"
Inserted: "Apple"
Inserted: "Pineapple"
Inserted: "Banana"
Inserted: "Grape"
Inserted: "Orange"
Inserted: "Kiwi"

Initial In-Order Traversal:
   "Apple" "Banana" "Grape" "Kiwi" "Mango" "Orange" "Pineapple"

--- Test 1: Delete Leaf Node (Kiwi) ---
Resulting Traversal: "Apple" "Banana" "Grape" "Mango" "Orange" "Pineapple"

--- Test 2: Delete Node with 1 Child (Apple) ---
Resulting Traversal: "Banana" "Grape" "Mango" "Orange" "Pineapple"

--- Test 3: Delete Node with 2 Children (Mango - the Root) ---
Resulting Traversal: "Banana" "Grape" "Orange" "Pineapple"

--- Test 4: Delete Non-Existent Key (Zebra) ---
Key "Zebra" not found for deletion.
No change expected: "Banana" "Grape" "Orange" "Pineapple"

Tree destroyed and memory freed.
```