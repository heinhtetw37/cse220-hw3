#include <stdio.h>
#include "BitManipulation/MyBitManipulation.h"
#include "MyIntegers/MyIntegers.h"

int main(void)
{
    /* printf("ToggleBit(9, 0): %d\n", ToggleBit(9, 0));
    printf("ToggleBit(9, 3): %d\n", ToggleBit(9, 3));
    printf("ToggleBit(-3, 2): %d\n", ToggleBit(-3, 2));
    printf("ToggleBit(-3, 1): %d\n", ToggleBit(-3, 1));

    printf("GetMSB(18): %d\n", GetMSB(18));
    printf("GetMSB(0): %d\n", GetMSB(0));
    printf("GetMSB(-1): %d\n", GetMSB(-1));

    printf ("Clear Bit Range (73, 1, 3): %d\n", ClearBitRange(73, 1, 3));

    printf ("RotateLeft(5,1): %d\n", RotateLeft(5,1));

    printf("SwapOddEvenBits(23): %d\n", SwapOddEvenBits(23));
    return 0; */

    /* Two's complement -> Sign magnitude */
    printf("Test 1: ");
    repr_convert('2', 'S', 0xfffffffb);

    /* Sign magnitude -> Two's complement */
    printf("Test 2: ");
    repr_convert('S', '2', 0x80000005);

    /* Positive number */
    printf("Test 3: ");
    repr_convert('2', 'S', 0x00000005);

    /* Negative zero -> positive zero */
    printf("Test 4: ");
    repr_convert('S', '2', 0x80000000);

    /* Undefined case */
    printf("Test 5: ");
    repr_convert('2', 'S', 0x80000000);

    /* Invalid representation */
    printf("Test 6: ");
    repr_convert('F', '2', 0x00000005);

    //return 0;
    unsigned int i = 1;
    while(i > 0) {
        i <<= 1;
    }
    printf("Done");
}