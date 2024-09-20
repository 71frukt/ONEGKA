#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "sort.h"

void MyQSort(void *arr, size_t ar_size, size_t el_size, int (*compare) (void *str_1, void *str_2))
{
    assert(arr);
    assert(compare);

    int left = 0;
    int right = ar_size - 1;

    char *p_arr = (char*) arr;
    char *pivot = p_arr; 
    
    while (left <= right)
    { 
        while (compare(p_arr + left * el_size, pivot) < 0 && left <= right)
            left++;
        
        while (compare(p_arr + right * el_size, pivot) > 0 && left <= right)
            right--;    
        
        if (left > right)
            break;

        Swap(p_arr + left  * el_size, p_arr + right * el_size, el_size);    

        left++;
        right--;
    } 

    if (left >= 2)
        MyQSort(p_arr, left, el_size, compare);
    
    if ((ar_size - left) >= 2)
        MyQSort((p_arr + left * sizeof(void*)), ar_size - left, el_size, compare);   
}

void Swap(void *ptr1, void *ptr2, size_t el_size)
{
    assert(ptr1);
    assert(ptr2);

    if (ptr1 == ptr2)
        return;

    char *p_elem_1 = (char*) ptr1;
    char *p_elem_2 = (char*) ptr2;

    for (size_t i = 0; i < el_size; i++)
    {
        char byte = p_elem_1[i];
        p_elem_1[i] = p_elem_2[i];
        p_elem_2[i] = byte;
    }
}