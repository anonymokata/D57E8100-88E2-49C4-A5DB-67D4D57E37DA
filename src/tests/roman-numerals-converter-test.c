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

START_TEST(test_convert_subtractive_input_has_no_prefix)
{
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("ECHO"),"ECHO");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("III"),"III");
}
END_TEST

START_TEST(test_convert_internal_sums)
{
  ck_assert_str_eq(convert_internal_sums("IIIII"),"V");
  ck_assert_str_eq(convert_internal_sums("VV"),"X");
  ck_assert_str_eq(convert_internal_sums("XXXXX"),"L");
  ck_assert_str_eq(convert_internal_sums("LL"),"C");
  ck_assert_str_eq(convert_internal_sums("CCCCC"),"D");
  ck_assert_str_eq(convert_internal_sums("DD"),"M");
}
END_TEST

START_TEST(test_convert_internal_sums_input_has_no_sum)
{
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("ECHO"),"ECHO");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("III"),"III");
}
END_TEST

Suite * make_roman_numerals_converter_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals Converter Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_convert_valid_subtractive_prefixes);
    tcase_add_test(tc_core, test_convert_subtractive_input_has_no_prefix);
    tcase_add_test(tc_core, test_convert_internal_sums);
    tcase_add_test(tc_core, test_convert_internal_sums_input_has_no_sum);
    suite_add_tcase(s, tc_core);

    return s;
}
