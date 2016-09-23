#include <check.h>
#include "../main/common-utils.h"

START_TEST(testReplaceSubstring)
{
  ck_assert_str_eq(replaceSubstring("Hello World", "World", "Michigan"),"Hello Michigan");
  ck_assert_str_eq(replaceSubstring("Hello World. Hello Universe", "World", "Michigan"),"Hello Michigan. Hello Universe");
  ck_assert_str_eq(replaceSubstring("CXLIIII", "XL", "XXXX"),"CXXXXIIII");
  ck_assert_str_eq(replaceSubstring("A", "A", "ABC"),"ABC");
}
END_TEST

START_TEST(testReplaceEntireString)
{
  ck_assert_str_eq(replaceSubstring("Hello", "Hello", "World"),"World");
}
END_TEST

START_TEST(testReplaceStringThatDoesNotExistReturnsInput)
{
  ck_assert_str_eq(replaceSubstring("substring is not here", "foo", "bar"),"substring is not here");
}
END_TEST

START_TEST(testConcatenateString)
{
  ck_assert_str_eq(concatenate("foo", "bar"), "foobar");
  ck_assert_str_eq(concatenate("short", " loooooooooooong"), "short loooooooooooong");
  ck_assert_str_eq(concatenate("loooooooooooong ", "short"), "loooooooooooong short");
}
END_TEST

Suite * makeCommonUtilsSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Common Utils Suite");
    tcCore = tcase_create("Core");


    tcase_add_test(tcCore, testReplaceSubstring);
    tcase_add_test(tcCore, testReplaceEntireString);
    tcase_add_test(tcCore, testReplaceStringThatDoesNotExistReturnsInput);
    tcase_add_test(tcCore, testConcatenateString);

    suite_add_tcase(s, tcCore);

    return s;
}
