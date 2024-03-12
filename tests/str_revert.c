#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/tinyprintf.h"

Test(str_revert, classic)
{
    char s[] = "abcd";
    str_revert(s);

    printf("%s", s);

    char *expected = "dcba";

    cr_assert_str_eq(expected, s);
}

Test(str_revert, empty)
{
    char s[] = "";
    str_revert(s);

    cr_assert_str_empty(s);
}

Test(str_revert, backslash_n)
{
    char s[] = "\n";
    str_revert(s);
    char *expected = "\n";

    cr_assert_str_eq(s, expected);
}
