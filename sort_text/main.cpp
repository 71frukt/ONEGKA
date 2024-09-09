#include <stdio.h>
#include <string.h>
#include <sys\stat.h>

#include "sort.h"

struct stat file_info;

const int LINES_LEN = 100;
const int LINES_COUNT = 7000;

int ReadFile(char buf[][LINES_LEN], int lines_count, FILE *file);

int main()
{
    FILE *text_file = fopen("C:/Users/71fru/Documents/GitHub/ONEGKA/formater/form_text.txt", "r");
    int text_size = file_info.st_size;

    if (fstat(fileno(text_file), &file_info) != 0)
        printf("Descriftor of file is incorrect");

    char lines[LINES_COUNT][LINES_LEN] = {};

    ReadFile(lines, LINES_COUNT, text_file);

    char *p_lines[LINES_COUNT] = {};

    for (int i = 0; i < LINES_COUNT; i++)
        p_lines[i] = lines[i];

    /*
    for (int i = 0; i < LINES_COUNT; i++)
        printf("%p ", p_lines[i]);
    printf("\n");
    */

    MySort(p_lines, LINES_COUNT, sizeof(p_lines[0]), StrCompare);

    for (int i = 0; i < LINES_COUNT; i++)
        printf("%s", p_lines[i]);

    fclose(text_file);
}

int ReadFile(char buf[][LINES_LEN], int lines_count, FILE *file)
{
    int i = 0;
    for (i = 0; i < LINES_COUNT; i++)
        fgets(buf[i], LINES_LEN - 1, file);     // -1 для последней строки, где приходится записывать \n вручную

    int len = strlen(buf[i]);

    buf[i][len] = '\n';
    buf[i][len + 1] = '\0';
}