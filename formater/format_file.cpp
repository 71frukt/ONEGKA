#include <stdio.h>
#include <ctype.h>
#include <assert.h>

void FormFile(FILE *orig_file, FILE *target_file);
const int LINE_LEN = 30;

int main()
{
    FILE *orig_onegin = fopen("orig_onegin.txt", "r");
    FILE *form_onegin = fopen("form_text.txt", "w+");

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

    int i = 0;
    while (true)
    {
        char curr_ch = 0;
        while ((isspace(curr_ch) || !isalpha(curr_ch)) && curr_ch != EOF)
            curr_ch = fgetc(orig_file);
        
        ungetc(curr_ch, orig_file);

        if (fgets(line, LINE_LEN, orig_file) != NULL)
            fputs(line, target_file);

        else
            break;

    } 
}