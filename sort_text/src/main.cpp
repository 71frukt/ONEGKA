#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <time.h>

#include "read_file.h"
#include "sort.h"
#include "printer.h"
#include "argv_work.h"
#include "comparator.h"
#include "free.h"

int main(const int argc, const char *argv[])
{
    clock_t begin = clock();

    FILE *text_file = NULL;
    FILE *target_file = NULL;

    if (OpenGettedFiles(argc, argv, &text_file, &target_file) != OPEN_OK)
        return 0;

    TextInfo text = {};
    
    if (ReadFile(text_file, &text) != READ_OK)
        return 0;
    
    fclose(text_file);
    
    PutPointers(&text);

    MySort(text.p_lines, text.num_lines, sizeof(void*), StrCompare);  
    FprintLines(target_file, text.p_lines, text.num_lines);

    MySort(text.p_lines, text.num_lines, sizeof(void*), StrReverceCompare);    
    FprintLines(target_file, text.p_lines, text.num_lines);

    FreeTextInfo(&text);
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("WORK TIME = %f", time_spent);

    /*
    int arr[40] = { 1, 5, 6, 8, 7, 6, 3, 1, 4, 7, 8, 9, 10, 4, 5, 9, 2, 1, 0, 3, 57, 8, 9, 5, 3, 1, 10, 15, 16, 59, 5, 47, 8, 59, 74, 1, 5, 6, 5, 6};

    MySort(arr, 40, sizeof(int), DigCompare);

    for (int i = 0; i < 40; i++)
        printf("%d ", arr[i]);
    */
}
