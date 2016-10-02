#include <check.h>
#include "../main/calculator.h"

static void assertAdd(char *firstNumeral, char *secondNumeral, char *result);

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

START_TEST(testAddOneToMakeLargesttRomanNumeral)
{
  assertAdd("MMMCMXCVIII","I","MMMCMXCIX");
}
END_TEST

static void assertAdd(char *firstNumeral, char *secondNumeral, char *expected){
  char result[100] = {'\0'};
  add(firstNumeral, secondNumeral, result);
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
    tcase_add_test(tcCore, testAddOneToMakeLargesttRomanNumeral);
    suite_add_tcase(s, tcCore);

    return s;
}
