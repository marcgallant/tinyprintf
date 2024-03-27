#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/tinyprintf.h"

Test(my_itoa, classic)
{
    cr_redirect_stdout();

    my_itoa(255);

    fflush(NULL);
    char *expected = "255";

    cr_assert_stdout_eq_str(expected);
}

Test(my_itoa, zero)
{
    cr_redirect_stdout();

    my_itoa(0);

    fflush(NULL);
    char *expected = "0";

    cr_assert_stdout_eq_str(expected);
}

Test(my_itoa_base, classic)
{
    cr_redirect_stdout();

    my_itoa_base(255, 16);

    fflush(NULL);
    char *expected = "ff";

    cr_assert_stdout_eq_str(expected);
}

Test(my_itoa, negatif)
{
    cr_redirect_stdout();

    my_itoa(-20);

    fflush(NULL);
    char *expected = "-20";

    cr_assert_stdout_eq_str(expected);
}

Test(my_itoa_base, zero)
{
    cr_redirect_stdout();

    my_itoa_base(0, 16);

    fflush(NULL);
    char *expected = "0";

    cr_assert_stdout_eq_str(expected);
}
