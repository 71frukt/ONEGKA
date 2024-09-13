#ifndef FORMAT_FILE_H
#define FORMAT_FILE_H

#include <stdio.h>

const int LINE_LEN = 30;

void FormFile(FILE *orig_file, FILE *target_file);
bool IsRomanDigit(char ch);
void SkipExtra(FILE *file);
void SkipRomanDigits(FILE *file, char *p_curr_ch);

#endif