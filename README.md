# English---Dothraki-Dictionary

In this experiment, you are expected to write an application that constructs an Dothraki-English
dictionary with Trie data structure. The application will take the input.txt file from command
line and read its contents. There are some commands for this experiment such as adding, deleting
and listing. Your task is implement these features with min time and space costs.
Structure of Commands:
• insert(k,v): should insert a key-value pair (k, v) into the trie; if the key k already existed
the corresponding value should be replaced with v. Key corresponds to Dothraki word and
value corresponds to English word.
• search(k): search with the given key and return the value
• delete(k): delete the key and its value
• list: should return a printable representation of the trie with keys sorted lexicographically


Insert command: insert(k,v)
• The application will read the given Dothraki word (k) character by character and add them
to the tree. With the last character of the Dothraki word store the English equivalent (v)
of that word.
• If the first character of the Dothraki word (k) is not referenced by the root node, the word
will be added to the tree starting from the root node.
• If the first n character of the Dothraki word (k) exists on the tree, a branch occurs on the
nth node for the last characters
• The node which is the last character of the Dothraki word has to hold the English equivalent
for the given Dothraki word. If there is a Dothraki word same as the given word (k) and their values (v) are also same,
the application will give an output that “xxx already exist”. If the key k already existed and
values are different, then the corresponding value should be replaced with v and "xxx was
updated".


Search command: search(k)
• The application will read the given Dothraki word (k) and according to the questioned word
it will return an information.
• If the first character of the k is not referenced by the root node, the application will give an
output that “no record”.
• If the first n character of the k exists on the tree, but the remainder is not, the application
will give an output that “incorrect Dothraki word”.
• If all characters of the k exist on the tree, but the last character has no English equivalent,
the application will give an output that “not enough Dothraki word”.
• If all characters of the k exist on the tree and the last character has its English equivalent,
the application will give an output that “The English equivalent is xxx”.


Delete command: delete(k)
• With the given k, the application will delete the key and its value from the tree.
Page 3 of 7Fall 2021
BBM 203: Data Structures Lab.
• If the first character of the k is not referenced by the root node, the application will give an
output that “no record”.
• If the first n character of the k exists on the tree, but the remainder is not, the application
will give an output that “incorrect Dothraki word”.
• If all characters of the k exist on the tree, but the last character has no English equivalent,
the application will give an output that “not enough Dothraki word”.
• If all characters of the k exist on the tree, and the last character has the English equivalent,
the application will delete all nodes which are not connected to another Dothraki word.
Then it will give an output that “xxx deletion is successful”.


List command: list
• The application will list the all Dothraki words with their values by preorder traversal.
• After the first level of the tree, each branch will be displayed with a new tab. If there is no
branch, no need a new tab. If a branch have different values, you can display with one tab.
Following example is given for this case (Only output of list command is shown).
insert(at,one)
insert(atak,first)
insert(ataki,first)
insert(ale,some)
list
-a
--->
-ale(some)
-at(one)
-atak(first)
-ataki(first)


Inputs and Outputs
For this assignment you have one input file that contains commands. You are expected to produce
output.txt file according to input.txt file. The format of input and output files are shown below.
The input.txt file of the example given in Figures above is as follows.
insert(achra,smelly)
insert(adra,turtle)
insert(gaezo,brother)
insert(kemak,spouse)
insert(kem,married)
insert(kemik,ally)
insert(gaezo,brother)
search(mekis)
search(adra)
search(gaez)
search(kemok)
search(kemak)
search(kem)
list
delete(ach)
delete(adra)
delete(oqo)
delete(kem)
delete(gaizo)
delete(kem)
list
The output of this assignment which are created according to the input.txt file should be as shown
below. Please create your output file according to the format given to you.
"achra" was added
"adra" was added
"gaezo" was added
"kemak" was added
"kem" was added
"kemik" was added
"gaezo" already exist
"no record"
"The English equivalent is turtle"
"not enough Dothraki word"
"incorrect Dothraki word"
"The English equivalent is spouse"
"The English equivalent is married"
-a
-achra(smelly)
-adra(turtle)
-gaezo(brother)
-kem(married)
-kemak(spouse)
-kemik(ally)
"not enough Dothraki word"
"adra" deletion is successful
"no record"
"kem" deletion is successful
"incorrect Dothraki word"
"no record"
-achra(smelly)
-gaezo(brother)
-kem
-kemak(spouse)
-kemik(ally)





