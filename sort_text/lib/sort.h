#ifndef SORT_H
#define SORT_H

#include <stdio.h>

void MySort(void *arr, size_t ar_size, size_t el_size, int (*compare) (void *str_1, void *str_2));
int StrCompare(void *str_1, void *str_2);
int StrReverceCompare(void *str_1, void *str_2);
int DigCompare(void *i1, void *i2);
void Swap(void *ptr1, void *ptr2, size_t el_size);

#endif