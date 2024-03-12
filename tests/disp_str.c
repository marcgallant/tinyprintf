#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/tinyprintf.h"

Test(disp_str, classic)
{
    cr_redirect_stdout();

    disp_str("abcd");
    char *expected = "abcd";
    fflush(NULL);

    cr_assert_stdout_eq_str(expected);
}

Test(disp_str, backslash_n)
{
    cr_redirect_stdout();

    disp_str("\n");
    fflush(NULL);
    char *expected = "\n";

    cr_assert_stdout_eq_str(expected);
}

Test(disp_str, backslash_0)
{
    cr_redirect_stdout();

    disp_str("");
    fflush(NULL);
    char *expected = "";

    cr_assert_stdout_eq_str(expected);
}

Test(disp_str, null)
{
    cr_redirect_stdout();

    disp_str(NULL);
    fflush(NULL);
    char *expected = "(null)";

    cr_assert_stdout_eq_str(expected);
}
