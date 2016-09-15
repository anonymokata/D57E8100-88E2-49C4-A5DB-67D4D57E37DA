#include <check.h>
#include "../main/roman-numerals-converter.h"

START_TEST(test_convert_to_additive_prefixes)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("IV"),"IIII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("IX"),"VIIII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("XL"),"XXXX");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("XC"),"LXXXX");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CD"),"CCCC");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CM"),"DCCCC");
}
END_TEST

START_TEST(test_convert_to_additive_prefix_substring)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("XIV"),"XIIII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CXLII"),"CXXXXII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CXLIV"),"CXXXXIIII");
}
END_TEST

START_TEST(test_convert_subtractive_input_has_no_prefix)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("ECHO"),"ECHO");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("III"),"III");
}
END_TEST

START_TEST(test_convertInternalSums)
{
  ck_assert_str_eq(convertInternalSums("IIIII"),"V");
  ck_assert_str_eq(convertInternalSums("VV"),"X");
  ck_assert_str_eq(convertInternalSums("XXXXX"),"L");
  ck_assert_str_eq(convertInternalSums("LL"),"C");
  ck_assert_str_eq(convertInternalSums("CCCCC"),"D");
  ck_assert_str_eq(convertInternalSums("DD"),"M");
}
END_TEST

START_TEST(test_convertInternalSums_input_has_no_sum)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("ECHO"),"ECHO");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("III"),"III");
}
END_TEST

START_TEST(test_convert_multiple_internal_sums)
{
  ck_assert_str_eq(convertInternalSums("VIIIII"),"X");
  ck_assert_str_eq(convertInternalSums("VIIIIII"),"XI");
  ck_assert_str_eq(convertInternalSums("CLXXXXVIIIIIII"),"CCII");
}
END_TEST

START_TEST(test_convert_to_subtractive_prefix)
{
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("IIII"),"IV");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("VIIII"),"IX");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("XXXX"),"XL");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("LXXXX"),"XC");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("CCCC"),"CD");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("DCCCC"),"CM");
}
END_TEST

START_TEST(test_convert_to_subtractive_prefix_substring)
{
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("XIIII"),"XIV");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("CXXXXII"),"CXLII");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("CXXXXIIII"),"CXLIV");
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
    tcase_add_test(tc_core, test_convertInternalSums);
    tcase_add_test(tc_core, test_convertInternalSums_input_has_no_sum);
    tcase_add_test(tc_core, test_convert_multiple_internal_sums);
    tcase_add_test(tc_core, test_convert_to_subtractive_prefix);
    tcase_add_test(tc_core, test_convert_to_subtractive_prefix_substring);
    suite_add_tcase(s, tc_core);

    return s;
}
