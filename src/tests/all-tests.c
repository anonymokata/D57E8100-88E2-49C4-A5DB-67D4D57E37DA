#include <check.h>
#include "calculator-test.h"
#include "roman-numerals-sorter-test.h"
#include "roman-numerals-converter-test.h"
#include "common-utils-test.h"

int main(void)
{
  Suite *s1 = suite_create("All");
  SRunner *sr = srunner_create(s1);
  int number_failed;
  int EXIT_SUCCESS = 0;
  int EXIT_FAILURE = 1;

  srunner_add_suite (sr, make_calculator_suite());
  srunner_add_suite (sr, make_roman_numerals_sorter_suite());
  srunner_add_suite (sr, make_roman_numerals_converter_suite());
  srunner_add_suite (sr, make_common_utils_suite());

  srunner_run_all(sr, CK_ENV);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
