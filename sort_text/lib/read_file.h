#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdio.h>

enum ReadFileCode 
{
    GOOD_READ,
    ERR_READ
};

struct TextInfo
{
    size_t length;
    char *content;

    size_t num_lines;
    char **p_lines;
};

ReadFileCode ReadFile(FILE *file, TextInfo *text_info);
void PutPointers(TextInfo *text_info);

#endif