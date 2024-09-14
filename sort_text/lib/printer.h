#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>
#include "read_file.h"

void FprintLines(FILE *file, Line **p_lines, size_t num_lines);

#endif