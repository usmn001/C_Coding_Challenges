/*
 ============================================================================
 Name        : P1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Sort An Array Of Words In Descending Order
                https://www.testdome.com/tests/embedded-systems-c-online-test/155
 Reference   :	https://stackoverflow.com/questions/23189630/how-to-use-qsort-for-an-array-of-strings
 
 For strcmp function               https://en.cppreference.com/w/c/string/byte/strcmp

We are using qsort from stdlib.h
 Prototype :  void qsort(void *base, size_t nmemb, size_t size,
                 int (*compar)(const void *, const void *));
 Parameters :
    base  -  pointer to the first element of the array to be sorted.
    nmemb -  number of elements in the array pointed to by base.
    size  -  size in bytes of each element in the array.
    compar - pointer to a comparison function which returns
             negative value if first argument is less than second,
             zero if they are equal,
             positive value if first argument is greater than second.

 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cmpfunc(const void *a, const void *b)
{
char *const *pp1 = a;
char *const *pp2 = b;
return strcmp(*pp2,*pp1);     // Returning strcmp return value in reverse order for descending sort i.e
                              /* strcmp returns -ive if pp2 < pp1 in lexicographical order , so for descending order we return it as is.
                                        returns 0 if pp2 = pp1 in lexicographical order 
                                        returns +1 if string pp2 appears after pp1 in lexicographical order */

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
