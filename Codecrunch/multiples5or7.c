#include<stdio.h>
int count_multiples(int);
int main()
{ int num;

	printf("Enter positive integer: ");
	scanf("%d",&num);
	if (count_multiples(num)==0)
	{ printf("There are no multiples of 5 or 7 in [1,%d].\n",num );	  
	}
	else if(count_multiples(num)==1) 
	{   printf("There is %d multiple of 5 or 7 in [1,%d].\n",count_multiples(num),num );
	}
	else
	{ printf("There are %d multiples of 5 or 7 in [1,%d].\n",count_multiples(num),num );
	}
	return 0;
}
int count_multiples(int num)
{ int i;int count =0;
	for ( i=1;i<=num;i++)
	{   if(i% 5==0)
		{ count+=1;
		}
		else if(i%7==0)
		{ count+=1;
		}

	}
	return count;
}











