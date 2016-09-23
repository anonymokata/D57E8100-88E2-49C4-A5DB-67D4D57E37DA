#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main/calculator.h"

static const char *getfield(char* line, int num);

START_TEST(testAddData)
{
  FILE* stream = fopen("src/tests/fitness-test-data", "r");

  char line[1024];
  while (fgets(line, 1024, stream))
  {

      char *firstNumeral = calloc(100, sizeof(char));
      char *secondNumeral = calloc(100, sizeof(char));
      char *expectedNumeral = calloc(100, sizeof(char));
      char *actualNumeral = calloc(100, sizeof(char));
      strcat(firstNumeral, getfield(strdup(line), 1));
      strcat(secondNumeral, getfield(strdup(line), 2));
      strcat(expectedNumeral, getfield(strdup(line), 3));

      strcat(actualNumeral, add(firstNumeral, secondNumeral));
      strcat(actualNumeral, "\n");

      ck_assert_str_eq(actualNumeral, expectedNumeral);
      free(firstNumeral);
      free(secondNumeral);
      free(actualNumeral);
      free(expectedNumeral);
  }
}
END_TEST

const char *getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok != NULL;
            tok = strtok(NULL, ","))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

Suite * makeFitnessSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Fitness Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testAddData);
    suite_add_tcase(s, tcCore);

    return s;
}
