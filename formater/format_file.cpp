#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#include "format_file.h"

int main (int argc, const char* argv[]) 
{
    FILE *orig_onegin = fopen((argc >= 2) ? argv[1] : ORIG_TEXT_DEFAULT_PATH, "r");
    FILE *form_onegin = fopen((argc >= 3) ? argv[2] : FORM_TEXT_DEFAULT_PATH, "w");

    FormFile(orig_onegin, form_onegin);

    fclose(orig_onegin);
    fclose(form_onegin);

    return 0;
}

void FormFile(FILE *orig_file, FILE *target_file)
{
    assert(orig_file);
    assert(target_file);
    assert(orig_file != target_file);

    char line[LINE_LEN] = {};

    while (true)
    {
        SkipExtra(orig_file);

        if (fgets(line, LINE_LEN, orig_file) != NULL)
            fputs(line, target_file);
        
        else
            break;
    } 
}

bool IsRomanDigit(char ch)
{
    return (ch == 'I' || ch == 'V' || ch == 'X' || ch == 'L') ? true : false; 
}

void SkipExtra(FILE *file)
{
    assert(file);
    
    char curr_ch = 0;

    while (curr_ch != EOF) 
    {
        SkipRomanDigits(file, &curr_ch);

        if (isspace(curr_ch) || !isalpha(curr_ch))
            curr_ch = (char) fgetc(file);

        else
            break;
    }
    
    ungetc(curr_ch, file);
}

void SkipRomanDigits(FILE *file, char *p_curr_ch)
{
    assert(file);
    assert(p_curr_ch);

    if (IsRomanDigit(*p_curr_ch)) 
    {
        char next_ch = (char) fgetc(file);

        if (IsRomanDigit(next_ch))
            while (IsRomanDigit(*p_curr_ch = (char) fgetc(file)))
                continue;

        while (isspace(next_ch))
        {
            if (next_ch == '\n')
            {
                *p_curr_ch = next_ch;
                break;
            }

            next_ch = (char) fgetc(file);
        }
    }
}

