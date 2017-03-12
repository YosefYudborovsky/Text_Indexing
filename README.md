# Text_Indexing: (algorithms & data structures II)
For a given document an online index is created using a binary search tree where each node contains a word and a linked list that contains the line number of the transcript where the word occurs.

The Program:

(a) Creates the index for the document.

(b) Prints the index out in lexicographic order with a count of the number of times a word occurres and a list of each line number that the word is found on (using an inorder traversal to print the tree out).

(c) Prints the total number of tree nodes.

(d) Prints out the height of the tree.

(e) Prints out the word with the maximum number of occurrences and on what line(s) this word occurs.

(f) Interactively requests the user to input a word and returns the number of occurrences of that word (including the line numbers they occur on). A message is printed if the word is not in the index.


The program filters the words based on input to treat upper and lower case the same, remove punctuation marks, and not store numerical data as words. document1.txt as well as document1_short.txt could be used as input file examples.

make all - To compile all sections.

make clean - To remove all *.o and executable files.
