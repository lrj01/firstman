#include<stdio.h>
int square();
int computeHappyNumbers();
int main(void)
{  
	int lim1,lim2,lim3,lim4;
	printf("Enter first range: ");
	scanf("%d %d",&lim1,&lim2);
	printf("Enter second range: ");
	scanf("%d %d",&lim3,&lim4);

	int count1=computeHappyNumbers(lim1,lim2);
	int count2=computeHappyNumbers(lim3,lim4);

	printf("The numbers of happy numbers in the two ranges are: %d %d\n",count1,count2);
	if (count1>count2)
	{
		printf("There are more happy numbers in the first range.\n");
	}

	else if(count2>count1)
	{ printf("There are more happy numbers in the second range.\n");
	}
	else
	{ printf("The numbers of happy numbers in both ranges are the same.\n");
	}
	return 0;
}
int square(int num)
{   int rem;int sum=0;
	if (num==1)
	{ sum=1;
	}
	else
	{
		while(sum!=1)
		{  sum=0;	
			while(num!=0)
			{ 
				rem=num%10;
				sum+=rem*rem;
				num/=10;
			}

			if(sum==0||sum==4||sum==16 ||sum==37||sum==42||sum==58||sum==89||sum==145)
			{  sum=0;
			   break;
			}
			else
			{	
			   num=sum;
			}
		}
	}
	if(sum==1)
	{ 
		return 1;
	}
	else
	{ 
		return 0;
	}

}
int computeHappyNumbers(int lower, int upper)
{   int i; int sum=0;
	for( i=lower;i<=upper;i++)
	{  if(square(i)==1)
		{  sum+=1;
		}
	}
	return sum;
}

