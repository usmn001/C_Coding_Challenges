/*
 ============================================================================
 Name        : T1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : FIFO_BUFFER implementation in C Using MALLLOC and STRUCTS
                  

 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef enum {        // STATUS CODES OF FIFO BUFFER STATUSES 
FB_NO_ERROR = 0,
FB_FULL,
FB_NOT_FULL,
FB_EMPTY,
FB_NOT_EMPTY,
FB_NULL,
}FB_Status;



typedef struct {
uint32_t length;         // Size of the FIFO Buffer
uint32_t *base;          // Pointer Pointing to the starting memory location address
uint32_t *head;          // Pointer Pointing to next memory location address
uint32_t *tmp;           // Temporary Pointer to hold the base address for free operation
}FIFO_BUF_st;

FB_Status FIFO_Is_Buf_Full(FIFO_BUF_st  *fbuf_s)
{
	FB_Status status;

	if( fbuf_s->base == NULL || fbuf_s->head == NULL) 
	{
	status = FB_NULL;  
	}

	else if(fbuf_s->base == (fbuf_s->head+fbuf_s->length))
	{
	status = FB_FULL;
	}

	else if(fbuf_s->base < (fbuf_s->head))
	{
	status = FB_NOT_FULL;
	}
	
	else if(fbuf_s->base == fbuf_s->head)
	{
	status = FB_EMPTY;
	}
	
	return status;
}

FB_Status FIFO_Add_Item (FIFO_BUF_st *fbuf_s,uint32_t item) // This iteam can also be a struct or union, for that we will need to cast
                                                         // malloc pointer accordingly
{
FB_Status status;

	if( FIFO_Is_Buf_Full(fbuf_s)!=FB_FULL)
	{
		*(fbuf_s->head) = item;
		printf("Added item is %i \n",item);
		fbuf_s->head= fbuf_s->head+1;
		status = FB_NO_ERROR;
	}
	else
	{
		status = FB_FULL;
	}
return status;
}

FB_Status FIFO_Remove_Item (FIFO_BUF_st *fbuf_s) // This iteam can also be a struct or union, for that we will need to cast
                                                         // malloc pointer accordingly
{
	FB_Status status;

	if( FIFO_Is_Buf_Full(fbuf_s)==FB_NOT_FULL )
	{
		uint32_t item = *(fbuf_s->base);	
		printf("Popped item is %i \n",item);
		fbuf_s->base= fbuf_s->base+1;    // Increment the base pointer to point to the next item
		status = FB_NO_ERROR;
	}
	else if(FIFO_Is_Buf_Full(fbuf_s)==FB_EMPTY)
	{
		status = FB_EMPTY;
	}
	return status;
}

FIFO_BUF_st * create_buffer(FIFO_BUF_st *fbuf_ptr,uint32_t length ) 
{
fbuf_ptr->base= (uint32_t*)malloc(sizeof(length)*32);   // Here we could have also used arrays instead of heap depending upon requirement.
fbuf_ptr->tmp = fbuf_ptr->base;  // TEMP POINTER TO HOLD THE BASE ADDRESS FOR FREE OPERATION
fbuf_ptr->head = fbuf_ptr->base;
fbuf_ptr->length= length;
return fbuf_ptr;
}


int main ()
{
	FIFO_BUF_st fbuf1, *fbuf_ptr;
	fbuf1.base = NULL;
	fbuf1.head = NULL;	
	fbuf1.tmp = NULL;
	fbuf1.length = 32;

	fbuf_ptr = create_buffer(&fbuf1,fbuf1.length);
    
    FIFO_Add_Item(fbuf_ptr,10);
	FIFO_Add_Item(fbuf_ptr,20);	
	FIFO_Add_Item(fbuf_ptr,30);
    
	FIFO_Remove_Item(fbuf_ptr);
	FIFO_Remove_Item(fbuf_ptr);
	FIFO_Remove_Item(fbuf_ptr);

	free(fbuf_ptr->tmp); 
	 
	
  
	

	return 0;
}


