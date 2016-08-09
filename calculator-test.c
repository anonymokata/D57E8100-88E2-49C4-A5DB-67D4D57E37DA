#include <check.h>
#include "calculator.h"

START_TEST(concatinate_to_add)
{
  ck_assert_str_eq(add("I","I"),"II");
  ck_assert_str_eq(add("I","II"),"III");
}
END_TEST

START_TEST(max_roman_numeral)
{
  ck_assert_str_eq(add("MMDCCCLXXXVII","I"),"MMDCCCLXXXVIII");
}
END_TEST

int main(void)
{
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int number_failed;
  int EXIT_SUCCESS = 0;
  int EXIT_FAILURE = 1;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, concatinate_to_add);
  tcase_add_test(tc1_1, max_roman_numeral);

  srunner_run_all(sr, CK_ENV);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
