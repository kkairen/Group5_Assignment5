# GROUP 5 FINAL ASSIGNMENT

Assignment 5: Problems 2 & 7
P8.2
Write a program that checks the spelling of all words in a file. It should read each word of a file and check whether it is contained in a word list. A word list is available on most UNIX systems (including Linux and Mac OS X) in the file /usr/share/dict/words. (If you don’t have access to a UNIX system, you can find a copy of the file on the Internet by searching for /usr/share/dict/words.) The program should print out all words that it cannot find in the word list. Follow this pseudocode:
Open the dictionary file.

Define a vector of strings called words.

For each word in the dictionary file

   Append the word to the words vector.

Open the file to be checked.

For each word in that file

   If the word is not contained in the words vector

      Print the word.


P8.7
Random monoalphabet cipher. The Caesar cipher, which shifts all letters by a fixed amount, is far too easy to crack. Here is a better idea. As the key, don’t use numbers but words. Suppose the key word is FEATHER. Then first remove duplicate letters, yielding FEATHR, and append the other letters of the alphabet in reverse order:
 ‘F-E-A-T-H-R-Z-Y-X-W-V-U-S-Q-P-O-M-N-L-K-J-I-C-G-O-B-V,’

Now encrypt the letters as follows:
F, E, A, T, H, R, Z, Y, X, M, V, U, S, O, P, R, O, N, L, M, K, J, I, G, D, C, Q, V, B. 

Write a program that encrypts or decrypts a file using this cipher. For example,

crypt -d -kFEATHER encrypt.txt output.txt

decrypts a file using the keyword FEATHER. It is an error not to supply a keyword.
