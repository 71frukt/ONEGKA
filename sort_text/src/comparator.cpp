#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "comparator.h"
#include "read_file.h"

int StrCompare(void *str_1, void *str_2)
{
    assert(str_1);
    assert(str_2);

    //printf("\ncomparator:\n");
    //printf("(%s) %02x %02x %02x %02x\n", str_1, ((unsigned char*)str_1)[0], ((unsigned char*)str_1)[1], ((unsigned char*)str_1)[2], ((unsigned char*)str_1)[3]);

    //printf("(%s) %02x %02x %02x %02x\n", str_2, ((unsigned char*)str_2)[0], ((unsigned char*)str_2)[1], ((unsigned char*)str_2)[2], ((unsigned char*)str_2)[3]);

    Line **line_1 = (Line **) str_1;
    Line **line_2 = (Line **) str_2;
    
    char *cont_1 = (*line_1)->line_cont;
    char *cont_2 = (*line_2)->line_cont;

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

    Line **line_1 = (Line **) str_1;
    Line **line_2 = (Line **) str_2;
    
    char *cont_1 = (*line_1)->line_cont;
    char *cont_2 = (*line_2)->line_cont;

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
    assert(i1);
    assert(i2);
    assert(i1 != i2);

    int d1 = *((int*) i1);
    int d2 = *((int*) i2);

    if (d1 > d2)
        return 1;
    else if (d2 > d1)
        return -1;
    return 0;
}
