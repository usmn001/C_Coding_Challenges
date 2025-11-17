/*
 ============================================================================
 Name        : T1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : LIFO_BUFFER implementation in C Using Arrays
               This is how a stack works in memory (LIFO)
			   Push operation adds item to the top of stack	
			   Pop operation removes item from the top of stack

 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define BUFFER_SIZE 10


typedef enum {        // STATUS CODES OF LIFO BUFFER STATUSES 
LB_NO_ERROR = 0,
LB_ERROR,
LB_FULL,
LB_NOT_FULL,
LB_EMPTY,
LB_NOT_EMPTY,
LB_NULL,
}LB_Status;

LB_Status status_e;


int BUF_ARRAY[BUFFER_SIZE];

static int top = -1;  // INITIALIZING TOP TO -1 INDICATING EMPTY BUFFER


LB_Status LIFO_init (void)
{
	LB_Status status_e;
	if(memset(BUF_ARRAY, 0, sizeof(BUF_ARRAY))!=NULL)
	{
       status_e = LB_NO_ERROR;
	   printf("LIFO Buffer Initialized Successfully \n");
	}
	else if (memset(BUF_ARRAY, 0, sizeof(BUF_ARRAY))==NULL)
	{
		status_e = LB_ERROR;
	}
	return status_e;
}


LB_Status LIFO_push (int item)
{
	// CHECKING NULL BUF
	LB_Status status_e;
    top +=1;
	if(top < BUFFER_SIZE)
	{
		BUF_ARRAY[top] = item;
		printf("Added item is %i \n",item);
		status_e = LB_NO_ERROR;
	}
	else if (top >= BUFFER_SIZE)
	{
		// HANDLE FULL BUFFER
		status_e = LB_FULL;
		top -=1; // REVERTING TOP IN CASE OF FULL BUFFER
	}
	return status_e;
}

LB_Status LIFO_pop(void)
{
	// CHECKING NULL BUF
	if( top == -1)
	{
	   return LB_EMPTY;
	}
	else if (top >= 0)
	{
	   int item = BUF_ARRAY[top];
	   printf("Removed item is %i \n",item);
	   top -=1;
	   return LB_NO_ERROR;
	}
}


int main ()
{
	LIFO_init();

	LIFO_push(10);
	LIFO_push(20);
	LIFO_push(30);	

	LIFO_pop();
	LIFO_pop();
	LIFO_pop();
	
	return 0;
}


