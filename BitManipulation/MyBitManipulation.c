#include "MyBitManipulation.h"


/*
 * Toggle the bit at position pos.
 *
 * Example:
 * ToggleBit(0,3) -> 8
 *
 * Return original number if pos is invalid.
 */
int ToggleBit(int num, int pos)
{
    if (pos < 0 || pos > 31) { //check whether the position is valid or not
        return num; //if not valid return the original number
    }

    else return num ^ (1 << pos); //toggle the 1 bit at position pos and return the new number
}


/*
 * Return the position of the most significant bit.
 *
 * Example:
 * GetMSB(8) -> 3
 *
 * Return -1 for zero.
 */
int GetMSB(int num)
{

    if (num == 0) {
        return -1;
    } //if the number is zero return -1

    unsigned int u = (unsigned int)num; //copies the same 32-bit bit pattern form num
    int pos = -1;

    for (int i = 0; i < 32; i++) {
        if (u & (1 << i)) { //check whether the bit at position i is set or not
            pos = i; //if the bit is set update the position
        }
    }
    return pos;
}


/*
 * Clear bits from start to end (inclusive).
 *
 * Example:
 * ClearBitRange(0xffffffff, 0, 7)
 * returns 0xffffff00
 *
 * Hint: if start is 0 and end is 31 you are clearing every bit in a
 * 32 bit value. A mask built as (1u << (end - start + 1)) - 1 needs a
 * shift by 32 in that case, and shifting a 32 bit type by 32 is
 * undefined behavior in C, it is not guaranteed to give you 0. Handle
 * that full range case on its own instead of relying on the shift.
 */
int ClearBitRange(int num, int start, int end) //changes the bit to zero
{
    if (start < 0 || end > 31 || start > end) //three invalid cases
    {  
        return num;
    }

    unsigned int mask = 0; //creates a mask with all zeros

    for (int i = start; i <= end; i++) //loops through every bit in the range
    {
        mask = mask | (1 << i); // sets bit i in the mask
    }


    return num & (~mask); //return num + flipped value of mask
}


/*
 * Rotate bits left by d positions.
 *
 * Hint: after reducing d with d %= 32, d can come out to 0, which
 * also happens whenever the original d was itself a multiple of 32
 * (32, 64, and so on). A common rotate formula is
 * (x << d) | (x >> (32 - d)), but when d is 0 that means shifting by
 * 32, which is undefined behavior for a 32 bit type in C. Handle
 * d == 0 as its own case, where the answer is just num, instead of
 * relying on that shift to behave a particular way.
 */
int RotateLeft(int num, int d) //num is the integer and d is the position to rotate
{
    unsigned int number; //hold the bits
    unsigned int result; // holds the final answer

       d = d % 32; //reduce rotations larger than 32

    if (d == 0) {
        return num;
    } //rotation is equal to zero return the original number

    number = (unsigned int)num;

    result = (number << d) | (number >> (32 - d)); //move bits left and recover bits that need to wrap and then combine them together

    return (int)result;
}


/*
 * Swap odd and even bit positions.
 */
int SwapOddEvenBits(int num)
{
    unsigned int u = (unsigned int)num; //make unsigned int causes the bit shifting easier

    //Two masks
    unsigned int even_mask = 0x55555555; //for even bits
    unsigned int odd_mask  = 0xAAAAAAAA; //for odd bits

    unsigned int evens = (u & even_mask) << 1; //move left
    unsigned int odds  = (u & odd_mask) >> 1; //move right

    return (int)(evens | odds); //combine the two groups
}
