/*
 ============================================================================
 Name        : P1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Sort An Array Of Words In Descending Order
                https://www.testdome.com/tests/embedded-systems-c-online-test/155
 Reference   :	https://stackoverflow.com/questions/23189630/how-to-use-qsort-for-an-array-of-strings
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cmpfunc(const void *a, const void *b)
{
char *const *pp1 = a;
char *const *pp2 = b;
return strcmp(*pp2,*pp1);

}
void sort_words(char *words[], int count)
{
qsort(words,count,sizeof(char*),cmpfunc);
}

#ifndef RunTests
int main()
{
    char *words[] = { "cherry", "orange", "apple" };

    sort_words(words, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", words[i]);
    }
}
#endif
