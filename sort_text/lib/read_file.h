#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdio.h>

enum GetTextInfoCode
{
    GET_TXT_OK,
    GET_TXT_ERROR
};

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
    Line **p_lines;
};

GetTextInfoCode GetTextInfo(FILE *file, TextInfo *text_info);
ReadFileCode ReadFile(FILE *file, TextInfo *text_info);
void CopyTextInfos(TextInfo *text_info_to, TextInfo *text_info_from);
void PutPointers(TextInfo *text_info);
int SetEndsOfLines(char *text, int text_len);
Line **Calloc_Ptr_Lines(size_t num_lines);

#endif