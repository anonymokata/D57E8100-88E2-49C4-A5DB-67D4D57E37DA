#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "roman-numerals-converter.h"
#include "roman-numerals-reducer.h"
#include "common-utils.h"

void add(char *romanNumeral1, char *romanNumeral2, char result[])
{
    char additiveNumerals1[100] = {'\0'};
    char additiveNumerals2[100] = {'\0'};
    char combinedNumerals[100] = {'\0'};
    char sortnedNumerals[100] = {'\0'};
    char internalSumsNumerals[100] = {'\0'};

    convertSubtractiveToAdditivePrefix(romanNumeral1, additiveNumerals1);
    convertSubtractiveToAdditivePrefix(romanNumeral2, additiveNumerals2);
    concatenate(additiveNumerals1, additiveNumerals2, combinedNumerals);
    sortRomanNumerals(combinedNumerals, sortnedNumerals);
    convertInternalSums(sortnedNumerals, internalSumsNumerals);
    convertAdditiveToSubtractivePrefix(internalSumsNumerals,result);

    return result;
}

void subtract(char *romanNumeral1, char *romanNumeral2, char result[]){
  char additiveNumerals1[100] = {'\0'};
  char additiveNumerals2[100] = {'\0'};

  convertSubtractiveToAdditivePrefix(romanNumeral1, additiveNumerals1);
  convertSubtractiveToAdditivePrefix(romanNumeral2, additiveNumerals2);
  reduceMatchingNumerals(additiveNumerals1, additiveNumerals2, result);
}
