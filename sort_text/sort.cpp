#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void MySort(void *arr, size_t ar_size, size_t el_size, int (*compare) (void *str_1, void *str_2))
{
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
    
    while (left < right)
    { 
        while (compare(p_arr + left * el_size, pivot) < 0 && left <= right)
            left++;
        
        while (compare(p_arr + right * el_size, pivot) > 0 && left <= right)
            right--;    
        
        if(left > right)
            break;
    

        char *ptr_left = (char*) (p_arr + left  * el_size);
        char *ptr_right = (char*) (p_arr + right * el_size);

        for (int i = 0; i < el_size; i++)
        {
            char byte = ptr_left[i];
            ptr_left[i] = ptr_right[i];
            ptr_right[i] = byte;
        }

        /*
        void *p_tmp = calloc(1, sizeof(el_size));

        memcpy(p_tmp,                     p_arr + left  * el_size,   el_size);
        memcpy(p_arr + left * el_size,    p_arr + right * el_size,   el_size);
        memcpy(p_arr + right * el_size,   p_tmp,                     el_size);

        free(p_tmp);
        char *p_tmp = p_arr + left * el_size;
        *(p_arr + left * el_size) = *(p_arr + right * el_size);
        *(p_arr + right * el_size) = *(p_tmp);
        char str_tmp[20] = {};
        strcpy(str_tmp, p_arr + left * el_size);
        strcpy(p_arr + left * el_size, p_arr + right * el_size);
        strcpy(p_arr + right * el_size, str_tmp);
        */

    
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
    //assert(str1 != str2);

    //printf("\ncomparator:\n");
    //printf("(%s) %02x %02x %02x %02x\n", str_1, ((unsigned char*)str_1)[0], ((unsigned char*)str_1)[1], ((unsigned char*)str_1)[2], ((unsigned char*)str_1)[3]);

    //printf("(%s) %02x %02x %02x %02x\n", str_2, ((unsigned char*)str_2)[0], ((unsigned char*)str_2)[1], ((unsigned char*)str_2)[2], ((unsigned char*)str_2)[3]);


    char **line_1 = (char**) str_1;
    char **line_2 = (char**) str_2;
    
    char *cont_1 = *line_1;
    char *cont_2 = *line_2;
    //printf("cont1:(%s) %p | cont2:(%s) %p\n", cont_1, cont_1, cont_2, cont_2);
    
    for (int i = 0; !(cont_1[i] == '\0' && cont_2[i] == '\0'); i++)
    {
        if (cont_1[i] > cont_2[i] || cont_2[i] == '\0')
            return 1;

        else if (cont_2[i] > cont_1[i] || cont_1[i] == '\0')
            return -1;

    }

    return 0;
}
