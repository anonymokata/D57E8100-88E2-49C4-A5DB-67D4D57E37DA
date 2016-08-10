#include <check.h>
#include "../main/calculator.h"

START_TEST(test_concatinate_to_addTest)
{
  ck_assert_str_eq(add("I","I"),"II");
  ck_assert_str_eq(add("I","II"),"III");
}
END_TEST

START_TEST(test_sort_by_largest_to_smallest)
{
  // ck_assert_str_eq(add("I","V"),"VI");
  // ck_assert_str_eq(add("XI","CL"),"CLXI");
  // ck_assert_str_eq(add("XII","CLI"),"CLXIII");
}
END_TEST

START_TEST(test_largest_roman_numeralTest)
{
  ck_assert_str_eq(add("MMDCCCLXXXVII","I"),"MMDCCCLXXXVIII");
}
END_TEST

Suite * make_calculator_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Calculator Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_concatinate_to_addTest);
    tcase_add_test(tc_core, test_sort_by_largest_to_smallest);
    tcase_add_test(tc_core, test_largest_roman_numeralTest);
    suite_add_tcase(s, tc_core);

    return s;
}
