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

START_TEST(testAddLargestRomanNumeral)
{
  ck_assert_str_eq(add("MMMDCCCLXXXVII","I"),"MMMDCCCLXXXVIII");
}
END_TEST

Suite * makeCalculatorSuite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Calculator Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, testAddByConcatinating);
    tcase_add_test(tc_core, testAddSortByLargestToSmallest);
    tcase_add_test(tc_core, testAddConvertToSubtractivePrefix);
    tcase_add_test(tc_core, testAddConvertBackToSubtractive);
    tcase_add_test(tc_core, testAddLargestRomanNumeral);
    suite_add_tcase(s, tc_core);

    return s;
}
