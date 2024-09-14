#include <stdio.h>
#include <assert.h>

#include "argv_work.h"

OpenFilesRes OpenGettedFiles(const int argc, const char *argv[], FILE **file_from, FILE **file_to)
{
    assert(argv);
    assert(file_from);
    assert(file_to);
    assert(file_from != file_to);

    *file_from = fopen(argv[1], "r");
    *file_to = fopen(argv[2], "w+");

    if (argc < 3)
    {
        printf("ERROR: NO ARGUMENTS\n");
        return ARGC_ERR;
    }

    else if (file_from == NULL || file_to == NULL)
    {
        perror("");
        return ERROR_OPEN;
    }

    else
        return OPEN_OK;
}