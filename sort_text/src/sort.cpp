#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "sort.h"

void MySort(void *arr, size_t ar_size, size_t el_size, int (*compare) (void *str_1, void *str_2))
{
    assert(arr);
    assert(compare);

    int left = 0;
    int right = ar_size - 1;

    char *p_arr = (char*) arr;
    char *pivot = p_arr; 

    /*
    for (int i = 0; i < ar_size; i++)
    {
        for (int j = 0; j < ar_size - 1; j++)
        {
            if (compare(p_arr + j * el_size, p_arr + (j + 1) * el_size) > 0)
            {
                void *p_tmp = calloc(1, sizeof(el_size));

                memcpy(p_tmp,                       p_arr + j * el_size,        el_size);
                memcpy(p_arr + j * el_size,         p_arr + (j + 1) * el_size,  el_size);
                memcpy(p_arr + (j + 1) * el_size,   p_tmp,                      el_size);

                free(p_tmp);
            }
        }
    }
    */

    //for (int i = 0; i < 10; i++)
        //putchar(*(p_arr));
    
    while (left <= right)
    { 
        while (compare(p_arr + left * el_size, pivot) < 0 && left <= right)
            left++;
        
        while (compare(p_arr + right * el_size, pivot) > 0 && left <= right)
            right--;    
        
        if(left > right)
            break;

        Swap(p_arr + left  * el_size, p_arr + right * el_size, el_size);    

        left++;
        right--;
    }  
    if (left >= 2)
        MySort(p_arr, left, el_size, compare);
    
    if ((ar_size - left) >= 2)
        MySort((p_arr + left * sizeof(void*)), ar_size - left, el_size, compare);
    
}

int StrCompare(void *str_1, void *str_2)
{
    assert(str_1);
    assert(str_2);

    //printf("\ncomparator:\n");
    //printf("(%s) %02x %02x %02x %02x\n", str_1, ((unsigned char*)str_1)[0], ((unsigned char*)str_1)[1], ((unsigned char*)str_1)[2], ((unsigned char*)str_1)[3]);

    //printf("(%s) %02x %02x %02x %02x\n", str_2, ((unsigned char*)str_2)[0], ((unsigned char*)str_2)[1], ((unsigned char*)str_2)[2], ((unsigned char*)str_2)[3]);

    char **line_1 = (char**) str_1;
    char **line_2 = (char**) str_2;
    
    char *cont_1 = *line_1;
    char *cont_2 = *line_2;

    for (int i = 0, k = 0; cont_1[i] != '\0' || cont_2[k] != '\0'; i++, k++)
    {
        if (!isalpha(cont_1[i]))
        {
            k--; 
            continue;
        }

        if (!isalpha(cont_2[k]))
        {
            i--;
            continue;
        }
        
        if (toupper(cont_1[i]) > toupper(cont_2[k]) || cont_2[k] == '\0')
            return 1;
        
        else if (toupper(cont_2[k]) > toupper(cont_1[i]) || cont_1[i] == '\0')
            return -1;
    }

    return 0;
}

int StrReverceCompare(void *str_1, void *str_2)
{
    assert(str_1);
    assert(str_2);

    char **line_1 = (char**) str_1;
    char **line_2 = (char**) str_2;
    
    char *cont_1 = *line_1;
    char *cont_2 = *line_2;

    int len_1 = strlen(cont_1);
    int len_2 = strlen(cont_2);

    for (int i = 1, k = 1; cont_1[i] != '\0' || cont_2[k] != '\0'; i++, k++)    //пока оба указателя не дойдут до конца предыдущей строки
    {
        int num_1 = len_1 - i;
        int num_2 = len_2 - k;

        if (!isalpha(cont_1[num_1]))
        {
            k--; 
            continue;
        }

        if (!isalpha(cont_2[num_2]))
        {
            i--;
            continue;
        }
        
        if (toupper(cont_1[num_1]) > toupper(cont_2[num_2]) || cont_2[num_2] == '\0')
            return 1;
        
    
        else if (toupper(cont_2[num_2]) > toupper(cont_1[num_1]) || cont_1[num_1] == '\0')
            return -1;
    }

    return 0;
}

// пример другого компаратора

int DigCompare(void *i1, void *i2)
{
    int d1 = *((int*) i1);
    int d2 = *((int*) i2);

    if (d1 > d2)
        return 1;
    else if (d2 > d1)
        return -1;
    return 0;
}


void Swap(void *ptr1, void *ptr2, size_t el_size)
{
    assert(ptr1);
    assert(ptr2);
    assert(ptr1 != ptr2);

    char *p_elem_1 = (char*) ptr1;
    char *p_elem_2 = (char*) ptr2;

    for (size_t i = 0; i < el_size; i++)
    {
        char byte = p_elem_1[i];
        p_elem_1[i] = p_elem_2[i];
        p_elem_2[i] = byte;
    }
}