#include <stdio.h>
 int gcd(int a, int b);
int main()
{   
	int lim,j,i,sum=0;
	printf("Enter limit: ");
	scanf("%d",&lim);

	for(i=2;i<=lim;i++)
	{   
		for (j=2;j<=lim;j++)
		{    
			if (gcd(i,j)==1)
			{  
				sum+=1;
			}
		}

	}
	printf("Answer = %d\n",sum/2);
    return 0;
}
int gcd(int a, int b)
{   int temp;    

	while(b>0)
	{  temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}


