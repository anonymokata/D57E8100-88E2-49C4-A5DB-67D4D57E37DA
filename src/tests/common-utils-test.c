#include <check.h>
#include "../main/common-utils.h"

START_TEST(testReplaceSubstring)
{
  char result[1000] = {'\0'};

  replaceSubstring("Hello World", "World", "Michigan", result);
  ck_assert_str_eq(result, "Hello Michigan");

  memset(result, 0, sizeof result);
  replaceSubstring("Hello World. Hello Universe", "World", "Michigan", result);
  ck_assert_str_eq(result, "Hello Michigan. Hello Universe");

  memset(result, 0, sizeof result);
  replaceSubstring("CXLIIII", "XL", "XXXX", result);
  ck_assert_str_eq(result, "CXXXXIIII");

  memset(result, 0, sizeof result);
  replaceSubstring("A", "A", "ABC", result);
  ck_assert_str_eq(result, "ABC");
}
END_TEST

START_TEST(testReplaceEntireString)
{
  char result[100] = {'\0'};
  replaceSubstring("Hello", "Hello", "World", result);
  ck_assert_str_eq(result, "World");
}
END_TEST

START_TEST(testReplaceStringThatDoesNotExistReturnsInput)
{
  char result[100] = {'\0'};
  replaceSubstring("substring is not here", "foo", "bar", result);
  ck_assert_str_eq(result, "substring is not here");
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
