#include <criterion/criterion.h>

#include "MyBitManipulation.h"

Test(ToggleBit, examples_and_invalid_positions)
{
    cr_assert_eq(ToggleBit(9, 0), 8);
    cr_assert_eq(ToggleBit(9, 3), 1);
    cr_assert_eq(ToggleBit(-3, 2), -7);
    cr_assert_eq(ToggleBit(0, 31), (int)0x80000000u);
    cr_assert_eq(ToggleBit(9, -1), 9);
    cr_assert_eq(ToggleBit(9, 32), 9);
}

Test(GetMSB, positive_zero_and_negative)
{
    cr_assert_eq(GetMSB(18), 4);
    cr_assert_eq(GetMSB(16), 4);
    cr_assert_eq(GetMSB(1), 0);
    cr_assert_eq(GetMSB(0), -1);
    cr_assert_eq(GetMSB(-1), 31);
    cr_assert_eq(GetMSB((int)0x80000000u), 31);
}

Test(ClearBitRange, normal_invalid_and_full_range)
{
    cr_assert_eq(ClearBitRange(73, 1, 3), 65);
    cr_assert_eq(ClearBitRange(-73, 1, 3), -79);
    cr_assert_eq(ClearBitRange((int)0xFFFFFFFFu, 0, 7),
                 (int)0xFFFFFF00u);
    cr_assert_eq(ClearBitRange((int)0xFFFFFFFFu, 0, 31), 0);
    cr_assert_eq(ClearBitRange(73, -1, 3), 73);
    cr_assert_eq(ClearBitRange(73, 4, 3), 73);
    cr_assert_eq(ClearBitRange(73, 1, 32), 73);
}

Test(RotateLeft, examples_and_wraparound)
{
    cr_assert_eq(RotateLeft(5, 1), 10);
    cr_assert_eq(RotateLeft(5, 2), 20);
    cr_assert_eq(RotateLeft(-5, 1), -9);
    cr_assert_eq(RotateLeft((int)0x80000000u, 1), 1);
    cr_assert_eq(RotateLeft((int)0xC0000000u, 2), 3);
    cr_assert_eq(RotateLeft(5, 32), 5);
    cr_assert_eq(RotateLeft(5, 33), 10);
}

Test(SwapOddEvenBits, positive_negative_and_patterns)
{
    cr_assert_eq(SwapOddEvenBits(23), 43);
    cr_assert_eq(SwapOddEvenBits(-23), -42);
    cr_assert_eq(SwapOddEvenBits(0), 0);
    cr_assert_eq(SwapOddEvenBits((int)0xAAAAAAAAu),
                 (int)0x55555555u);
    cr_assert_eq(SwapOddEvenBits((int)0x55555555u),
                 (int)0xAAAAAAAAu);
}
