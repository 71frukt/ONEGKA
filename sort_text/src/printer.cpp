#include <stdio.h>
#include <assert.h>

#include "read_file.h"
#include "printer.h"

void FprintLines(FILE *file, Line **p_lines, size_t num_lines)
{
    assert(file);
    assert(p_lines);

    for (size_t i = 0; i < num_lines; i++)
        fprintf(file, "%s\n", p_lines[i]->line_cont);

        //fputs(p_lines[i], file);
}