#include <check.h>
#include "../main/roman-numerals-sorter.h"

START_TEST(testSortRomanNumerals)
{
  ck_assert_str_eq(sortRomanNumerals("VI"),"VI");
  ck_assert_str_eq(sortRomanNumerals("IV"),"VI");
  ck_assert_str_eq(sortRomanNumerals("XICL"),"CLXI");
  ck_assert_str_eq(sortRomanNumerals("XIICLI"),"CLXIII");
  ck_assert_str_eq(sortRomanNumerals("IIVII"),"VIIII");
}
END_TEST

START_TEST(testSortLongestRomanNumerals)
{
  ck_assert_str_eq(sortRomanNumerals("MXIDXVIMCXMILCC"),"MMMDCCCLXXXVIII");
}
END_TEST

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
