#ifndef ARGV_WORK_H
#define ARGV_WORK_H

#include <stdio.h>

#define TXT_FOLDER "texts"

#define GET_PATH(PATH, NAME) PATH NAME

enum OpenFilesRes
{
    OPEN_OK,
    ARGC_ERR,
    ERROR_OPEN
};

OpenFilesRes OpenGettedFiles(const int argc, const char *argv[], FILE **file_from, FILE **file_to);

#endif