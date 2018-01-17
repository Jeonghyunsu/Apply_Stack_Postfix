# Apply_Stack_Postfix [Data Structure]

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

* Notice
   - Use stack template class in STL!
   - You should observe the format of input & output exactly.
   - It should be compiled in Visual Studio 2010 or higher, or g++
