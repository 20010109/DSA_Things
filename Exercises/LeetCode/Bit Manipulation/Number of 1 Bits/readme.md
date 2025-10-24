# 10. Number of 1 Bits

**Easy**  
**Topics**: Bit Manipulation  
**Companies**: Various

## Description

Given a positive integer `n`, write a function that returns the number of set bits (1s) in its binary representation. This is also known as the **Hamming weight**.

---

## Examples

### Example 1:
**Input:** `n = 11`  
**Output:** `3`  
**Explanation:**  
The binary representation of 11 is `1011`, which contains **three** set bits.

### Example 2:
**Input:** `n = 128`  
**Output:** `1`  
**Explanation:**  
The binary representation of 128 is `10000000`, which contains **one** set bit.

### Example 3:
**Input:** `n = 2147483645`  
**Output:** `30`  
**Explanation:**  
The binary representation of 2147483645 is `1111111111111111111111111111101`, which contains **thirty** set bits.

---

## Constraints

- The input will be a positive integer
- The solution should efficiently count the number of 1 bits

---

## Solutions

Common approaches include:
- Bit manipulation using `n & (n - 1)` to clear the lowest set bit
- Right-shifting and checking the least significant bit
- Built-in functions in various programming languages

---

## Tags

`Bit Manipulation`, `Easy`, `Hamming Weight`