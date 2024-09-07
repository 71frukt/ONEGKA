#include <stdio.h>
#include <ctype.h>
#include <assert.h>

void FormFile(FILE *orig_file, FILE *target_file);

int main()
{
    FILE *orig_onegin = fopen("orig_onegin.txt", "r");
    FILE *form_onegin = fopen("form_onegin.txt", "w");

    FormFile(orig_onegin, form_onegin);

    fclose(orig_onegin);
    fclose(form_onegin);
}

void FormFile(FILE *orig_file, FILE *target_file)
{
    assert(orig_file);
    assert(target_file);
    assert(orig_file != target_file);

    char curr_ch = 0;

    while ((curr_ch = fgetc(orig_file)) != EOF)
    {
        while (isspace(curr_ch) || !isalpha(curr_ch))
            curr_ch = fgetc(orig_file);
        
        ungetc(curr_ch, orig_file);

        while ((curr_ch = fgetc(orig_file)) != '\n' && curr_ch != EOF)
            fputc(curr_ch, target_file);
        
        fputc('\n', target_file);
    } 
}