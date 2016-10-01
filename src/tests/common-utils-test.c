#include <check.h>
#include "../main/common-utils.h"

static void assertReplaceSubstring(char *inputString, char *subString, char *replaceWithString, char *expected);

START_TEST(testReplaceSubstring)
{
  assertReplaceSubstring("Hello World", "World", "Michigan", "Hello Michigan");
  assertReplaceSubstring("Hello World. Hello Universe", "World", "Michigan", "Hello Michigan. Hello Universe");
  assertReplaceSubstring("CXLIIII", "XL", "XXXX", "CXXXXIIII");
  assertReplaceSubstring("A", "A", "ABC", "ABC");
}
END_TEST

START_TEST(testReplaceEntireString)
{
  assertReplaceSubstring("Hello", "Hello", "World", "World");
}
END_TEST

START_TEST(testReplaceStringThatDoesNotExistReturnsInput)
{
  assertReplaceSubstring("substring is not here", "foo", "bar", "substring is not here");
}
END_TEST

START_TEST(testConcatenateString)
{
  ck_assert_str_eq(concatenate("foo", "bar"), "foobar");
  ck_assert_str_eq(concatenate("short", " loooooooooooong"), "short loooooooooooong");
  ck_assert_str_eq(concatenate("loooooooooooong ", "short"), "loooooooooooong short");
}
END_TEST

static void assertReplaceSubstring(char *inputString, char *subString, char *replaceWithString, char *expected){
  char result[1000] = {'\0'};
  replaceSubstring(inputString, subString, replaceWithString,result);
  ck_assert_str_eq(result, expected);
}


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
