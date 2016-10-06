#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *expandIndex[6] = {"V","X","L","C","D","M"};
static char *expandValue[6] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};

void expandNumerals(char *romanNumerals, char result[]){
  char *lastNumeral = &romanNumerals[(strlen(romanNumerals)-1)];
  char expandedNumerals[5] = {'\0'};

  for (int i = 0; i < 6; i++) {
    if(strcmp(expandIndex[i], lastNumeral) == 0){
      strcpy(expandedNumerals, expandValue[i]);
    }
  }

  strcat(result, romanNumerals);
  result[strlen(romanNumerals)-1] = '\0';
  strcat(result, expandedNumerals);
}
