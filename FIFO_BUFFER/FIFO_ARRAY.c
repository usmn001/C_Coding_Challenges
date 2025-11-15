/*
 ============================================================================
 Name        : T1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : FIFO_BUFFER implementation in C Using Arrays
                  

 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define BUFFER_SIZE 10



typedef enum {        // STATUS CODES OF FIFO BUFFER STATUSES 
FB_NO_ERROR = 0,
FB_ERROR,
FB_FULL,
FB_NOT_FULL,
FB_EMPTY,
FB_NOT_EMPTY,
FB_NULL,
}FB_Status;

FB_Status status_e;

FB_Status FIFO_init (void);
FB_Status FIFO_push (int item);
FB_Status FIFO_pop(void);

int BUF_ARRAY[BUFFER_SIZE];

static int top = -1;  // INITIALIZING TOP TO -1 INDICATING EMPTY BUFFER
static int bottom = 0; // INITIALIZING BOTTOM TO 0 INDICATING THE FIRST ELEMENT


FB_Status FIFO_init (void)
{
	FB_Status status_e;
	if(memset(BUF_ARRAY, 0, sizeof(BUF_ARRAY))!=NULL)
	{
       status_e = FB_NO_ERROR;
	   printf("FIFO Buffer Initialized Successfully \n");
	}
	else if (memset(BUF_ARRAY, 0, sizeof(BUF_ARRAY))==NULL)
	{
		status_e = FB_ERROR;
	}
	return status_e;
}


FB_Status FIFO_push (int item)
{
	// CHECKING NULL BUF
	FB_Status status_e;
    
	if(top < BUFFER_SIZE)
	{
		top +=1;           // INCREMENTING TOP TO POINT TO THE NEXT EMPTY ELEMENT
		BUF_ARRAY[top] = item;
		 printf("Added item is %i \n",item);
		status_e = FB_NO_ERROR;
	}
	else if (top >= BUFFER_SIZE)
	{
		// HANDLE FULL BUFFER
		status_e = FB_FULL;
		top -=1; // REVERTING TOP IN CASE OF FULL BUFFER
	}
	return status_e;
}

FB_Status FIFO_pop(void)
{
	// CHECKING NULL BUF
	if( top == -1)
	{
	   return FB_EMPTY;
	}
	else if (bottom < BUFFER_SIZE)
	{
	   int item = BUF_ARRAY[bottom];
	   printf("Removed item is %i \n",item);
	   bottom +=1; // INCREMENTING TOP TO POINT TO THE NEXT ELEMENT
	   return FB_NO_ERROR;
	}
	else if (bottom >= top)
	{
	   return FB_FULL;
	}
}


int main ()
{
	FIFO_init();

	FIFO_push(10);
	FIFO_push(20);
	FIFO_push(30);	

	FIFO_pop();
	FIFO_pop();
	FIFO_pop();
	
	return 0;
}


