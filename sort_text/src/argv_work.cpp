#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "argv_work.h"

OpenFilesRes OpenGettedFiles(const int argc, const char *argv[], FILE **file_from, FILE **file_to)
{
    assert(argv);
    assert(file_from);
    assert(file_to);
    assert(file_from != file_to);

    char path_from[MAX_PATH_LEN] = {};
    char path_to  [MAX_PATH_LEN] = {};
    
    int max_cpy_len = MAX_PATH_LEN - MAX_FOLDNAME_LEN - 1;

    GetPath(path_from, FOLD_NAME, argv[1], MAX_FOLDNAME_LEN, max_cpy_len);
    GetPath(path_to,   FOLD_NAME, argv[2], MAX_FOLDNAME_LEN, max_cpy_len);

    *file_from = fopen(path_from, "r");   
    *file_to   = fopen(path_to,   "w");    

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

void GetPath(char *res_path, const char *folder, const char *name, size_t max_foldname_len, size_t max_path_name)
{
    assert(res_path);
    assert(folder);
    assert(name);

    strncat(res_path, folder, max_foldname_len);
    strncat(res_path, name,   max_path_name - max_foldname_len - 1);
}