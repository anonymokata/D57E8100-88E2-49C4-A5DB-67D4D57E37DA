#include <check.h>
#include "calculator.h"

START_TEST(addtest)
{
  ck_assert_str_eq(add("I","I"),"II");
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
  tcase_add_test(tc1_1, addtest);

  srunner_run_all(sr, CK_ENV);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
