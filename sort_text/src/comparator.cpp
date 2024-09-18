#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "comparator.h"
#include "read_file.h"

int StrCompare(void *str_1, void *str_2)
{
    //printf("\ncomparator:\n");
    //printf("(%s) %02x %02x %02x %02x\n", str_1, ((unsigned char*)str_1)[0], ((unsigned char*)str_1)[1], ((unsigned char*)str_1)[2], ((unsigned char*)str_1)[3]);

    //printf("(%s) %02x %02x %02x %02x\n", str_2, ((unsigned char*)str_2)[0], ((unsigned char*)str_2)[1], ((unsigned char*)str_2)[2], ((unsigned char*)str_2)[3]);
    Line **line_1 = (Line **) str_1;
    Line **line_2 = (Line **) str_2;

    assert(line_1);
    assert(line_2);
    assert(*line_1);
    assert(*line_2);
    
    char *cont_1 = (*line_1)->line_cont;
    char *cont_2 = (*line_2)->line_cont;

    for (int i_1 = 0, i_2 = 0; cont_1[i_1] != '\0' || cont_2[i_2] != '\0'; i_1++, i_2++)
    {
        if (!isalpha(cont_1[i_1]))
        {
            i_2--; 
            continue;
        }

        if (!isalpha(cont_2[i_2]))
        {
            i_1--;
            continue;
        }
        
        if (toupper(cont_1[i_1]) > toupper(cont_2[i_2]) || cont_2[i_2] == '\0')
            return 1;
        
        else if (toupper(cont_2[i_2]) > toupper(cont_1[i_1]) || cont_1[i_1] == '\0')
            return -1;
    }

    return 0;
}

int StrReverceCompare(void *str_1, void *str_2)
{
    Line **line_1 = (Line **) str_1;
    Line **line_2 = (Line **) str_2;
    
    assert(line_1);
    assert(line_2);
    assert(*line_1);
    assert(*line_2);

    char *cont_1 = (*line_1)->line_cont;
    char *cont_2 = (*line_2)->line_cont;

    int i_1 = (*line_1)->length - 1;
    int i_2 = (*line_2)->length - 1;

    for ( ; cont_1[i_1] != '\0' || cont_2[i_2] != '\0'; i_1--, i_2--)    //пока оба указателя не дойдут до конца предыдущей строки
    {
        assert(i_1 < (*line_1)->length);
        assert(i_2 < (*line_2)->length);
        
        if (!isalpha(cont_1[i_1]) && cont_1[i_1] != '\0')
        {
            i_2++; 
            continue;
        }

        if (!isalpha(cont_2[i_2]) && cont_2[i_2] != '\0')
        {
            i_1++;
            continue;
        }
        
        if (toupper(cont_1[i_1]) > toupper(cont_2[i_2]) || cont_2[i_2] == '\0')
            return 1;
    
        else if (toupper(cont_2[i_2]) > toupper(cont_1[i_1]) || cont_1[i_1] == '\0')
            return -1;
    }

    return 0;
}

// пример другого компаратора

int DigCompare(void *ptr_1, void *ptr_2)
{
    assert(ptr_1);
    assert(ptr_2);
    assert(ptr_1 != ptr_2);

    int num_1 = *((int*) ptr_1);
    int num_2 = *((int*) ptr_2);

    if (num_1 > num_2)
        return 1;
    else if (num_2 > num_1)
        return -1;
    return 0;
}
