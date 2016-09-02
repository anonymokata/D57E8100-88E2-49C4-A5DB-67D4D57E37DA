#include <check.h>
#include "../main/common-utils.h"

START_TEST(test_replaceSubstring)
{
  ck_assert_str_eq(replaceSubstring("Hello World", "World", "Michigan"),"Hello Michigan");
  ck_assert_str_eq(replaceSubstring("Hello World. Hello Universe", "World", "Michigan"),"Hello Michigan. Hello Universe");
  ck_assert_str_eq(replaceSubstring("CXLIIII", "XL", "XXXX"),"CXXXXIIII");
  ck_assert_str_eq(replaceSubstring("A", "A", "ABC"),"ABC");
}
END_TEST

START_TEST(test_replace_entire_string)
{
  ck_assert_str_eq(replaceSubstring("Hello", "Hello", "World"),"World");
}
END_TEST

START_TEST(test_concatenate_string)
{
  ck_assert_str_eq(concatenate("foo", "bar"), "foobar");
  ck_assert_str_eq(concatenate("short", " loooooooooooong"), "short loooooooooooong");
  ck_assert_str_eq(concatenate("loooooooooooong ", "short"), "loooooooooooong short");
}
END_TEST

Suite * make_common_utils_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Common Utils Suite");
    tc_core = tcase_create("Core");


    tcase_add_test(tc_core, test_replaceSubstring);
    tcase_add_test(tc_core, test_replace_entire_string);
    tcase_add_test(tc_core, test_concatenate_string);

    suite_add_tcase(s, tc_core);

    return s;
}
