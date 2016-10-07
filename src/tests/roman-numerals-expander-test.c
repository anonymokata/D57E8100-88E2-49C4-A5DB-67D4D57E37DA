#include <check.h>
#include "../main/roman-numerals-expander.h"

static void assertExpandNumerals(char *input, char expandBy, char *expected);

START_TEST(testExpandSingleNumeral)
{
  assertExpandNumerals("V",'V',"IIIII");
  assertExpandNumerals("X",'X',"VV");
  assertExpandNumerals("L",'L',"XXXXX");
  assertExpandNumerals("C",'C',"LL");
  assertExpandNumerals("D",'D',"CCCCC");
  assertExpandNumerals("M",'M',"DD");
}
END_TEST

START_TEST(testExpandRightMostOnly)
{
  assertExpandNumerals("LXV",'V',"LXIIIII");
  assertExpandNumerals("LX",'X',"LVV");
  assertExpandNumerals("ML",'L',"MXXXXX");
  assertExpandNumerals("MC",'C',"MLL");
  assertExpandNumerals("MM",'M',"MDD");
  assertExpandNumerals("MD",'D',"MCCCCC");
  assertExpandNumerals("VV",'V',"VIIIII");
  assertExpandNumerals("MDCLXV",'V',"MDCLXIIIII");
}
END_TEST

START_TEST(testExpandFirstNumeralLargerThanExpandBy)
{
  assertExpandNumerals("XI",'V',"VVI");
  assertExpandNumerals("XXII",'V',"XVVII");
  assertExpandNumerals("LX",'X',"LVV");
  assertExpandNumerals("LX",'I',"LVV");
  assertExpandNumerals("MDLXVI",'C',"MCCCCCLXVI");
}
END_TEST

static void assertExpandNumerals(char *input, char expandBy, char *expected){
  char result[100] = {'\0'};
  expandNumerals(input, expandBy, result);
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
    tcase_add_test(tcCore, testExpandFirstNumeralLargerThanExpandBy);

    suite_add_tcase(s, tcCore);

    return s;
}
