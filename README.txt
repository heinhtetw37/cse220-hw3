CSE 220 Homework3

Name: Hein Htet Win


Project Layout
|__Make File
|__MyBitManipulation.c
|__MyBitManipulation.h
|__Myfloat.c
|__Myfloat.h
|__MyIntegers.c
|__MyIntegers.h
|__tests/
    |__test_bitmanipulation.c
    |__test_float.c
    |__test_integers.c


=============================================
PART I
=============================================
Program Description

MyBitManipulation.c
Contains functions that perform operations directly on the bits of integer values.

1.ToggleBit
Main purpose - To Toggle the bits at assigned positions

How it works:
First I check if pos (position) is a valid bit position between 0 and 31.
If it is not valid, it returns the original number.

In the other case I create a value with a 1 at position pos by using (1<<pos).
Then I take the xor function (^) with num. XOR flips the bit at that position
from 0 to 1 or 1 to 0, and leaves the rest of the bits unchanged.

Example:
ToggleBit(0, 3) returns 8.

---------------------------------------------------------------------------------------

2. GetMSB
Main purpose - finds the position of the most significant bit that is set to 1.

How it works:
If num is 0, the function will return -1 since there is no set bit.

If that is not the case, I convert num to an unsigned int and check all 32 bit positions
from 0 to 31. Wherever a set bit is found, I update pos with its position.
Since the bits are checked from the lowest to the highest position,
the final position stored in pos is the position of the highest significant set bit.

Example:
GetMSB(18) returns 4.

---------------------------------------------------------------------------------------

3. ClearBitRange
Main purpose: clears all bits from start to end, including start and end as well.

How it works:
First, I check the invalidity of the range where if start is less than 0,
or end is greater than 31 or start is greater than the end. If those cases are true,
the original number is returned.

If the range is valid, I create a mask starting with all zeros, where I loop from start
to end and set each bit in that range in the mask to 1

I then use NOT (~) to the flip the mask and AND (&) for num. This
clears the selected bits while keeping the other bits unchanged.

Example:
Clear Bit Range (73, 1, 3): 65

-------------------------------------------------------------------------------------------------

4.RotateLeft
Main purpose: rotates the bits of a 32-bit integer to the left by d positions

Firstly, I used d%32 to reduce the rotation amounts greater than 32.
If d is 0, it will return the original number while preventing a shift by 32 bits.

I switched the num to unsigned int before shifting so that when I shift the bits left
by d positions and shifts another copy right by (32 -d) positions.
This paves to get the bits that need to wrap around.
I combine both parts using OR (|) and return the final result.

Example:
RotateLeft(5,1): 10

-------------------------------------------------------------------------------------------------

5. SwapOddEvenBits
Main purpose: swaps every even-positioned bit with the odd-positioned bit.

How it works:
First I assign the num to an unsigned int.
I use 0x55555555 as a mask for the even-positioned bits and 0xAAAAAAAA as a mask
for the odd-positioned bits.
Even-positioned bits and odd-positioned bits are shifted by one position to the left
and the right respectively.
Finally, I combine both groups using OR (|) and later, return the result

--------------------------------------------------------------------------------------------------
How to Compile

We will use the provided Makefile to compile the project.
Run: make test
The Makefile complies the necessary source files, and also creates the required executable/test files.
-------------------------------------------------------------------------------------------------------
Testing and Results

It uses the Criterion framework while testing and I didn't modify the file.

Also, to compile the code, I used the Makefile which was provided and run the test
by using the Linux terminal to check my implementations.
I used the keyword "make test" in order to execute the tests.
After running the given tests by the professor, Criterion framework will report whether the tests are passed or failed
With no changes made in the Makefile and test files, the program ran 5 times successfully.
No failure was detected.

For my implementations, bitwise operators including AND (&), OR (|), XOR (^), NOT (~),
left shift (<<), and right shift (>>) were used.


===========================================
PART II
===========================================

---------------------------
Main Purpose & Setting Up:
---------------------------
Myfloat.c
Contains functions related to constructing and manipulating floating-point values using their bit representations
and Implements the required floating-point manipulation functions.
Myfloat.h
Contains the function declarations for Myfloat.c

construct_float_sf -> builds an IEEE-754 single-precision (float) value
from its three binary components:

* sign_bit: the sign stored in bit 31
unsigned int sign = ((unsigned int) sign_bit & 0x01);
Binary Form of 0x01 - it's 0000 0001 and it keeps the lowest 1 bit

* exponent: the 8-bit exponent stored in bits 30-23
unsigned int sign = ((unsigned int) exponent & 0xFF);
Binary Form of 0xFF = 1111 1111 and it keeps only the lowest eight bits

* fraction: the 23-bit fraction/mantissa stored bits 22-0
const unsigned int frac = fraction & 0x7FFFFF;
Binary Form of 0x7FFFFF = 0111 1111 1111 1111 1111 1111, and it keeps only the lowest 23 bits
This mask removes any extra bits above 22.

-----------------------------
How does it work and Testing:
-----------------------------

sign = sign << 31;
If sign is 1, it shifts left 31 positions places in the leftmost bit
If sign is 0, all bits will remain zero.

exp = exp << 23;
The exponent shifts left by 23 bits ending up in moving bits 30 through 23
which is required to get IEEE-754 position

Combining sign, exponent, and fraction
f = sign | exp | frac
The bitwise OR operator combines the three fields into f. Each field uses separate bit positions
-sign bit uses 31
-exponent uses bits 30-23
-fraction uses bits 22-0

Reinterpreting the bits as a float
return * (float *)&f;
Regardless of f being an unsigned int, it now contains a bit pattern arranged like an IEEE-754 float.
This line transitions the same 32 bits as a float and returns the final floating-point number.

------------------------------------
Results
------------------------------------
The function makes each input to the correct size and shifts the sign and exponent
into their IEEE-754 positions which combine all three fields with bitwise OR.
Finally, it treats the completed 32-bit patten as a float (IEEE-754).

It uses the Criterion framework while testing and I didn't modify the file.

Also, to compile the code, I used the Makefile which was provided and run the test
by using the Linux terminal to check my implementations.
I used the keyword "make test" in order to execute the tests.
After running the given tests by the professor, Criterion framework will report whether the tests are passed or failed
With no changes made in the Makefile and test files, the program ran 10 times successfully.
No failure was detected.



=======================================================================
PART III
=======================================================================
----------------------------------------------------------------
Main Purpose & Setting Up
----------------------------------------------------------------
Overview,
MyIntegers.c
Contains functions for converting between sign-magnitude and two's complement integer representations
Implements conversions between sign-magnitude and two's complement integer representation
MyIntegers.h
contains the declaration functions for MyIntegers.c
repr_convert() -> converts a 32-bit integer representation between:
'S' - Sign Magnitude and '2' - Two's Complement

-----------------------------
How does it work and Testing:
-----------------------------

The function uses bitwise operations to examine the sign bit and magnitude of the given value.
It converts the magnitude into the proper two's complement representation
for negative sign-magnitude values.
For negative two's complement values, it computes the magnitude
and sets the sign bit so that the sign-magnitude representation is produced.

Positive values tend to have the same bit pattern when converting between the two representations.
The function also handles special cases required by the assignment.

-------------------
Results
------------------
Sign-magnitude negative zero (0x80000000) is converted to positive zero(0x00000000).
The two's complement value 0x80000000 represents -2147483648, which cannot be represented using 32-bit sign-magnitude, so
the function prints "undefined".

If an invalid representation type is provided, such as a character other
than 'S' or '2', the function prints "error".

The final converted value is printed as an 8-digit hexadecimal value.

It uses the Criterion framework while testing and I didn't modify the file.

Also, to compile the code, I used the Makefile which was provided and run the test
by using the Linux terminal to check my implementations.
I used the keyword "make test" in order to execute the tests.
After running the given tests by the professor, Criterion framework will report whether the tests are passed or failed
With no changes made in the Makefile and test files, the program ran 11 times successfully.
No failure was detected.


----------------------------
Notes
----------------------------
- Implementation assumes 32-bit integer values as required by assignment.

- Bit positions are numbered from 0, where bit 0 is the least significant bit.

- Properly manages invalid inputs based on the specifications given in the assignment.

- Special cases such as positive/negative zero and those values that cannot be represented in the destination format are handled as specified in the assignment for the integer representation conversion.
- Before submitting, the program should be tested with the Criterion tests provided.