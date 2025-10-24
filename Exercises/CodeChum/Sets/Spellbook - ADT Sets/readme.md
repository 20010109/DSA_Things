# 🧙 Spellbook – ADT Sets  
**By Edwin Bartlett**

## 🎯 Objective  
Implement an **Abstract Data Type (ADT)** for **sets of strings in C** to manage a wizard’s spellbook.  
Each spell is unique, and the spellbook must support standard set operations.  

> 💡 **Implementation detail:** The ADT uses a **linked list** structure.

---

## ⚙️ Program Overview  
Create a C program that defines and uses a `Set` ADT with the following operations:

### 🧩 Core Functions

| Function | Description |
|-----------|--------------|
| `Set* createSet()` | Initializes an empty set. |
| `bool addSpell(Set*, const char*)` | Adds a spell to the set (no duplicates allowed). |
| `bool removeSpell(Set**, const char*)` | Removes a spell from the set. |
| `bool containsSpell(Set*, const char*)` | Checks if a spell exists in the set. |
| `void printSet(Set*)` | Displays all spells in the set. |
| `void destroySet(Set* set)` | Frees all memory associated with the set. |

---

### 🔮 Set Operations

| Function | Description |
|-----------|--------------|
| `Set* unionSets(Set*, Set*)` | Returns a new set containing all spells from both sets. |
| `Set* intersectSets(Set*, Set*)` | Returns a new set containing only common spells from both sets. |

---

## 🧰 Implementation Notes
- The **Set ADT** must use a **linked list** to store strings.  
- Each spell should be unique (no duplicates).  
- All dynamically allocated memory must be properly freed.  

---

## 🧪 Example Usage
```c
Set* fireSpells = createSet();
Set* waterSpells = createSet();

addSpell(fireSpells, "Flame Burst");
addSpell(fireSpells, "Inferno");
addSpell(waterSpells, "Aqua Shield");
addSpell(waterSpells, "Inferno");

printf("Fire Spells:\n");
printSet(fireSpells);

printf("Water Spells:\n");
printSet(waterSpells);

Set* sharedSpells = intersectSets(fireSpells, waterSpells);
printf("Common Spells:\n");
printSet(sharedSpells);

destroySet(fireSpells);
destroySet(waterSpells);
destroySet(sharedSpells);
```

## ⚒️ Compilation & Execution
To compile and run the program:
```bash
gcc main.c set.c -o spellbook
./spellbook
```