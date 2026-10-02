#include "MyIntegers.h"
#include <stdio.h>

/*
Convert between:

'S' = sign magnitude

'2' = two's complement


Print:

hex value:
xxxxxxxx

error:
error

undefined:
undefined
*/

/*
 * Hint: the two trickiest cases are the ones the assignment calls out
 * as "undefined" and "always output positive zero".
 *   - Two's complement 0x80000000 (the most negative int) has no
 *     matching sign/magnitude value, since sign/magnitude only goes
 *     down to -(2^31 - 1). That is the case you print "undefined" for
 *     when converting two's complement to sign/magnitude.
 *   - Sign/magnitude has two zeros, 0x00000000 and 0x80000000 (a sign
 *     bit of 1 with a magnitude of 0). Both represent the value 0, so
 *     whichever representation you are converting into, make sure
 *     zero always comes out as 0x00000000, never with the sign bit
 *     set.
 */
void repr_convert(
        char source_repr,
        char target_repr,
        uint32_t repr)
{

    // TODO: implement
    uint32_t result;
    uint32_t magnitude;

    if (source_repr != 'S' && source_repr != '2') {
        printf("error\n");
        return;
    }

    if (target_repr != 'S' && target_repr != '2') {
        printf("error\n");
        return;
    }
    //won't add any other conversion if the representations are the same
    if (source_repr == target_repr) {
        if (source_repr == 'S' && repr == 0x80000000u)
            {
            printf("00000000\n");
            return;
        }

        printf("%08x\n", repr);
        return;
    }

    //Two's complement -> Sign-magnitude
    if (source_repr == '2' && target_repr == 'S') {
        if (repr == 0x80000000u) {
            printf("undefined\n");
            return;
        }

        if ((repr & 0x80000000u) == 0) {
            result = repr;
        }
        else
        {
            magnitude = (~repr) + 1u;
            result = magnitude | 0x80000000u;
        }
        printf("%08x\n", result);
        return;
    }

    //Sign-magnitude -> Two's complement
    if (source_repr == 'S' && target_repr == '2') {
        magnitude = repr & 0x7FFFFFFFu;

        if (magnitude == 0) {
            printf("00000000\n");
            return;
        }

        if ((repr & 0x80000000u) == 0) {
            result = magnitude;
        }
        else {
            result = (~magnitude) + 1u;
        }
        printf("%08x\n", result);
        return;
    }


}
