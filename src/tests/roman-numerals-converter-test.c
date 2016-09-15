#include <check.h>
#include "../main/roman-numerals-converter.h"

START_TEST(testConvertToAdditivePrefixes)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("IV"),"IIII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("IX"),"VIIII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("XL"),"XXXX");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("XC"),"LXXXX");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CD"),"CCCC");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CM"),"DCCCC");
}
END_TEST

START_TEST(testConvertToAdditivePrefixSubstring)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("XIV"),"XIIII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CXLII"),"CXXXXII");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("CXLIV"),"CXXXXIIII");
}
END_TEST

START_TEST(testConvertSubtractiveInputHasNoPrefix)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("ECHO"),"ECHO");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("III"),"III");
}
END_TEST

START_TEST(testConvertInternalSums)
{
  ck_assert_str_eq(convertInternalSums("IIIII"),"V");
  ck_assert_str_eq(convertInternalSums("VV"),"X");
  ck_assert_str_eq(convertInternalSums("XXXXX"),"L");
  ck_assert_str_eq(convertInternalSums("LL"),"C");
  ck_assert_str_eq(convertInternalSums("CCCCC"),"D");
  ck_assert_str_eq(convertInternalSums("DD"),"M");
}
END_TEST

START_TEST(testConvertInternalSumsInputHasNoSum)
{
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("ECHO"),"ECHO");
  ck_assert_str_eq(convertSubtractiveToAdditivePrefix("III"),"III");
}
END_TEST

START_TEST(testConvertMultipleInternalSums)
{
  ck_assert_str_eq(convertInternalSums("VIIIII"),"X");
  ck_assert_str_eq(convertInternalSums("VIIIIII"),"XI");
  ck_assert_str_eq(convertInternalSums("CLXXXXVIIIIIII"),"CCII");
}
END_TEST

START_TEST(testConvertToSubtractivePrefix)
{
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("IIII"),"IV");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("VIIII"),"IX");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("XXXX"),"XL");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("LXXXX"),"XC");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("CCCC"),"CD");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("DCCCC"),"CM");
}
END_TEST

START_TEST(testConvertToSubtractivePrefix_substring)
{
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("XIIII"),"XIV");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("CXXXXII"),"CXLII");
  ck_assert_str_eq(convertAdditiveToSubtractivePrefix("CXXXXIIII"),"CXLIV");
}
END_TEST

Suite * makeRomanNumeralsConverterSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Roman Numerals Converter Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testConvertToAdditivePrefixes);
    tcase_add_test(tcCore, testConvertToAdditivePrefixSubstring);
    tcase_add_test(tcCore, testConvertSubtractiveInputHasNoPrefix);
    tcase_add_test(tcCore, testConvertInternalSums);
    tcase_add_test(tcCore, testConvertInternalSumsInputHasNoSum);
    tcase_add_test(tcCore, testConvertMultipleInternalSums);
    tcase_add_test(tcCore, testConvertToSubtractivePrefix);
    tcase_add_test(tcCore, testConvertToSubtractivePrefix_substring);
    suite_add_tcase(s, tcCore);

    return s;
}
