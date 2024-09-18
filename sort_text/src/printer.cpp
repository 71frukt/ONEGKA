#include <stdio.h>
#include <assert.h>

#include "read_file.h"
#include "printer.h"

void FprintText(FILE *file, const TextInfo *text_info) 
{
    assert(file);
    assert(text_info);

    for (size_t i = 0; i < text_info->num_lines; i++)
        fprintf(file, "%s\n", text_info->p_lines[i]->line_cont);

        //fputs(p_lines[i], file);
}

void FprintSeparator(FILE *file)
{
    for (size_t i = 0; i < 50; i++)
        fprintf(file, "\n");

    for (size_t i = 0; i < 50; i++)
    {
        for (size_t k = 0; k < 100; k++)
            fprintf(file, "MALLOC");

        fprintf(file, "\n");
    }

    for (size_t i = 0; i < 50; i++)
        fprintf(file, "\n");
}