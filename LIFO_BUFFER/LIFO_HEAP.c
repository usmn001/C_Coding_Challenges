/*
 ============================================================================
 Name        : T1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : LIFO_BUFFER implementation in C Using MALLLOC and STRUCTS
                  

 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef enum {        // STATUS CODES OF LIFO BUFFER STATUSES 
LB_NO_ERROR = 0,
LB_FULL,
LB_NOT_FULL,
LB_EMPTY,
LB_NOT_EMPTY,
LB_NULL,
}LB_Status;

typedef struct {
uint32_t length;         // Size of the LIFO Buffer
uint32_t *base;          // Pointer Pointing to the starting memory location address
uint32_t *head;          // Pointer Pointing to next memory location address
}LIFO_BUF_st;

LB_Status LIFO_Is_Buf_Full(LIFO_BUF_st  *lbuf_s)
{
	LB_Status status;

	if( lbuf_s->head == NULL || lbuf_s->base == NULL) 
	{
	status = LB_NULL;  
	}

	else if(lbuf_s->head == (lbuf_s->base+lbuf_s->length))
	{
	status = LB_FULL;
	}

	else if(lbuf_s->head != (lbuf_s->base+lbuf_s->length))
	{
	status = LB_NOT_FULL;
	}
	else if(lbuf_s->head == lbuf_s->base)
	{
	status = LB_EMPTY;
	}
	
	return status;
}

LB_Status LIFO_Add_Item (LIFO_BUF_st *lbuf_s,uint32_t item) // This iteam can also be a struct or union, for that we will need to cast
                                                         // malloc pointer accordingly
{

if( LIFO_Is_Buf_Full(lbuf_s)!=LB_FULL)
{
*(lbuf_s->head) = item;
printf("Added item is %i \n",item);
lbuf_s->head= lbuf_s->head+1;
return LB_NO_ERROR;
}
else
{
return LB_FULL;
}

}

LB_Status LIFO_Remove_Item (LIFO_BUF_st *lbuf_s) // This iteam can also be a struct or union, for that we will need to cast
                                                         // malloc pointer accordingly
{
	LB_Status status;
	if( LIFO_Is_Buf_Full(lbuf_s)==LB_NOT_FULL)
	{
		lbuf_s->head = lbuf_s->head-1;      // Move the head pointer back to point to the last added item
		uint32_t item = *(lbuf_s->head);	
		printf("Popped item is %i \n",item);
		
		status = LB_NO_ERROR;
	}
	else if(LIFO_Is_Buf_Full(lbuf_s)==LB_EMPTY)
	{
		status = LB_EMPTY;
	}
	return status;
}

LIFO_BUF_st * create_buffer(LIFO_BUF_st *lbuf_ptr,uint32_t length ) 
{
lbuf_ptr->base= (uint32_t*)malloc(sizeof(length)*32);   // Here we could have also used arrays instead of heap depending upon requirement.
lbuf_ptr->head= lbuf_ptr->base;
lbuf_ptr->length= length;
return lbuf_ptr;
}


int main ()
{
	LIFO_BUF_st lbuf1, *lbuf_ptr;
	lbuf1.base = NULL;
	lbuf1.head = NULL;	
	lbuf1.length = 32;

	lbuf_ptr = create_buffer(&lbuf1,lbuf1.length);
    
    LIFO_Add_Item(lbuf_ptr,10);
	LIFO_Add_Item(lbuf_ptr,20);	
	LIFO_Add_Item(lbuf_ptr,30);
    
	 LIFO_Remove_Item(lbuf_ptr);
	 LIFO_Remove_Item(lbuf_ptr);
	 LIFO_Remove_Item(lbuf_ptr);

	 free(lbuf_ptr->base);
	 lbuf_ptr->base = NULL;
	
  
	

	return 0;
}


