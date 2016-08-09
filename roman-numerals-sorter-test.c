#include <check.h>
#include "roman-numerals-sorter.h"

START_TEST(test_sort_roman_numerals)
{
  ck_assert_str_eq(sort_roman_numerals("VI"),"VI");
  // ck_assert_str_eq(sort_roman_numerals("IV"),"VI");
  // ck_assert_str_eq(sort_roman_numerals("XICL"),"CLXI");
  // ck_assert_str_eq(sort_roman_numerals("XIICLI"),"CLXIII");
  // ck_assert_str_eq(sort_roman_numerals("IIVII"),"VIIII");
  // ck_assert_str_eq(sort_roman_numerals("CIDCLMILXIVIDXDM"),"MMDDDCCLLXXVIIII");
}
END_TEST

Suite * make_roman_numerals_sorter_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals Sorter Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_sort_roman_numerals);
    suite_add_tcase(s, tc_core);

    return s;
}
