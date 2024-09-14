#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <assert.h>
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
    
    int prev_text_len = file_info.st_size;

    char *text = (char*) calloc(prev_text_len, sizeof(char));
    int real_text_len = fread(text, sizeof(char), prev_text_len, file);

    int num_lines = SetEndsOfLines(text, real_text_len);

    text_info->content   = text;
    text_info->length    = real_text_len;
    text_info->num_lines = num_lines;

    return READ_OK;

/*
    printf("psevdo num elems: %d\n", prev_text_len);
    printf("num elems: %d\n",        real_text_len);
    printf("num lines: %d\n",        num_lines);
*/
}

void PutPointers(TextInfo *text_info)
{
    assert(text_info);

    text_info->p_lines = (char**) calloc(text_info->num_lines, sizeof(char*));

//printf("p_lines: %p\n", text_info->p_lines);

    text_info->p_lines[0] = text_info->content;

    for (size_t el_num = 1, line_num = 1; line_num < text_info->num_lines; el_num++)
    {
        assert(el_num < text_info->length);
        if (text_info->content[el_num] == '\0')
        {
            (text_info->p_lines)[line_num] = &text_info->content[el_num + 1];
//printf("p_lines[%d] : fakt - %p; norm - %p\n", line_num, (text_info->p_lines)[line_num], &(text_info->content[el_num + 1]));
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
