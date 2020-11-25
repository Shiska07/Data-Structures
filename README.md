# Data_Structures

This program uses the edit distance algorithm to find the letter-wise differences between two words.
It allows the user to read in a file containing dictionary works for comparison and another testfile containing words one wants to test.
For every word in the test file, it gives four most similar words present in the dictionary file.
Sample dictionary file and word file are provided. 

SAMPLE RUN:
student@cse1325:/media/sf_CPP_Shared/edit_distance$ ./edit_distance
Repeatedly enter two words separated by a space (e.g.: cat someone).
 Stop with: -1 -1
camel malla

 first: camel
second: malla
    |    |   m|   a|   l|   l|   a|
-----------------------------------
    |   0|   1|   2|   3|   4|   5|
-----------------------------------
   c|   1|   1|   2|   3|   4|   5|
-----------------------------------
   a|   2|   2|   1|   2|   3|   4|
-----------------------------------
   m|   3|   2|   2|   2|   3|   4|
-----------------------------------
   e|   4|   3|   3|   3|   3|   4|
-----------------------------------
   l|   5|   4|   4|   3|   3|   4|
-----------------------------------
edit distance: 4

===========================================================================
how cow

 first: how
second: cow
    |    |   c|   o|   w|
-------------------------
    |   0|   1|   2|   3|
-------------------------
   h|   1|   1|   2|   3|
-------------------------
   o|   2|   2|   1|   2|
-------------------------
   w|   3|   3|   2|   1|
-------------------------
edit distance: 1

===========================================================================
hello yellow

 first: hello
second: yellow
    |    |   y|   e|   l|   l|   o|   w|
----------------------------------------
    |   0|   1|   2|   3|   4|   5|   6|
----------------------------------------
   h|   1|   1|   2|   3|   4|   5|   6|
----------------------------------------
   e|   2|   2|   1|   2|   3|   4|   5|
----------------------------------------
   l|   3|   3|   2|   1|   2|   3|   4|
----------------------------------------
   l|   4|   4|   3|   2|   1|   2|   3|
----------------------------------------
   o|   5|   5|   4|   3|   2|   1|   2|
----------------------------------------
edit distance: 2

===========================================================================
-1 -1

 first: -1
second: -1
Enter the dictionary file name: dictionary1.txt 
Enter the test file name: test1.txt
------- Current test word: oter
Minimum distance: 1 
Words that give minimum distance:
other
over

------- Current test word: sentnse
Minimum distance: 2 
Words that give minimum distance:
sentence
sense

------- Current test word: teh
Minimum distance: 1 
Words that give minimum distance:
ten

------- Current test word: Jason
Minimum distance: 2 
Words that give minimum distance:
reason
son
season

------- Current test word: cavt
Minimum distance: 1 
Words that give minimum distance:
cart
cat
cave
cast
