# 13. Power of Two

**Easy**  
**Topics**: Math, Bit Manipulation  
**Companies**: Various

## Description

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two if there exists an integer `x` such that `n = 2^x`.

---

## Examples

### Example 1:
**Input:** `n = 1`  
**Output:** `true`  
**Explanation:** `2^0 = 1`

### Example 2:
**Input:** `n = 16`  
**Output:** `true`  
**Explanation:** `2^4 = 16`

### Example 3:
**Input:** `n = 3`  
**Output:** `false`

---

## Constraints

- `-2^31 <= n <= 2^31 - 1`

---

## Solutions

### Approach 1: Bit Manipulation (Recommended)
A power of two in binary has exactly one `1` bit:
- `1` → `1`
- `2` → `10`
- `4` → `100`
- `8` → `1000`

Use the property: `(n > 0) && (n & (n - 1)) == 0`

### Approach 2: Mathematical
Keep dividing by 2 until you reach 1, or use logarithms.

### Approach 3: Iterative
Check if the number can be repeatedly divided by 2 until it becomes 1.

---

## C Implementation

```c
#include <stdbool.h>

// Approach 1: Bit Manipulation (Most Efficient)
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Approach 2: Iterative Division
bool isPowerOfTwo_iterative(int n) {
    if (n <= 0) return false;
    while (n > 1) {
        if (n % 2 != 0) return false;
        n /= 2;
    }
    return true;
}

// Approach 3: Using Logarithms
#include <math.h>
bool isPowerOfTwo_logarithm(int n) {
    if (n <= 0) return false;
    double log2n = log2(n);
    return log2n == floor(log2n);
}