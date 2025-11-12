/*
 ============================================================================
 Name        : T1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Program For Converting Decimal Number To Binary
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int decimal_binary(unsigned int number)
{

int binary [32]={0};
int cnt_digits=0;      // counter for counting binary digits

for(int index = 0;number>0;index++){
     binary[index]=number%2;
	 number=number/2;
	 cnt_digits+=1;
 }

for(int index=0;index<cnt_digits;index++){
printf("%i",binary[index]);
}



return 1;

}


int main ()
{
	decimal_binary(13);
    //printf("%d", decimal_binary(13));
	return 0;
}


