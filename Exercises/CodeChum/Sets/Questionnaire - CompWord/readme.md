# 🧠 Questionnaire - CompWord  
**by Janie Lane Sabado**

---

## 📘 Description  
You are designing a system to record and compare responses to a **10-question yes/no personality quiz**.  
Each answer is either **1 (yes)** or **0 (no)**.  
Use a **single short int** to store all 10 answers as bits.

---

## ⚙️ Functions to Implement  

- `void setAnswer(CompWord* profile, int index, int value)`  
Set the answer to **1 or 0** for a given question index.

- `int getAnswer(CompWord profile, int index)`  
Retrieve the answer for a given question index.

- `int countYesAnswers(CompWord profile)`  
Count how many answers are **1**.

- `void printAnswers(CompWord profile)`  
Print all answers as a **binary string**.

- `int compareProfiles(CompWord a, CompWord b)`  
Compare how many **matching answers** the two respondents have.

- `CompWord unionProfiles(CompWord a, CompWord b)`  
Return a new set containing **all of the yes answers** from both profiles.

- `CompWord intersectProfiles(CompWord a, CompWord b)`  
Return a new set containing **all of the common yes answers** from both profiles.

- `CompWord differenceProfiles(CompWord a, CompWord b)`  
Return a new set containing the **yes answers from a** and the **common answers they have with b**.

---

## 🖥️ Sample Output 1  

```plaintext
Inie's answers: 0100101011
Jobo's answers: 0011110101

Matching answers: 3
Jobo answered yes to question 1
Jobo answered no to question 2
Inie said yes to 5 questions

Union: 0111111111
Intersection: 0000100001
Difference: 0100001010
```

---

## 💡 Summary  
This activity demonstrates **bitwise manipulation** and how to efficiently store and compare boolean data using bit operations such as:  
`<<`, `>>`, `&`, `|`, `^`, and `~`.  

Each bit in the short integer corresponds to one question, making the system memory-efficient and fast for comparison tasks.

