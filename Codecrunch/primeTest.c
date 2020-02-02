#include<stdio.h>
void is_prime(int);
int main()
{  int num;
	printf("Enter a positive integer: ");
	scanf("%d",&num);
	is_prime(num);
	return 0;
}
void is_prime(int num)
{   int count=0;int i;
	for(i=1;i<=num; i++)
	{	if(num%i==0)
		{ count+=1;
		}
	}

	if( count==2)
	{   printf("%d is a prime.\n",num);
	}
	else
	{  printf("%d is not a prime.\n",num);
	}
}
