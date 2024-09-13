#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys\stat.h>

#include "read_file.h"
#include "sort.h"
#include "printer.h"
#include "argv_work.h"
#include "free.h"

int main(const int argc, const char *argv[])
{
    FILE *text_file = NULL;
    FILE *target_file = NULL;

    OpenGettedFiles(argv, &text_file, &target_file);

    TextInfo text = {};
    
    if (ReadFile(text_file, &text) == ERR_READ)
    {
        printf("ERROR reading file\n");
        return 0;
    }
    
    fclose(text_file);
    
    PutPointers(&text);

    MySort(text.p_lines, text.num_lines, sizeof(void*), StrCompare);  
    FprintLines(target_file, text.p_lines, text.num_lines);

    fprintf(target_file, "\n\n\n\n#######################################################################################\n#######################################################################################\n#######################################################################################\n#######################################################################################\n#######################################################################################\n#######################################################################################\n#######################################################################################\n\n\n\n");

    MySort(text.p_lines, text.num_lines, sizeof(void*), StrReverceCompare);    
    FprintLines(target_file, text.p_lines, text.num_lines);

    FreeTextInfo(&text);



    /*
    int arr[40] = { 1, 5, 6, 8, 7, 6, 3, 1, 4, 7, 8, 9, 10, 4, 5, 9, 2, 1, 0, 3, 57, 8, 9, 5, 3, 1, 10, 15, 16, 59, 5, 47, 8, 59, 74, 1, 5, 6, 5, 6};

    MySort(arr, 40, sizeof(int), DigCompare);

    for (int i = 0; i < 40; i++)
        printf("%d ", arr[i]);
    */

}
