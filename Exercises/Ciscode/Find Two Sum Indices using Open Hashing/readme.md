# Find Two Sum Indices using Open Hashing
## By Cris Lawrence Lucero

### DSA

Given an array of unique integers and a target sum, find the indices of two elements that add up to the target.

## REQUIREMENTS:
- Must run in O(n) linear time
- Must use a DICTIONARY (hash table)
- Must use OPEN HASHING (linked lists for collisions)
- Returns two indices in ASCENDING order
- If found, return the indices; otherwise return NULL

## CONSTRAINTS:
- Exactly TWO NUMBERS add up to the target
- Solution ALWAYS exists
- Input values can be POSITIVE or NEGATIVE integers

## FUNCTIONS:
hash() → hash function<br>
insert() → insert key-value pair<br>
twoSum() → main function to solve problem<br>