Valid Parentheses
By Zeus Elderfield

DSA
You are tasked to implement a program that checks whether a given string of parentheses is valid. The string may contain the characters:
1. Round brackets: ( and )
2. Square brackets: [ and ]
3. Curly braces: { and }

A string of parentheses is valid if:
1. Every opening bracket has a corresponding closing bracket of the same type.
2. Brackets close in the correct order.

You may use a stack and its helper functions.

Input
- A single string s (length ≤ 256) consisting of characters ()[]{}.

Output
- Print "The parentheses is VALID" if the string is valid.
- Print "The parentheses is NOT VALID" otherwise.