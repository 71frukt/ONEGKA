#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <assert.h>
#include <string.h>
//#include "TXLib.h"

#include "read_file.h" 

ReadFileCode ReadFile(FILE *file, TextInfo *text_info)
{
    assert(file);
    assert(text_info); 

    struct stat file_info = {};

    if (fstat(fileno(file), &file_info) < 0)
    {
        printf("Error reading files\n");
        return ERR_READ;
    }
    
    int prev_text_len = file_info.st_size + 1;

    char *text = (char*) calloc(prev_text_len, sizeof(char));
    int real_text_len = fread(text, sizeof(char), prev_text_len, file) + 1;

    int num_lines = SetEndsOfLines(text, real_text_len);

    text_info->text_cont = text;
    text_info->length    = real_text_len;
    text_info->num_lines = num_lines;

    return READ_OK;
}

void PutPointers(TextInfo *text_info)
{
    assert(text_info);

    text_info->p_lines = CallocP_Lines(text_info->num_lines);

    text_info->p_lines[0]->line_cont = text_info->text_cont;

    for (size_t el_num = 1, line_num = 1; line_num < text_info->num_lines; el_num++)
    {
        assert(el_num < text_info->length);

        if (text_info->text_cont[el_num] == '\0')
        {
            text_info->p_lines[line_num]->line_cont = &text_info->text_cont[el_num + 1];
            text_info->p_lines[line_num]->length = strlen(&text_info->text_cont[el_num + 1]);

            line_num++;
        }
    }
}

int SetEndsOfLines(char *text, int text_len)
{    
    assert(text);

    int num_lines = 0; 

    int i = 0;
    for (i = 0; i < text_len; i++)
    {
        if (text[i] == '\n') 
        {
            text[i] = '\0';
            num_lines++;
        }
    }

    text[i] = '\0';     // в последней строке могло не быть '\n', поэтому

    return num_lines;
}

Line **CallocP_Lines(size_t num_lines)
{
    Line **res_ptr = (Line**) calloc(num_lines, sizeof(Line*));
    Line *lines_ptr = (Line *) calloc(num_lines, sizeof(Line));

    for (size_t i = 0; i < num_lines; i++)
    {
        res_ptr[i] = lines_ptr + i;
    }

    return res_ptr;
}