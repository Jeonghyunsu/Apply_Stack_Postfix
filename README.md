# Apply_Stack_Postfix

* Write a C++ program that inputs numerical expressions line by line and then outputs their results. “EOI\n” means the end of input.
   - Only ‘a’, ‘b’, ‘c’ can be input as operands.
   - Only 3 binary operators can be used as operators:
     - ‘@’, ‘#’, and ‘&’
      - ‘&’ has higher precedence than ‘@’ and ‘#’.
      - Consecutive operations with the same precedence must be computed from left.
   - The result is always ‘a’, ‘b’, or ‘c’.
   - Operation table is given as a text file named “operations.txt”
      - See the next slide for an example.
   - When exceptions such as unbalanced parenthesis (or brace, bracket) occur, print “Error!\n” and process next input lines.

* Input File (operations.txt), which can be modified when your code is tested.

(example)
@
a b c 
b c a 
c a b 
#
a c b 
b a c 
c b a 
&
a a a 
a b c 
a c b 

* Input
(a@b#c)&b
(b#c)}&(a#b@b)
{c#b@(a@a&b)}@(a#a)
(a&b#(a@c@b))#[(c&b)@{c&a#c}@b]
EOI

* Output
c
Error!
b
c

* Notice
   - Use stack template class in STL!
   - You should observe the format of input & output exactly.
   - It should be compiled in Visual Studio 2010 or higher, or g++



# Apply_Stack_Postfix
