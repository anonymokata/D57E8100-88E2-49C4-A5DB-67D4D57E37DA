#include <check.h>
#include "../main/roman-numerals-converter.h"

START_TEST(test_convert_valid_subtractive_prefixes)
{
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("IV"),"IIII");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("IX"),"VIIII");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("XL"),"XXXX");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("XC"),"LXXXX");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("CD"),"CCCC");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("CM"),"DCCCC");
}
END_TEST

START_TEST(test_input_has_no_prefix)
{
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("BOGUS"),"BOGUS");
}
END_TEST

Suite * make_roman_numerals_converter_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals Converter Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_convert_valid_subtractive_prefixes);
    tcase_add_test(tc_core, test_input_has_no_prefix);
    suite_add_tcase(s, tc_core);

    return s;
}
