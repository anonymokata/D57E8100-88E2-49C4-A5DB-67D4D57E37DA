#ifndef ROMAN_NUMERALS_CONVERTER_H_
#define ROMAN_NUMERALS_CONVERTER_H_

char *convertSubtractiveToAdditivePrefix(const char *romanNumerals, char result[]);
char *convertAdditiveToSubtractivePrefix(const char *romanNumerals, char result[]);
char *convertInternalSums(const char *romanNumerals, char result[]);

#endif
