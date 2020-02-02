/**
 * CS1010() AY2019/20 Semester 1 Lab3 Ex1
 * candles.c
 * This program counts the total number of candles Alexandra can burn taking into consideration the number of residual candles that can form a new one.
 * Leah Roselyn James
 * Tutorial T05
 */

#include <stdio.h>
int count_candles(int,int);
int main(void) 
{   
	int num,residual;
	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d %d",&num,&residual);
	printf("Total candles burnt = %d\n",count_candles(num,residual));
	return 0;
}


//This function counts the total number of candles he can burn. 
//@pre-cond: residual should be greater than 1 and num and residual are positive integers.
int count_candles(int num,int residual)
{   int sum=0;
	while(num>=residual)
	{  
	   sum+=((num/residual)*residual);
	   num=num/residual+num%residual;
	}
    sum+=num;
    return sum;
}	

