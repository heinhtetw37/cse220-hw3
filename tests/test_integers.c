#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "MyIntegers.h"


static void redirect_stdout_setup(void)
{
    cr_redirect_stdout();
}


Test(repr_convert, sign_magnitude_to_twos_complement, .init = redirect_stdout_setup)
{
    /* 'S' -> '2': sign/magnitude 0x80000001 (sign = 1, magnitude = 1,
       value = -1). Two's complement of -1 is 0xffffffff. */
    repr_convert('S', '2', 0x80000001);
    fflush(stdout);

    cr_assert_stdout_eq_str("ffffffff\n");
}

Test(repr_convert, twos_complement_to_sign_magnitude_negative_one, .init = redirect_stdout_setup)
{
    /* '2' -> 'S': two's complement 0xffffffff represents -1.
       Sign/magnitude representation of -1 is 0x80000001. */
    repr_convert('2', 'S', 0xffffffff);
    fflush(stdout);

    cr_assert_stdout_eq_str("80000001\n");
}

Test(repr_convert, twos_complement_to_sign_magnitude_minimum, .init = redirect_stdout_setup)
{
    /* '2' -> 'S': two's complement 0x80000000 represents -2147483648.
       This value cannot be represented in 32-bit sign/magnitude,
       so the result is undefined. */
    repr_convert('2', 'S', 0x80000000);
    fflush(stdout);

    cr_assert_stdout_eq_str("undefined\n");
}


Test(repr_convert, sign_magnitude_negative_zero_to_twos_complement, .init = redirect_stdout_setup)
{
    /* 'S' -> '2': sign/magnitude 0x80000000 represents negative zero.
       Two's complement uses one representation for zero, 0x00000000. */
    repr_convert('S', '2', 0x80000000);
    fflush(stdout);

    cr_assert_stdout_eq_str("00000000\n");
}


Test(repr_convert, twos_complement_to_sign_magnitude_maximum_positive, .init = redirect_stdout_setup)
{
    /* '2' -> 'S': 0x7fffffff represents the largest positive value.
       Positive values have the same representation in both formats. */
    repr_convert('2', 'S', 0x7fffffff);
    fflush(stdout);

    cr_assert_stdout_eq_str("7fffffff\n");
}


Test(repr_convert, sign_magnitude_to_twos_complement_maximum_positive, .init = redirect_stdout_setup)
{
    /* 'S' -> '2': 0x7fffffff is a positive value.
       Its two's complement representation is also 0x7fffffff. */
    repr_convert('S', '2', 0x7fffffff);
    fflush(stdout);

    cr_assert_stdout_eq_str("7fffffff\n");
}


Test(repr_convert, twos_complement_to_sign_magnitude_negative_five, .init = redirect_stdout_setup)
{
    /* '2' -> 'S': two's complement 0xfffffffb represents -5.
       Sign/magnitude representation of -5 is 0x80000005. */
    repr_convert('2', 'S', 0xfffffffb);
    fflush(stdout);

    cr_assert_stdout_eq_str("80000005\n");
}


Test(repr_convert, sign_magnitude_to_twos_complement_negative_five, .init = redirect_stdout_setup)
{
    /* 'S' -> '2': sign/magnitude 0x80000005 represents -5.
       Two's complement representation of -5 is 0xfffffffb. */
    repr_convert('S', '2', 0x80000005);
    fflush(stdout);

    cr_assert_stdout_eq_str("fffffffb\n");
}


Test(repr_convert, sign_magnitude_negative_zero_to_sign_magnitude, .init = redirect_stdout_setup)
{
    /* 'S' -> 'S': 0x80000000 represents negative zero.
       According to the requirements, negative zero must be output
       as positive zero, 0x00000000. */
    repr_convert('S', 'S', 0x80000000);
    fflush(stdout);

    cr_assert_stdout_eq_str("00000000\n");
}


Test(repr_convert, invalid_source_format, .init = redirect_stdout_setup)
{
    /* 'F' is not a valid source representation.
       Valid representations are 'S' and '2', so print error. */
    repr_convert('F', '2', 0x00394812);
    fflush(stdout);

    cr_assert_stdout_eq_str("error\n");
}


Test(repr_convert, invalid_destination_format, .init = redirect_stdout_setup)
{
    /* 'F' is not a valid destination representation.
       Valid representations are 'S' and '2', so print error. */
    repr_convert('2', 'F', 0x00394812);
    fflush(stdout);

    cr_assert_stdout_eq_str("error\n");
}

