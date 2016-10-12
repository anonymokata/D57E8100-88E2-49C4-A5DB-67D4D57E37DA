#include <check.h>
#include "../main/common-utils.h"
#include "test-constants.h"

static void assertReplaceSubstring(char *inputString, char *subString, char *replaceWithString, char *expected);
static void assertConcatenate(char *input1, char *input2, char *expected);
static const int TRUE = 1;
static const int FALSE = 0;

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

START_TEST(testReplaceWithNothingDoesNotAddWhiteSpace)
{
  assertReplaceSubstring("Hello", "o", "", "Hell");
}
END_TEST

START_TEST(testReplaceStringThatDoesNotExistReturnsInput)
{
  assertReplaceSubstring("substring is not here", "foo", "bar", "substring is not here");
}
END_TEST

START_TEST(testConcatenateString)
{
  assertConcatenate("foo", "bar", "foobar");
  assertConcatenate("short", " loooooooooooong", "short loooooooooooong");
  assertConcatenate("loooooooooooong ", "short", "loooooooooooong short");
}
END_TEST

START_TEST(testIsGreaterThanAllNumerals)
{
  ck_assert_int_eq(isGreaterThanOrEqual('V','I'), TRUE);
  ck_assert_int_eq(isGreaterThanOrEqual('X','V'), TRUE);
  ck_assert_int_eq(isGreaterThanOrEqual('L','X'), TRUE);
  ck_assert_int_eq(isGreaterThanOrEqual('C','L'), TRUE);
  ck_assert_int_eq(isGreaterThanOrEqual('D','C'), TRUE);
  ck_assert_int_eq(isGreaterThanOrEqual('M','D'), TRUE);

  ck_assert_int_eq(isGreaterThanOrEqual('I','V'), FALSE);
  ck_assert_int_eq(isGreaterThanOrEqual('V','X'), FALSE);
  ck_assert_int_eq(isGreaterThanOrEqual('X','L'), FALSE);
  ck_assert_int_eq(isGreaterThanOrEqual('L','C'), FALSE);
  ck_assert_int_eq(isGreaterThanOrEqual('C','D'), FALSE);
  ck_assert_int_eq(isGreaterThanOrEqual('D','M'), FALSE);
}
END_TEST

START_TEST(testIsGreaterOrEqual)
{
  ck_assert_int_eq(isGreaterThanOrEqual('I','I'), TRUE);
  ck_assert_int_eq(isGreaterThanOrEqual('M','M'), TRUE);
  ck_assert_int_eq(isGreaterThanOrEqual('M','I'), TRUE);
}
END_TEST

START_TEST(testGetRomanNumeralSortIndex)
{
  ck_assert_int_eq(getRomanNumeralSortIndex('I'), 0);
  ck_assert_int_eq(getRomanNumeralSortIndex('V'), 1);
  ck_assert_int_eq(getRomanNumeralSortIndex('X'), 2);
  ck_assert_int_eq(getRomanNumeralSortIndex('L'), 3);
  ck_assert_int_eq(getRomanNumeralSortIndex('C'), 4);
  ck_assert_int_eq(getRomanNumeralSortIndex('D'), 5);
  ck_assert_int_eq(getRomanNumeralSortIndex('M'), 6);
}
END_TEST

START_TEST(testGetRomanNumeralSortIndexUnknownReturnsNegativeOne)
{
  ck_assert_int_eq(getRomanNumeralSortIndex('A'), -1);
}
END_TEST

static void assertReplaceSubstring(char *inputString, char *subString, char *replaceWithString, char *expected){
  char result[TEST_BUFFER_SIZE] = {'\0'};
  replaceSubstring(inputString, subString, replaceWithString, result);
  ck_assert_str_eq(result, expected);
}

static void assertConcatenate(char *input1, char *input2, char *expected){
  char result[TEST_BUFFER_SIZE] = {'\0'};
  concatenate(input1, input2 ,result);
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
    tcase_add_test(tcCore, testReplaceWithNothingDoesNotAddWhiteSpace);
    tcase_add_test(tcCore, testReplaceStringThatDoesNotExistReturnsInput);
    tcase_add_test(tcCore, testConcatenateString);
    tcase_add_test(tcCore, testIsGreaterThanAllNumerals);
    tcase_add_test(tcCore, testIsGreaterOrEqual);
    tcase_add_test(tcCore, testGetRomanNumeralSortIndex);
    tcase_add_test(tcCore, testGetRomanNumeralSortIndexUnknownReturnsNegativeOne);

    suite_add_tcase(s, tcCore);

    return s;
}
