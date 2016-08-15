#include <check.h>
#include "../main/common-utils.h"

START_TEST(test_replace_substring)
{
  ck_assert_str_eq(replace_substring("Hello World", "World", "Michigan"),"Hello Michigan");
  ck_assert_str_eq(replace_substring("Hello World. Hello Universe", "World", "Michigan"),"Hello Michigan. Hello Universe");
}
END_TEST

Suite * make_common_utils_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Common Utils Suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_replace_substring);
    suite_add_tcase(s, tc_core);

    return s;
}
