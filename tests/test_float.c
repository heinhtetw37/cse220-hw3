#include <criterion/criterion.h>

#include "Myfloat.h"


Test(construct_float_sf, positive_5_5) {
    /* sign_bit = 0x00 (positive), exponent = 0x81 (excess-127 -> 2),
       fraction = 0x300000. Expected IEEE-754 bit pattern is 0x40B00000,
       which is 5.5f. */
    cr_assert_float_eq(
        construct_float_sf(0x00, 0x81, 0x300000),
        5.5,
        1e-6
    );
}
    Test(construct_float_sf, negative_5_5)
    {
        /* sign_bit = 0x01 (negative), exponent = 0x81,
           fraction = 0x300000. Expected IEEE-754 bit pattern is 0xC0B00000,
           which is -5.5f. */
        cr_assert_float_eq(
            construct_float_sf(0x01, 0x81, 0x300000),
            -5.5,
            1e-6
        );
    }


    Test(construct_float_sf, positive_1_25)
    {
        /* sign_bit = 0x00 (positive), exponent = 0x7F,
           fraction = 0x200000. Expected IEEE-754 bit pattern is 0x3FA00000,
           which is 1.25f. */
        cr_assert_float_eq(
            construct_float_sf(0x00, 0x7F, 0x200000),
            1.25,
            1e-6
        );
    }


    Test(construct_float_sf, negative_1_25)
    {
        /* sign_bit = 0x01 (negative), exponent = 0x7F,
           fraction = 0x200000. Expected IEEE-754 bit pattern is 0xBFA00000,
           which is -1.25f. */
        cr_assert_float_eq(
            construct_float_sf(0x01, 0x7F, 0x200000),
            -1.25,
            1e-6
        );
    }


    Test(construct_float_sf, positive_0_002588)
    {
        /* sign_bit = 0x00 (positive), exponent = 0x76,
           fraction = 0x299B6F. Expected IEEE-754 bit pattern is 0x3B299B6F,
           which is approximately 0.002588f. */
        cr_assert_float_eq(
            construct_float_sf(0x00, 0x76, 0x299B6F),
            0.002588,
            1e-6
        );
    }


    Test(construct_float_sf, negative_0_002588)
    {
        /* sign_bit = 0x01 (negative), exponent = 0x76,
           fraction = 0x299B6F. Expected IEEE-754 bit pattern is 0xBB299B6F,
           which is approximately -0.002588f. */
        cr_assert_float_eq(
            construct_float_sf(0x01, 0x76, 0x299B6F),
            -0.002588,
            1e-6
        );
    }


    Test(construct_float_sf, positive_1374_44)
    {
        /* sign_bit = 0x00 (positive), exponent = 0x89,
           fraction = 0xABCDEF. Expected IEEE-754 bit pattern is 0x44ABCDEF,
           which is approximately 1374.44f. */
        cr_assert_float_eq(
            construct_float_sf(0x00, 0x89, 0xABCDEF),
            1374.44,
            1e-2
        );
    }


    Test(construct_float_sf, negative_1374_44)
    {
        /* sign_bit = 0x01 (negative), exponent = 0x89,
           fraction = 0xABCDEF. Expected IEEE-754 bit pattern is 0xC4ABCDEF,
           which is approximately -1374.44f. */
        cr_assert_float_eq(
            construct_float_sf(0x01, 0x89, 0xABCDEF),
            -1374.44,
            1e-2
        );
    }


    Test(construct_float_sf, positive_255439)
    {
        /* sign_bit = 0x00 (positive), exponent = 0x90,
           fraction = 0x7973C0. Expected IEEE-754 bit pattern is 0x487973C0,
           which is approximately 255439f. */
        cr_assert_float_eq(
            construct_float_sf(0x00, 0x90, 0x7973C0),
            255439,
            1
        );
    }


    Test(construct_float_sf, negative_255439)
    {
        /* sign_bit = 0x01 (negative), exponent = 0x90,
           fraction = 0x7973C0. Expected IEEE-754 bit pattern is 0xC87973C0,
           which is approximately -255439f. */
        cr_assert_float_eq(
            construct_float_sf(0x01, 0x90, 0x7973C0),
            -255439,
            1
        );
    }

