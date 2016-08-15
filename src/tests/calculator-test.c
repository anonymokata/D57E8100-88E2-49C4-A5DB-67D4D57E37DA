#include <check.h>
#include "../main/calculator.h"

START_TEST(test_add_by_concatinating)
{
  ck_assert_str_eq(add("I","I"),"II");
  ck_assert_str_eq(add("I","II"),"III");
}
END_TEST

START_TEST(test_add_sort_by_largest_to_smallest)
{
  ck_assert_str_eq(add("I","V"),"VI");
  ck_assert_str_eq(add("XI","CL"),"CLXI");
  ck_assert_str_eq(add("XII","CLI"),"CLXIII");
}
END_TEST

START_TEST(test_add_convert_to_subtractive_prefix)
{
  ck_assert_str_eq(add("IX","I"),"X");
  ck_assert_str_eq(add("IX","IX"),"XVIII");
  ck_assert_str_eq(add("IX","III"),"XII");
  ck_assert_str_eq(add("I","IX"),"X");
  ck_assert_str_eq(add("III","IX"),"XII");
}
END_TEST

START_TEST(test_add_convert_back_to_subtractive)
{
  ck_assert_str_eq(add("CXXIII","LXIX"),"CXCII");
}
END_TEST

START_TEST(test_add_largest_roman_numeral)
{
  ck_assert_str_eq(add("MMMDCCCLXXXVII","I"),"MMMDCCCLXXXVIII");
}
END_TEST

Suite * make_calculator_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Calculator Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add_by_concatinating);
    tcase_add_test(tc_core, test_add_sort_by_largest_to_smallest);
    tcase_add_test(tc_core, test_add_convert_to_subtractive_prefix);
    tcase_add_test(tc_core, test_add_convert_back_to_subtractive);
    tcase_add_test(tc_core, test_add_largest_roman_numeral);
    suite_add_tcase(s, tc_core);

    return s;
}
