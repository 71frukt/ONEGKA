#include <stdio.h>

void MySort(int *p_arr, int size);

int arr[] = { 10, 9, 8, 7, 2, 2, 2, 5, 2, 6, 0 };
int main()
{

    MySort(arr, 11);

    for (int i = 0; i < 11; i++)
        printf("%d ", arr[i]);
}

void MySort(int *p_arr, int size)
{

    int left = 0;
    int right = size - 1;
    int pivot = p_arr[0];
// gdb debugger
    
    while (left < right)
    { 
        while (p_arr[left] < pivot && left <= right)
            left++;
        
        while (p_arr[right] > pivot && left <= right)
            right--;    
        
        if(left > right)
            break;

        int tmp = p_arr[left];
        p_arr[left] = p_arr[right];
        p_arr[right] = tmp;

        left++;
        right--;
    }  

    if (left >= 2)
        MySort(&p_arr[0], left);
    
    if ((size - left) >= 2)
        MySort(&p_arr[left], size - left);
}