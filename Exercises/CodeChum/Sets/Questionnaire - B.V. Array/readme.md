# 🧮 Questionnaire - B.V. Array
### by *Janie Lane Sabado*

---

### 📘 Overview
You are designing a system to record and compare responses to a 10-question yes/no personality quiz.  
Each answer is either **1 (yes)** or **0 (no)**.  
Use an array of `char` to store each answer.

---

## 🧠 Implement the following functions:

- `void setAnswer(BitVect* profile, int index, int value)`<br>
Set the answer to 1 or 0 for a given question index.

- `int getAnswer(BitVect profile, int index)`<br>
Retrieve the answer for a given question index.

- `int countYesAnswers(BitVect profile)`<br>
Count how many answers are 1.

- `void printAnswers(BitVect profile)`<br>
Print all answers as a binary string.

- `int compareProfiles(BitVect a, BitVect b)`<br>
Compares how many matching answers the two respondents have.

- `BitVect unionProfiles(BitVect a, BitVect b)`<br>
Returns a new set containing all of the **yes** answers from both profiles.

- `BitVect intersectProfiles(BitVect a, BitVect b)`<br>
Returns a new set containing all of the **common yes** answers from both profiles.

- `BitVect differenceProfilesWord(BitVect a, BitVect b)`<br>
Returns a new set containing the **yes** answers from `a` and the **common answers** they have with `b`.

---

## 🧾 Sample Output 1

```plaintext
Inie's answers: 0100101011
Jobo's answers: 0011110101

Matching answers: 3
Jobo answered yes to question 1
Jobo answered no to question 2
Inie said yes to 5 questions

Union: 0111111111
Intersection: 0000100001
Difference: 01000001010
```

---

### 💡 Notes
- Use **bitwise operations** and array manipulation where possible.
- Maintain consistent binary string formatting when printing results.

---

