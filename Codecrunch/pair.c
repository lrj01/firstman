#include<stdio.h>
int findPair(int,int,int [],int *,int *);
int main()
{  
	int k,n,i,arrN[10],n1,n2;
	printf("Please enter the number of elements: ");
	scanf("%d",&n);
	printf("Please enter %d integers: ",n);
	for(i=0;i<n;i++)
	{  scanf("%d",&arrN[i]);
	}
	printf("Please enter the target sum: ");
	scanf("%d",&k);
	if(findPair(n,k,arrN,&n1,&n2)==1)
	{ 
		printf("The pair of values are %d and %d.\n",arrN[n2],arrN[n1]);	
    }
	else
	{  
		printf("No solution!\n");
	}
	return 0;
}
int findPair(int n, int k,int arrN[], int *pn1, int *pn2)
{    int i,j,sum=0;
	for(i=0;i<n;i++)
	{   
		for(j=0;j<n;j++)
		{    
			if((i!=j)&&(arrN[i]+arrN[j]==k))
			{ *pn1=i,*pn2=j;sum=1;
				break;
			}
		}
	}
	
	if(sum==0)
	{ return 0;
	}
	else
	{ return 1;
	}
}

