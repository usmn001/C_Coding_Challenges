/*
 ============================================================================
 Name        : P1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Divide and Conquer Search

Binary Search Algorithm in C Requires Sorted Data
 1- Sort the array using Quick Sort Algorithm
 2- Apply Binary Search Algorithm
 3- Return the index of the found element or -1 if not found    

 

 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


int sort_array(int arr[], int size);
int cmp_func(const int* a, const int* b);

typedef struct {
    bool found;      /* 1 if found, 0 if not found */
    int position;   /* index of found element or -1 */
} SearchResult_st;



void binary_search(int arr[], int size, int target, SearchResult_st* result_sp)
{
    int left = 0;                 // 1st index of array
    int right = size - 1;         // last index of array
    result_sp->found = false;
    result_sp->position = -1;

    while (left <= right) {
        int mid = left + ((right - left) / 2);

        if (arr[mid] == target) 
        {       
            result_sp->found = true;
            result_sp->position = mid;
            break;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
            continue;
        }
        else {
            right = mid - 1;
            continue;
        }
    }
}


int cmp_func(const int* a, const int* b)
{
    return (*a - *b);               /* Returns -ive if a < b, 
                                       zero if a == b, 
                                       positive if a > b
                                    */
}

int sort_array(int arr[], int size)
{
qsort(arr, size, sizeof(int), (int(*)(const void*, const void*)) cmp_func);   
}




int main()
{
    int array[] = {72,51,91,100,1,15,42,33,67};        // Unsorted Array
    int target = 0, pos = -1; 
    
    SearchResult_st result = { .found = false, .position = -1 };
  
    
    sort_array(array,sizeof(array)/sizeof(array[0] ) );

    printf("Sorted Array:");
    for(int i=0;i<sizeof(array)/sizeof(array[0] );i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");

    printf("Enter a number to search: ");
    scanf("%i",&target);

    // Perform Binary Search
    binary_search(array, ( sizeof(array)/sizeof(array[0])), target,&result);

    printf("Search Result: ");
    if(result.found)
    {
        printf("Element %d found at index %d\n", target, (result.position+1));
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }
return 0;  
}

