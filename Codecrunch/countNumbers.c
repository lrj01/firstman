#include<stdio.h>
int count_numbers(int l1, int l2, int d1, int d2);
int main()
{   int div1,div2,lim1,lim2;
	int n1=0,n2=0;
	while(n1==0)
	{      
		printf("Enter 2 divisors: ");
		scanf("%d %d",&div1,&div2);
		if (div1!=div2 && div1>0 && div2>0) 
		{ n1=1;
		}
		else 
		{ 
			n1=0;
		}
	}

	while(n2==0) 
	{
		printf("Enter lower and upper limits: ");
		scanf("%d %d",&lim1 ,&lim2);
		if(lim1<lim2 && lim1>0 && lim2>0)
		{ n2=1;
		}
		else
		{ n2=0;

		}

	}


	printf("Answer = %d\n",count_numbers(div1,div2,lim1,lim2));

	return 0;
}
int count_numbers(int d1, int d2, int l1, int l2)
{   int i;int count=0;
	for (i=l1; i<=l2; i++)
	{   if ( i%d1!=0&& i%d2!=0)
		{   count+=1;
		}
	}
	return count;
}
