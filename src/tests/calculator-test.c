#include <check.h>
#include "../main/calculator.h"

static void assertAdd(char *firstNumeral, char *secondNumeral, char *result);
static void assertSubtract(char *firstNumeral, char *secondNumeral, char *expected);

START_TEST(testAddByConcatinating)
{
  assertAdd("I","I","II");
  assertAdd("I","II","III");
}
END_TEST

START_TEST(testAddSortByLargestToSmallest)
{
  assertAdd("I","V","VI");
  assertAdd("XI","CL","CLXI");
  assertAdd("XII","CLI","CLXIII");
}
END_TEST

START_TEST(testAddConvertToSubtractivePrefix)
{
  assertAdd("IX","I","X");
  assertAdd("IX","IX","XVIII");
  assertAdd("IX","III","XII");
  assertAdd("I","IX","X");
  assertAdd("III","IX","XII");
}
END_TEST

START_TEST(testAddConvertBackToSubtractive)
{
  assertAdd("CXXIII","LXIX","CXCII");
}
END_TEST

START_TEST(testAddOneToMakeLongestRomanNumeral)
{
  assertAdd("MMMDCCCLXXXVII","I","MMMDCCCLXXXVIII");
}
END_TEST

START_TEST(testAddOneToMakeLargestRomanNumeral)
{
  assertAdd("MMMCMXCVIII","I","MMMCMXCIX");
}
END_TEST

START_TEST(testSubtractReducesCommonNumerals)
{
  assertSubtract("II","I","I");
  assertSubtract("CLXV","LXV","C");
}
END_TEST

START_TEST(testSubtractHandlesSubtractivePrefixes)
{
  assertSubtract("IV","II","II");//4-2=2
  assertSubtract("XLIV","VI","XXXVIII");//44-6=38
  assertSubtract("C","XLIV","LVI");//100-44=56    XXXXIIII
}
END_TEST

START_TEST(testSubtractConvertsBackToSubtractivePrefixes)
{
  assertSubtract("X","I","IX");//10-1=9
  assertSubtract("CLXI","XX","CXLI");//161-1=141
}
END_TEST

START_TEST(testSubtractBufferNeedsToBeAtleast100)
{
  char result1[99] = {'\0'};
  char expected[99] = {'\0'};
  subtract("II", "I", result1, 99);
  ck_assert_str_eq(result1, expected);

  char result2[100] = {'\0'};
  subtract("II", "I", result2, 100);
  ck_assert_str_eq(result2, "I");
}
END_TEST

START_TEST(testSubtractBufferIsNotNull)
{
  subtract("II", "I", NULL, 100);
  ck_assert_str_eq("DID NOT BLOW UP", "DID NOT BLOW UP");
}
END_TEST

START_TEST(testAddBufferNeedsToBeAtleast100)
{
  char result1[99] = {'\0'};
  char expected[99] = {'\0'};
  add("II", "I", result1, 99);
  ck_assert_str_eq(result1, expected);

  char result2[100] = {'\0'};
  add("II", "I", result2, 100);
  ck_assert_str_eq(result2, "III");
}
END_TEST

START_TEST(testAddBufferIsNotNull)
{
  add("II", "I", NULL, 100);
  ck_assert_str_eq("DID NOT BLOW UP", "DID NOT BLOW UP");
}
END_TEST

static void assertAdd(char *firstNumeral, char *secondNumeral, char *expected){
  char result[100] = {'\0'};
  add(firstNumeral, secondNumeral, result, 100);
  ck_assert_str_eq(result, expected);
}

static void assertSubtract(char *firstNumeral, char *secondNumeral, char *expected){
  char result[100] = {'\0'};
  subtract(firstNumeral, secondNumeral, result, 100);
  ck_assert_str_eq(result, expected);
}

Suite * makeCalculatorSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Calculator Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testAddByConcatinating);
    tcase_add_test(tcCore, testAddSortByLargestToSmallest);
    tcase_add_test(tcCore, testAddConvertToSubtractivePrefix);
    tcase_add_test(tcCore, testAddConvertBackToSubtractive);
    tcase_add_test(tcCore, testAddOneToMakeLongestRomanNumeral);
    tcase_add_test(tcCore, testAddOneToMakeLargestRomanNumeral);
    tcase_add_test(tcCore, testSubtractReducesCommonNumerals);
    tcase_add_test(tcCore, testSubtractHandlesSubtractivePrefixes);
    tcase_add_test(tcCore, testSubtractConvertsBackToSubtractivePrefixes);
    tcase_add_test(tcCore, testSubtractBufferNeedsToBeAtleast100);
    tcase_add_test(tcCore, testSubtractBufferIsNotNull);
    tcase_add_test(tcCore, testAddBufferNeedsToBeAtleast100);
    tcase_add_test(tcCore, testAddBufferIsNotNull);
    suite_add_tcase(s, tcCore);

    return s;
}
