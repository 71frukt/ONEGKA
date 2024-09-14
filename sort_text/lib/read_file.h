#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdio.h>

enum ReadFileCode 
{
    READ_OK,
    ERR_READ
};

struct Line
{
    char *line_cont;
    int length;
};


struct TextInfo
{
    size_t length;
    char *text_cont;

    size_t num_lines;
    Line **p_lines; // TODO: struct { char *line; size_t line_len}
};

ReadFileCode ReadFile(FILE *file, TextInfo *text_info);
void PutPointers(TextInfo *text_info);
int SetEndsOfLines(char *text, int text_len);
Line **CallocP_Lines(size_t num_lines);

#endif