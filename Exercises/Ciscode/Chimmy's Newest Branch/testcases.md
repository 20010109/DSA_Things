------ Test case #1 ------
Expected Output:
======= Current Queue =======

Customer: Alice      | Order Count: 2
    - Mango Yogurt
    - Original Yogurt
------------------------------------
Customer: Bob        | Order Count: 1
    - Original Yogurt
------------------------------------
Customer: Charlie    | Order Count: 3
    - Chocolate Yogurt
    - Banana Yogurt
    - Mango Yogurt
------------------------------------
Customer: Diana      | Order Count: 1
    - Mango Graham Yogurt
------------------------------------
Customer: Evan       | Order Count: 2
    - Ube Yogurt
    - Avocado Yogurt
------------------------------------

Dequeuing customer Alice
Dequeuing customer Bob

======= Current Queue =======

Customer: Charlie    | Order Count: 3
    - Chocolate Yogurt
    - Banana Yogurt
    - Mango Yogurt
------------------------------------
Customer: Diana      | Order Count: 1
    - Mango Graham Yogurt
------------------------------------
Customer: Evan       | Order Count: 2
    - Ube Yogurt
    - Avocado Yogurt
------------------------------------