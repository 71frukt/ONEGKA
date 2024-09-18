#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <assert.h>
#include <string.h>
//#include "TXLib.h"

#include "read_file.h" 

GetTextInfoCode GetTextInfo(FILE *file, TextInfo *text_info)
{    
    if (ReadFile(file, text_info) != READ_OK)
    {
        text_info = NULL;
        return GET_TXT_ERROR;
    }

    PutPointers(text_info);
    return GET_TXT_OK;
} 


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
    if (prev_text_len == 0)
    {
        printf("The file is empty!\n");
        return ERR_READ;
    } 

    char *text = (char*) calloc(prev_text_len, sizeof(char));
    
    int real_text_len = fread(text, sizeof(char), prev_text_len, file);

    int num_lines = SetEndsOfLines(text, real_text_len);

    text_info->text_cont = text;
    text_info->length    = real_text_len;
    text_info->num_lines = num_lines;

    return READ_OK;
}

void PutPointers(TextInfo *text_info)
{
    assert(text_info);

    text_info->p_lines = Calloc_Ptr_Lines(text_info->num_lines);

    text_info->p_lines[0]->line_cont = text_info->text_cont;

    for (size_t el_num = 1, line_num = 1; line_num < text_info->num_lines; el_num++)
    {
        assert(el_num < text_info->length);

        if (text_info->text_cont[el_num] == '\0')
        {
            text_info->p_lines[line_num]->line_cont = &text_info->text_cont[el_num + 1];
            text_info->p_lines[line_num]->length    = strlen(&text_info->text_cont[el_num + 1]);

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

Line **Calloc_Ptr_Lines(size_t num_lines)
{
    Line **res_ptr  = (Line**) calloc(num_lines, sizeof(Line*));
    Line *lines_ptr = (Line *) calloc(num_lines, sizeof(Line));

    for (size_t i = 0; i < num_lines; i++)
        res_ptr[i] = lines_ptr + i;

    return res_ptr;
}

void CopyTextInfos(TextInfo *text_info_to, TextInfo *text_info_from)
{
    text_info_to->length    = text_info_from->length;
    text_info_to->num_lines = text_info_from->num_lines;
    text_info_to->text_cont = text_info_from->text_cont;

    text_info_to->p_lines = Calloc_Ptr_Lines(text_info_from->num_lines);

    for (size_t i = 0; i < text_info_to->num_lines; i++)
        text_info_to->p_lines[i] = text_info_from->p_lines[i];
}