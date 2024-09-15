#ifndef ARGV_WORK_H
#define ARGV_WORK_H

#include <stdio.h>

#define TXT_FOLDER "texts"

#define GET_PATH(PATH, NAME) PATH NAME

const int MAX_PATH_LEN = 100;
const int MAX_FOLDNAME_LEN = 20;

const char FOLD_NAME [MAX_FOLDNAME_LEN] = "texts/";

enum OpenFilesRes
{
    OPEN_OK,
    ARGC_ERR,
    ERROR_OPEN
};

OpenFilesRes OpenGettedFiles(const int argc, const char *argv[], FILE **file_from, FILE **file_to);
void GetPath(char *res_path, const char *folder, const char *name, size_t max_foldname_len, size_t max_path_name);

#endif