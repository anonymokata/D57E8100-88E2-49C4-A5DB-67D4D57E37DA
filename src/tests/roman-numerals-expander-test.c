#include <check.h>
#include "../main/roman-numerals-expander.h"

static void assertExpandNumerals(char *input, char *expected);

START_TEST(testExpandSingleNumeral)
{
  assertExpandNumerals("V","IIIII");
  assertExpandNumerals("X","VV");
  assertExpandNumerals("L","XXXXX");
  assertExpandNumerals("C","LL");
  assertExpandNumerals("D","CCCCC");
  assertExpandNumerals("M","DD");
}
END_TEST

START_TEST(testExpandRightMostOnly)
{
  assertExpandNumerals("LXV","LXIIIII");
  assertExpandNumerals("LX","LVV");
  assertExpandNumerals("ML","MXXXXX");
  assertExpandNumerals("MC","MLL");
  assertExpandNumerals("MD","MCCCCC");
  assertExpandNumerals("MM","MDD");
  assertExpandNumerals("VV","VIIIII");
  assertExpandNumerals("MDCLXV","MDCLXIIIII");
}
END_TEST

static void assertExpandNumerals(char *input, char *expected){
  char result[100] = {'\0'};
  expandNumerals(input, result);
  ck_assert_str_eq(result, expected);
}

Suite * makeRomanNumeralsExpanderSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Roman Numerals Reducer Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testExpandSingleNumeral);
    tcase_add_test(tcCore, testExpandRightMostOnly);

    suite_add_tcase(s, tcCore);

    return s;
}
