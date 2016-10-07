#include <check.h>
#include "../main/roman-numerals-reducer.h"

static void assertReduceNumerals(char *input, char *reduceBy, char *expected);

START_TEST(testReduceSingleValue)
{
  assertReduceNumerals("II","I","I");
  assertReduceNumerals("VII","V","II");
}
END_TEST

START_TEST(testReduceMultipleValues)
{
  assertReduceNumerals("III","II","I");
  assertReduceNumerals("CVII","VI","CI");
}
END_TEST

START_TEST(testExpandRightSideWhenCannotReduceRemainder)
{
  assertReduceNumerals("X","V","V");// VV-V -> V
  assertReduceNumerals("XX","XII","VIII");//X-II -> VV -> VIIIII-II -> VIII
  assertReduceNumerals("L","II","XXXXVIII");//XXXXX -> XXXXVV -> XXXXVIIIII
}
END_TEST

START_TEST(testDoNotExpandSecondTimeIfNoRemaineder)
{
  assertReduceNumerals("L","X","XXXX");//XXXXX -> XXXX Not XXXVV
}
END_TEST


START_TEST(testMultiplePasses)
{
  assertReduceNumerals("XX","XVII","III");// X-VII -> VV -> V-II -> IIIII -> IIIII-II -> III
  assertReduceNumerals("C","LXV","XXXV");//C -> LL-LXV -> L-XV -> XXXX-V -> XXXV
  assertReduceNumerals("C","LV","XXXXV");//C -> LL-LV -> L-V -> XXXXX-V -> XXXXVV-V -> XXXXV
}
END_TEST

START_TEST(testStopOn30Loops)
{
  assertReduceNumerals("VIIIIIIIIIIIIIIIIIIIIIIIIIIIII" ,"IIIIIIIIIIIIIIIIIIIIIIIIIIIII","V");
  assertReduceNumerals("VIIIIIIIIIIIIIIIIIIIIIIIIIIIII", "IIIIIIIIIIIIIIIIIIIIIIIIIIIIII","REDUCER FAILED");
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

    tcase_add_test(tcCore, testReduceSingleValue);
    tcase_add_test(tcCore, testReduceMultipleValues);
    tcase_add_test(tcCore, testExpandRightSideWhenCannotReduceRemainder);
    tcase_add_test(tcCore, testDoNotExpandSecondTimeIfNoRemaineder);
    tcase_add_test(tcCore, testMultiplePasses);
    tcase_add_test(tcCore, testStopOn30Loops);
    suite_add_tcase(s, tcCore);

    return s;
}
