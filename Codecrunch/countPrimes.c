#include<stdio.h>
#include<stdbool.h>
bool is_prime(int);
int main()
{  int limit;int count=0;int i;
	printf("Enter limit: ");
	scanf("%d",&limit);
	for(i=1;i<=limit;i++)
	{	  
		if(is_prime(i)==true) 
		{ count+=1;
		}

	}
	printf("Number of primes (1-%d): %d\n",limit,count);
	return 0;

}
bool is_prime(int num)
{   int count=0;int i;bool ans;
	for(i=1;i<=num; i++)
	{	if(num%i==0)
		{ count+=1;
		}
	}
	if( count==2)
	{   ans=true;
	}
	else
	{  ans=false;
	}
	return ans;
}

