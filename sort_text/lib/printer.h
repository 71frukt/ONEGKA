#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>
#include "read_file.h"

void FprintText(FILE *file, const TextInfo *text_info);
void FprintSeparator(FILE *file);

#endif