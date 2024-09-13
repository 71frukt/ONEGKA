#include <stdio.h>
#include <assert.h>

#include "argv_work.h"

void OpenGettedFiles(const char *argv[], FILE **file_from, FILE **file_to)
{
    assert(argv);
    assert(file_from);
    assert(file_to);
    assert(file_from != file_to);

    *file_from = fopen(argv[1], "r");
    *file_to = fopen(argv[2], "w+");
}