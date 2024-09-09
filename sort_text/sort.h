#include <stdio.h>

#ifndef SORT_H
#define SORT_H

void MySort(void *arr, size_t ar_size, size_t el_size, int (*compare) (void *str_1, void *str_2));
int StrCompare(void *str1, void *str2);

#endif