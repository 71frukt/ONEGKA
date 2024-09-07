#include <stdio.h>

const int lines_len = 20;
const int lines_count = 3;

int main()
{
    char lines[lines_count][lines_len] = { "Stepa loshjpet", "ArsDer loshpet", "chto-to esho" };

    char *p_lines[lines_count];

    for (int i = 0; i < lines_count; i++)
        p_lines[i] = lines[i];

    for (int i = 0; i < lines_count; i++)
        printf("%s\n",p_lines[i]);
}