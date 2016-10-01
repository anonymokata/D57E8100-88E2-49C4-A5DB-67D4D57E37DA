#include <check.h>
#include "../main/roman-numerals-converter.h"

static void assertInternalSums(char *input, char *expected);
static void assertConvertSubtractiveToAdditivePrefix(char *input, char *expected);
static void assertConvertAdditiveToSubtractivePrefix(char *input, char *expected);

START_TEST(testConvertSubtractiveToAdditivePrefixes)
{
  assertConvertSubtractiveToAdditivePrefix("IV", "IIII");
  assertConvertSubtractiveToAdditivePrefix("IX","VIIII");
  assertConvertSubtractiveToAdditivePrefix("XL","XXXX");
  assertConvertSubtractiveToAdditivePrefix("XC","LXXXX");
  assertConvertSubtractiveToAdditivePrefix("CD","CCCC");
  assertConvertSubtractiveToAdditivePrefix("CM","DCCCC");
}
END_TEST

START_TEST(testConvertSubtractiveToAdditivePrefixSubstring)
{
  assertConvertSubtractiveToAdditivePrefix("XIV","XIIII");
  assertConvertSubtractiveToAdditivePrefix("CXLII","CXXXXII");
  assertConvertSubtractiveToAdditivePrefix("CXLIV","CXXXXIIII");
}
END_TEST

START_TEST(testConvertAdditiveToSubtractiveInputHasNoPrefix)
{
  assertConvertAdditiveToSubtractivePrefix("ECHO","ECHO");
  assertConvertAdditiveToSubtractivePrefix("III","III");
}
END_TEST

START_TEST(testConvertSubtractiveToAdditiveInputHasNoPrefix)
{
  assertConvertSubtractiveToAdditivePrefix("ECHO","ECHO");
  assertConvertSubtractiveToAdditivePrefix("III","III");
}
END_TEST

START_TEST(testConvertInternalSumsInputHasNoSum)
{
  assertInternalSums("ECHO","ECHO");
  assertInternalSums("III","III");
}
END_TEST

START_TEST(testConvertMultipleInternalSums)
{
  assertInternalSums("VIIIII","X");
  assertInternalSums("VIIIIII","XI");
  assertInternalSums("CLXXXXVIIIIIII","CCII");
}
END_TEST

START_TEST(testConvertInternalSums)
{
  assertInternalSums("IIIII","V");
  assertInternalSums("VV","X");
  assertInternalSums("XXXXX","L");
  assertInternalSums("LL","C");
  assertInternalSums("CCCCC","D");
  assertInternalSums("DD","M");
}
END_TEST

START_TEST(testConvertToSubtractivePrefix)
{
  assertConvertAdditiveToSubtractivePrefix("IIII","IV");
  assertConvertAdditiveToSubtractivePrefix("VIIII","IX");
  assertConvertAdditiveToSubtractivePrefix("XXXX","XL");
  assertConvertAdditiveToSubtractivePrefix("LXXXX","XC");
  assertConvertAdditiveToSubtractivePrefix("CCCC","CD");
  assertConvertAdditiveToSubtractivePrefix("DCCCC","CM");
}
END_TEST

START_TEST(testConvertToSubtractivePrefix_substring)
{
  assertConvertAdditiveToSubtractivePrefix("XIIII","XIV");
  assertConvertAdditiveToSubtractivePrefix("CXXXXII","CXLII");
  assertConvertAdditiveToSubtractivePrefix("CXXXXIIII","CXLIV");
}
END_TEST

static void assertInternalSums(char *input, char *expected){
  char result[1000] = {'\0'};
  convertInternalSums(input, result);
  ck_assert_str_eq(result, expected);
}

static void assertConvertSubtractiveToAdditivePrefix(char *input, char *expected){
  char result[1000] = {'\0'};
  convertSubtractiveToAdditivePrefix(input, result);
  ck_assert_str_eq(result, expected);
}

static void assertConvertAdditiveToSubtractivePrefix(char *input, char *expected){
  char result[1000] = {'\0'};
  convertAdditiveToSubtractivePrefix(input, result);
  ck_assert_str_eq(result, expected);
}

Suite * makeRomanNumeralsConverterSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Roman Numerals Converter Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testConvertSubtractiveToAdditivePrefixes);
    tcase_add_test(tcCore, testConvertSubtractiveToAdditivePrefixSubstring);
    tcase_add_test(tcCore, testConvertAdditiveToSubtractiveInputHasNoPrefix);
    tcase_add_test(tcCore, testConvertSubtractiveToAdditiveInputHasNoPrefix);
    tcase_add_test(tcCore, testConvertInternalSumsInputHasNoSum);
    tcase_add_test(tcCore, testConvertInternalSums);
    tcase_add_test(tcCore, testConvertMultipleInternalSums);
    tcase_add_test(tcCore, testConvertToSubtractivePrefix);
    tcase_add_test(tcCore, testConvertToSubtractivePrefix_substring);
    suite_add_tcase(s, tcCore);

    return s;
}
