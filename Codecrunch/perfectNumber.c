#include<stdio.h>
int is_perfect(int);
int main()
{   int num;int n=1;

    while (n!=0)
	{ printf("Enter number: ");
	  scanf("%d",&num);
	if(num==0)
	{  break;
	}
	else if(is_perfect(num)==1)
	{  printf("%d is a perfect number.\n",num);
	}
	else if(is_perfect(num)==0)
	{  printf("%d is not a perfect number.\n",num);
	}
	
	}
	return 0;
}
int is_perfect(int num)
{   int i;int sum=0;
	for( i=1;i<num;i++)
	{	if(num%i==0)
		{ sum+=i;
		}
	}

	if (sum==num)
	{ return 1;
	}
	else
	{ return 0;
	}
}










































