# Variation 1 - Bitmask (char holding int value)

This is the most common and space-efficient way to implement a bit vector set. An unsigned `char` (or `int`) is used, and elements are added by setting the corresponding bit using the bitwise OR operator.

| Operations                                                                 | Checklist                                                                                                                                     | Example                                                                                                 |
| :------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------- |
| `void initialize(unsigned char *set);`                                       | Set the entire byte/integer to 0                                                                                                               | `char A = 0;`                                                                                          |
| `void insert(unsigned char *set, int element);`                              | * Safety check: ensure element index is within the bit range <br> * Create a bitmask for the element's position <br> * Perform Bitwise OR assignment | `insert(&A, 1); // A = 2 {1} (00000010)` <br> `insert(&A, 6); // A = 66 {1, 6} (01000010)`                  |
| `void delete(unsigned char *set, int element);`                              | * Safety check: ensure element index is within the bit range <br> * Create a mask for the element's position <br> * Invert the mask (this creates a mask with a 0 at the target bit and 1s everywhere else) <br> * Perform Bitwise AND assignment | `delete(&A, 6); // A = 2 {1} (00000010)` <br> `delete(&A, 1); // A = 0 { } (00000000)`                  |
| `bool find(unsigned char set, int element);`                                 | * Create a mask for the element's position <br> * Use Bitwise AND between the set and the mask                                                  | `find(A, 6); // True (1)` <br> `find(A, 2); // False (0)`                                               |
| `unsigned char union(unsigned char A, unsigned char B);`                    | * The union is achieved by the Bitwise OR operation                                                                                             | `char A = 66; // {1, 6} (01000010)` <br> `char B = 200; // {3, 6, 7} (11001000)` <br> `char C = union(A, B); // C = 202 {1, 3, 6, 7} (11001010)` |
| `unsigned char intersection(unsigned char A, unsigned char B);`             | * The intersection is achieved by the Bitwise AND operation                                                                                   | `char A = 66; // {1, 6} (01000010)` <br> `char B = 200; // {3, 6, 7} (11001000)` <br> `char C = intersection(A, B); // C = 64 {6} (01000000)` |
| `unsigned char difference(unsigned char A, unsigned char B);`               | * The difference is achieved by A AND (NOT B)                                                                                                 | `char A = 66; // {1, 6} (01000010)` <br> `char B = 200; // {3, 6, 7} (11001000)` <br> `char C = difference(A, B); // C = 2 {1} (00000010)` |
| `void display(unsigned char set);`                                          | * Iterate through all possible elements (0 to 7) <br> * Check if the bit corresponding to element is set <br> * If present, print the element, separated by commas | `char A = 202; // {1, 3, 6, 7} (11001010)` <br> `display(A); // Output: 1, 3, 6, 7`                       |

---

### Explanation

1. **`initialize()`**: Resets the entire bit vector (in this case, a `char`) to `0`.
2. **`insert()`**: Adds an element to the set by setting its corresponding bit to `1`. It uses bitwise OR to set the bit.
3. **`delete()`**: Removes an element from the set by setting its corresponding bit to `0`. It inverts the bitmask before applying a bitwise AND.
4. **`find()`**: Checks if an element is present in the set by checking the corresponding bit.
5. **`union()`**: Returns the union of two sets (combined set of elements) using the Bitwise OR operator.
6. **`intersection()`**: Returns the intersection of two sets (common elements) using the Bitwise AND operator.
7. **`difference()`**: Returns the difference between two sets (elements in A but not in B) using A AND (NOT B).
8. **`display()`**: Iterates through all possible elements and displays the ones that are set.

### Notes

- The elements are represented as positions in the bitmask, where each element corresponds to a bit in the byte/integer.
- This method of implementation is compact and efficient, utilizing bitwise operations for set operations.
