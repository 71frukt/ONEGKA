#include <stdio.h>
#include <assert.h>
int StrCompare(char *str1, char *str2);

int main()
{
    char s1[] = "Pipiska bolshaya";
    char s2[] = "Pipiska bolshayaa";

    int r = StrCompare(s1, s2);

    printf("%d", r);
}

int StrCompare(char *str1, char *str2)
{
    assert(str1);
    assert(str2);
    assert(str1 != str2);

    for (int i = 0; !(str1[i] == '\0' && str2[i] == '\0'); i++)
    {
        if (str1[i] > str2[i] || str1[i] == '\0')
            return -1;

        else if (str2[i] > str1[i] || str2[i] == '\0')
            return 1;
    }

    return 0;
}