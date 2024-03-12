#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/tinyprintf.h"

Test(tinyprintf, Simple)
{
    cr_redirect_stdout();
    tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    fflush(NULL);
    char *expected = "Hello [42] world!";

    cr_assert_stdout_eq_str(expected);
}

Test(tinyprintf, Hexadecimal)
{
    cr_redirect_stdout();
    tinyprintf("%s [%x] %s", "Hello", 42, "world!");

    fflush(NULL);
    char *expected = "Hello [2a] world!";

    cr_assert_stdout_eq_str(expected);
}

Test(tinyprintf, Percent)
{
    cr_redirect_stdout();
    tinyprintf("%%s", "in your head");

    fflush(NULL);
    char *expected = "%s";

    cr_assert_stdout_eq_str(expected);
}

Test(tinyprintf, Unknown)
{
    cr_redirect_stdout();
    tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);

    fflush(NULL);
    char *expected = "Good morning ACU! %t Tinyprintf is cool";

    cr_assert_stdout_eq_str(expected);
}

Test(tinyprintf, Tricky)
{
    cr_redirect_stdout();
    tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');

    fflush(NULL);
    char *expected = "42 is the answer... 42 too.";

    cr_assert_stdout_eq_str(expected);
}

Test(tinyprintf, Percent2)
{
    cr_redirect_stdout();
    tinyprintf("%%%s", "on est laaaa");

    fflush(NULL);
    char *expected = "%on est laaaa";

    cr_assert_stdout_eq_str(expected);
}

Test(tinyprintf, All)
{
    cr_redirect_stdout();
    tinyprintf("%s %c %d %u %o %x %% %t", "Hello", 'c', 42, 42, 42, 42);
    fflush(NULL);
    char *expected = "Hello c 42 42 52 2a % %t";

    cr_assert_stdout_eq_str(expected);
}

Test(tinyprintf, Moreargs)
{
    cr_redirect_stdout();
    tinyprintf("%s", "im giving more args", 42, 42, 42);
    fflush(NULL);
    char *expected = "im giving more args";

    cr_assert_stdout_eq_str(expected);
}
