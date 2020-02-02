/**
 * CS1010 AY2019/20 Semester 1 Lab3 Ex2
 * square_free.c
 * This program asks the user to enter 2 ranges of numbers and compares them to see which one has a greater number of square free numbers.
 * Leah Roselyn James
 * Tutorial T05
 */


#include<stdio.h>
int count_square(int,int);
int main(void) 
{
	int lower1, upper1, lower2, upper2;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d",&lower1,&upper1,&lower2,&upper2);
	int sum1=count_square(lower1,upper1);
	int sum2=count_square(lower2,upper2);
	if (sum1>sum2)
	{
		printf("Range [%d, %d] has more square-free numbers: %d\n",lower1,upper1,sum1);
	}
	else if(sum2>sum1)
	{ 
		printf("Range [%d, %d] has more square-free numbers: %d\n",lower2,upper2,sum2);
	}
	else
	{
		printf("Both ranges have the same number of square-free numbers: %d\n",sum1);
	}
	return 0;
}


//This function checks whether each number in the lower to upper range is a square free numbers and sums it if it is.
int count_square(int lower ,int upper )
{   
	int i,j,count=0,sum=0,count2=0;
	for (i=lower;i<=upper;i++)
	{   
		count=0;count2=0;
		for (j=2;j<=upper;j++)
		{  
			if (i%(j*j)==0||((j*j)==i))
			{ 
				count2+=1;
			}
			else if(i%(j*j)!=0&&((j*j)!=i))
			{ 
				count+=1;
			}
		}

		if(count2==0&&count>0)
		{  
			sum+=1;
			
		}
	}

	return sum;
}
