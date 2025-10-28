# The 8-Lane Subway Track, Meets A Surfer  
**By Nino Calinog**

---

### Categories:
`DSA`

---

## Story

You are a surfer. You were minding your business, *“LEGALLY”* Graffiting a cool design on a subway track, then suddenly you hear a loud whistle and a dog barking.  
In your peripheral vision, you see a misunderstood policeman and his pitbull terrier running in your direction.  
The policeman didn’t know you had been permitted to decorate the subway walls, and the anger on the face of the policeman suggests that he is ready to be violent.

As if your body moved on its own, you bolt in the opposite direction from where the policeman is running.  
But after a few meters of running, you are greeted with **7 inactive trains**, blocking the way for all except one track.  
You then noticed that after those 7 trains, there are even more trains blocking the tracks. You are to navigate your way out of the subway to ask for help before the policeman beats you up.

---

## Problem Setup

There are **5 sets of trains** that you have to go through, and each set will look like this:
```plaintext
1 1 1 1 0 1 1 1
```
Where:  
- `1` = train  
- `0` = no train  

You, the surfer, will start from the very left side, looking like this:
```plaintext
1 0 0 0 0 0 0 0
```

---

## TASK

You are going to design an **algorithm** that will find the right path and shift yourself to dodge the trains and escape.  
The function for your algorithm will return an array of integers determining the number of shifts.

Positive means you shift to the right, while negative means you shift to the left.

---

## Example

### You:
```plaintext
1 0 0 0 0 0 0 0 <--- You
```

### Train Sets:
```plaintext
1 1 1 1 0 1 1 1 <--- 1st set
1 0 1 1 1 1 1 1 <--- 2nd set
1 1 1 0 1 1 1 1 <--- 3rd set
1 1 1 1 1 1 0 1 <--- 4th set
1 1 1 1 0 1 1 1 <--- 5th set
```