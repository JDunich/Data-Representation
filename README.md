# Data-Representation #

## Overview ##

This is a project from Rutgers Computer Science 01:198:211:05-08 COMPUTER ARCHITECTURE class taught by Prof. Santosh Nagarakatte. For this program, we were instucted to manipulate binary and hexadecimal numbers in C to better understand how data is represented inside a coding language. The project description can be seen below:

 ### Introduction ###
In this assignment, you will improve your understanding of data representation by writing C programs. Your program must follow the input-output guidelines listed in each section *exactly*, with no additional or missing output.

No cheating or copying will be tolerated in this class. Your assignments will be automatically
checked with plagiarism detection tools that are powerful. Hence, you should not look at your
friend’s code or use any code from the Internet or other sources such as Chegg/Freelancer. All
violations will be reported to office of student conduct. See Rutgers academic integrity policy at:
http://academicintegrity.rutgers.edu/

### First: Conversion to Unsigned Binary Representation (20 Points) ###

In this part, your task is to write a C program that prints the unsigned binary representation of
a number with a specific number of bits. The argument to the program is an input file, whose
format is described in the input format. If a given number is representable with a given number of
bits (w), then you should print the binary representation of the number. Otherwise, you print the
binary representation of the remainder when divided by 2w.

*Input-Output format:* Your program will take one file name as its command-line input. Each
line in the input file will have two positive integers separated by a space: an integer that you
want to represent in binary and the number of bits to use for the representation. For each line
in the input, you should print out the binary representation of the number followed by a newline
character.

Example Execution:

Let’s assume we have the following input file:

input.txt <br />
42 12 <br />
27 3 <br />

Then the result will be:

$./first input.text

000000101010 <br />
011 <br />

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.

### Second: Conversion to Two’s Complement Binary (30 points) ###

In this part, your task is to write a C program that prints the two’s complement binary representation of a number with a specific number of bits. The argument to the program is an input file,
whose format is described in the input format. If a given number is not representable with a given
number of bits because the number is greater than largest positive value possible with the given
number of bits, then you should print the representation for the largest positive value with the given
number of bits in the two’s complement representation. If a given number is not representable with
a given number of bits because is smaller than smallest negative value with the given number of
bits, then you should print the representation for the smallest negative with the given number of
bits in the two’s complement representation.

Input-Output format: Your program will take one file name as its command-line input. Each
line in the input file will have two integers separated by a space: an integer that you want to
represent in binary and the number of bits to use for the representation. For each line in the input,
you should print out the binary representation of the number followed by a newline character.

Example Execution:

Let’s assume we have the following input file:

input.txt <br />
42 7 <br />
16 4 <br />
-9 4 <br />

Then the result will be:

$./first input.text <br />
0101010 <br />
0111 <br />
1000 <br />

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.

### Third: Effect of Signed/Unsigned Casts (10 points) ###

In this part, your task is to write a C program that prints value of the number when it is cast from
a unsigned number to a signed number and vice-versa. The argument to the program is an input
file, whose format is described in the input format.

Input-Output format: Your program will take one file name as its command-line input. Each
line in the input file will have two integers and two characters separated by a space: an integer that
is being represented, the number of bits to use for the representation, the source representation and
the destination representation. Here, u is unsigned representation and s is in signed representation.
For each line in the input, you should print out the value of the number (in decimal) in the
destination representation followed by a newline character.

You can assume that the unsigned value of the number is representable with the given number of
bits.

Example Execution:

Let’s assume we have the following input file:

input.txt <br />
7 3 u s <br />
-2 4 s u <br />

Then the result will be:

$./first input.text <br />
-1 <br />
14 <br />
We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.

### Fourth: Decimal Fraction to Canonical Binary Fraction (30 points) ###

You will write a program to convert a decimal fraction to a binary fraction in the canonical representation (i.e., (−1)s × M × 2
E). For this program, M lies between (1, 2). You do not have to
perform any rounding for this part. You are required to print as many digits after the decimal
point as specified by the input.

Input-Output format: Your program will take one file name as its command-line input. Each
line in the input file will have a decimal fraction (use a double type to read it) and the number of
bits to show in the canonical binary representation separate by space. For each line in the input,
you should print the M value and E value in the canonical representation separated by space. Add
a newline character after printing the output for each input.

Example Execution:

Let’s assume we have the following input file:

input.txt <br />
6.25 6 <br />
12.5 3 <br />

Then the result will be:

$./first input.text <br />
1.100100 2 <br />
1.100 3 <br />

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above. Further, we will provide only positive fractions for this part of the
assignment (i.e., no negative numbers).

### Fifth: Decimal to IEEE-FP with Rounding (40 points) ###

Your task is to write a program to convert a decimal fraction to IEEE-754 FP representation in a
given configuration with the rounding to nearest with ties-to-even rounding mode.

Input-Output format: Your program will take one file name as its command-line input. Each
line in the input file will have a decimal fraction (use a double type to read it), the number of
the bits (n) in the IEEE-754 FP representation, number of bits for the exponent, and number of
fraction bits. These numbers on a given line are separated by a space. For each line in the input,
you should the IEEE-754 representation with n-bits followed by a new line.

Example Execution:

Let’s assume we have the following input file:

input.txt <br />
6.5 8 4 3 <br />
.0546875 8 4 3 <br />
.013671875 8 4 3 <br />
6.375 8 4 3 <br />
8.5 8 4 3 <br />
9.5 8 4 3 <br />

Then the result will be:

$./first input.text <br />
01001101 <br />
00010110 <br />
00000111 <br />
01001101 <br />
01010000 <br />
01010010 <br />

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above. You can assume that input will not have NaNs and any value will
not round up or down to infinities.

### Sixth: Hexadecimal Bit-pattern in the IEEE-FP Format to Decimal Fraction (20 points) ###

Your task is to write a program that takes a hexadecimal bit-pattern and prints the decimal
fractional value of the number.

Input-Output format: Your program will take one file name as its command-line input. Each
line in the input file will have the total number of bits, the number of bits for the exponent,
number of bits for the fraction, the hexadecimal bit-pattern, and the number of precision bits after
the decimal point in the decimal fraction. These numbers on a given line are separated by a space.
For each line in the input, you should print out the decimal fraction value with the specified number
of precision bits followed by a new line.

Example Execution:

Let’s assume we have the following input file:

input.txt <br />
8 4 3 0x4d 2 <br />
8 4 3 0x16 7 <br />

Then the result will be:

$./first input.text <br />
6.50 <br />
.0546875 <br />

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.
