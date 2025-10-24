Fix it! WALL-E!
By Cliff Jharel Jao

DSA
Infix and Postfix Expressions are two common ways of writing arithmetic operations. Infix expressions are the standard mathematical form where the operator is placed between the operands. On the other hand, postfix expressions places the operator after the operands, such as "AB+" or "AB+C*". Concept-wise, humans prefer Infix while computers prefer Postfix. (Research more about them if description is vague)

Suppose you have a computer friend, WALL-E, capable of revitalizing an entire planet with sufficient instructions. However, WALL-E can only comprehend Postfix notations which is out of your scope of knowledge.

To solve this, given a mathematical infix expression, you are to create a function that converts it into a postfix expression using an Array-Stack Implementation. The function should return a stack that already contains the postfix expression in its elemental array.

ASSUME and LIMITATIONS:
1. Valid Operators -> (+, -, /, *, ^)
2. Valid Operands are only single digits (0-9)

NOTE ON HELPER FUNCTIONS!
1. findPrecedence()
- There is no way of identifying an operator's precedence if it is of data type char. This function will help in identifying that operator's precedence.
2. Stack Operation Functions
- Utilize these to implement stack operations for efficiency

SAVE WALL-E!