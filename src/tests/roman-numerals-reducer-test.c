#include <check.h>
#include "../main/roman-numerals-reducer.h"

static void assertReduceNumerals(char *input, char *reduceBy, char *expected);

START_TEST(testReduce)
{
  assertReduceNumerals("","","");
}
END_TEST

static void assertReduceNumerals(char *input, char *reduceBy, char *expected){
  char result[100] = {'\0'};
  reduceMatchingNumerals(input, reduceBy, result);
  ck_assert_str_eq(result, expected);
}

Suite * makeRomanNumeralsReducerSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Roman Numerals Reducer Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testReduce);
    suite_add_tcase(s, tcCore);

    return s;
}
