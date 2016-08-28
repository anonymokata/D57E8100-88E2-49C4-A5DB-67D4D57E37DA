#include <check.h>
#include "../main/roman-numerals-converter.h"

START_TEST(test_convert_to_additive_prefixes)
{
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("IV"),"IIII");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("IX"),"VIIII");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("XL"),"XXXX");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("XC"),"LXXXX");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("CD"),"CCCC");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("CM"),"DCCCC");
}
END_TEST

START_TEST(test_convert_to_additive_prefix_substring)
{
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("XIV"),"XIIII");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("CXLII"),"CXXXXII");
  ck_assert_str_eq(convert_subtractive_to_additive_prefix("CXLIV"),"CXXXXIIII");
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

START_TEST(test_convert_multiple_internal_sums)
{
  ck_assert_str_eq(convert_internal_sums("VIIIII"),"X");
  ck_assert_str_eq(convert_internal_sums("VIIIIII"),"XI");
  ck_assert_str_eq(convert_internal_sums("CLXXXXVIIIIIII"),"CCII");
}
END_TEST

START_TEST(test_convert_to_subtractive_prefix)
{
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("IIII"),"IV");
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("VIIII"),"IX");
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("XXXX"),"XL");
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("LXXXX"),"XC");
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("CCCC"),"CD");
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("DCCCC"),"CM");
}
END_TEST

START_TEST(test_convert_to_subtractive_prefix_substring)
{
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("XIIII"),"XIV");
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("CXXXXII"),"CXLII");
  ck_assert_str_eq(convert_additive_to_subtractive_prefix("CXXXXIIII"),"CXLIV");
}
END_TEST

Suite * make_roman_numerals_converter_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals Converter Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_convert_to_additive_prefixes);
    tcase_add_test(tc_core, test_convert_to_additive_prefix_substring);
    tcase_add_test(tc_core, test_convert_subtractive_input_has_no_prefix);
    tcase_add_test(tc_core, test_convert_internal_sums);
    tcase_add_test(tc_core, test_convert_internal_sums_input_has_no_sum);
    tcase_add_test(tc_core, test_convert_multiple_internal_sums);
    tcase_add_test(tc_core, test_convert_to_subtractive_prefix);
    tcase_add_test(tc_core, test_convert_to_subtractive_prefix_substring);
    suite_add_tcase(s, tc_core);

    return s;
}
