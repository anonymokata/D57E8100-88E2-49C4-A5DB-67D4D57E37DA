#include <check.h>
#include "../main/roman-numerals-sorter.h"

static void assertSortNumerals(char *input, char *expected);

START_TEST(testSortRomanNumerals)
{
  assertSortNumerals("VI","VI");
  assertSortNumerals("IV","VI");
  assertSortNumerals("XICL","CLXI");
  assertSortNumerals("XIICLI","CLXIII");
  assertSortNumerals("IIVII","VIIII");
}
END_TEST

START_TEST(testSortLongestRomanNumerals)
{
  assertSortNumerals("MXIDXVIMCXMILCC","MMMDCCCLXXXVIII");
}
END_TEST

static void assertSortNumerals(char *input, char *expected){
  char result[100] = {'\0'};
  sortRomanNumerals(input, result);
  ck_assert_str_eq(result, expected);
}

Suite * makeRomanNumeralsSorterSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Roman Numerals Sorter Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testSortRomanNumerals);
    tcase_add_test(tcCore, testSortLongestRomanNumerals);
    suite_add_tcase(s, tcCore);

    return s;
}
