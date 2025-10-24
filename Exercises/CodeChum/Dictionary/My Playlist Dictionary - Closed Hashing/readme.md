# 🎵 My Playlist Dictionary - Closed Hashing
**by Janie Lane Sabado**

---

## 📘 Problem Statement
Create a C program that inserts, deletes, and searches the song genre in a **closed hashing dictionary** using a **cursor-based implementation**.

You are required to write the following functions inside **`cldi.c`**.  
The **main function** and **struct definitions** are already provided.

### ✳️ Required Functions
- **`hash(genre)`** – Accepts the genre of the song, compares the string to the elements of the `genreTable`, and returns the correct index.
- **`insert(Song)`** – Uses the hash function to insert a new `Song` into the playlist at its proper place.  
  Any collisions will be placed at the end of its corresponding hashed list.
- **`deleteMember(Song)`** – Uses the hash function to delete a given `Song` in the playlist.
- **`search(Song)`** – Uses the hash function to search the dictionary if a given `Song` exists in the playlist.

---

## 💡 Tips

### `initDict(VirtualHeap *VH)`
- This function is already given.
- It initializes the primary storage to be empty by assigning the `elem.genre` to **"Empty"**.

---

### `hash(String genre)`
- Compare the string `genre` to the elements of the given `genreTable`.
- Use the string function `strcmp()`.

---

### `insert(VirtualHeap *VH, Song song)`
- Use the hash function to receive the proper index for the specified genre.
- If the given index genre is `"Empty"` or `"Deleted"`, insert it as is.
- Else, the song must be appropriately inserted into the **secondary storage**, at the end of the given genre list.

---

### `deleteMember(VirtualHeap *VH, Song song)`
- Use the hash function to receive the proper index for the specified genre.
- If the given index genre is the song to be deleted, update the list appropriately.
- Else, the song must be appropriately deleted from the secondary storage,  
  updating the variable **`avail`** in the `VirtualHeap`.

---

### `search(VirtualHeap VH, Song song)`
- Use the hash function to receive the proper index for the specified genre.
- Traverse through the secondary storage if necessary.
- **Return 1** if the song exists in the playlist.  
- **Return 0** if the song does not exist in the playlist.

---

## 🧾 Sample Output

Sample Output 1
```plaintext

Playlist of Janie Sabado
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Ndx                        Song Name   Singer            Genre
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    1.                Someone Like You - Adele           | Ballad
                     Thinking Out Loud - Ed Sheeran      | Ballad

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    2.                Yellow Submarine - Beatles         | Pop Rock
                        Mr. Brightside - The Killers     | Pop Rock

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    3.                 Training Season - Dua Lipa        | Pop
             This is What You Came For - Calvin Harris   | Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    4.                        Doo Wop' - Lauryn Hill     | R&B

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    5.                             --- - ---             | ---

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    6.                      Love Story - Taylor Swift    | Country Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    7.                          Kirari - Fuji Kaze       | J-Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    8.                   Rock with you - SEVENTEEN       | K-Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    9.                  Symphony no. 8 - Beethoven       | Classical

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   10.                 Defying Gravity - Wicked          | Theater

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   11.                           Alone - Marshmello      | EDM

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   12.                           Buwan - Juan Karlos     | OPM

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   13.                             --- - ---             | ---

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   14.                   Let's go back - Jungle          | Dance
                            Back on 74 - Jungle          | Dance
                           NO PROBLEMZ - Jungle          | Dance

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   15.                            Sway - Michael Buble   | Jazz
                  Where is my Husband? - Raye            | Jazz
                    Fly me to the moon - Frank Sinatra   | Jazz

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   16.                             --- - ---             | ---

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

The song "Everynight" does not exist in my playlist
The song "Fly me to the moon" exists in my playlist

Deleting song Fly me to the moon
Deleting song Training Season

Inserting song Everynight
Playlist of Janie Sabado
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Ndx                        Song Name   Singer            Genre
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    1.                Someone Like You - Adele           | Ballad
                     Thinking Out Loud - Ed Sheeran      | Ballad

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    2.                Yellow Submarine - Beatles         | Pop Rock
                        Mr. Brightside - The Killers     | Pop Rock

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    3.       This is What You Came For - Calvin Harris   | Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    4.                        Doo Wop' - Lauryn Hill     | R&B

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    5.                             --- - ---             | ---

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    6.                      Love Story - Taylor Swift    | Country Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    7.                          Kirari - Fuji Kaze       | J-Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    8.                   Rock with you - SEVENTEEN       | K-Pop

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    9.                  Symphony no. 8 - Beethoven       | Classical

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   10.                 Defying Gravity - Wicked          | Theater

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   11.                           Alone - Marshmello      | EDM

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   12.                           Buwan - Juan Karlos     | OPM

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   13.                             --- - ---             | ---

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   14.                   Let's go back - Jungle          | Dance
                            Back on 74 - Jungle          | Dance
                           NO PROBLEMZ - Jungle          | Dance
                            Everynight - Jungle          | Dance

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   15.                            Sway - Michael Buble   | Jazz
                  Where is my Husband? - Raye            | Jazz

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   16.                             --- - ---             | ---

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
```
