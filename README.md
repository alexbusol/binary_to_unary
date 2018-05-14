# binary_to_unary
Binary to unary converter takes in a string of ASCII characters. It then converts it to binary and returns a int vector holding that number. 
The binary number is then converted to unary code using the following rules:
  1. The output is printed in blocks of 0s separated by spaces
  2. If the block contains 1s, a 0 is printed before the next block that has the number of 0s corresponding to the number of 1s in the          binary number.
  3. If the block contains 0s, a 00 is printed before the next block that has the number of 0s corresponding to the number of 0s in the
     binary number.
     
  So, if the binary value is 110001, the unary code generated is 0 00 00 000 0 0

This is a solution to the CodingGame Chuck Norris puzzle.
