#include <check.h>
#include "../main/calculator.h"

START_TEST(testAddByConcatinating)
{
  ck_assert_str_eq(add("I","I"),"II");
  ck_assert_str_eq(add("I","II"),"III");
}
END_TEST

START_TEST(testAddSortByLargestToSmallest)
{
  ck_assert_str_eq(add("I","V"),"VI");
  ck_assert_str_eq(add("XI","CL"),"CLXI");
  ck_assert_str_eq(add("XII","CLI"),"CLXIII");
}
END_TEST

START_TEST(testAddConvertToSubtractivePrefix)
{
  ck_assert_str_eq(add("IX","I"),"X");
  ck_assert_str_eq(add("IX","IX"),"XVIII");
  ck_assert_str_eq(add("IX","III"),"XII");
  ck_assert_str_eq(add("I","IX"),"X");
  ck_assert_str_eq(add("III","IX"),"XII");
}
END_TEST

START_TEST(testAddConvertBackToSubtractive)
{
  ck_assert_str_eq(add("CXXIII","LXIX"),"CXCII");
}
END_TEST

START_TEST(testAddOneToMakeLongestRomanNumeral)
{
  ck_assert_str_eq(add("MMMDCCCLXXXVII","I"),"MMMDCCCLXXXVIII");
}
END_TEST

START_TEST(testAddOneToMakeLargesttRomanNumeral)
{
  ck_assert_str_eq(add("MMMCMXCVIII","I"),"MMMCMXCIX");
}
END_TEST

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
