#include<stdio.h>
int compute_flips(int, int, int, int *, int *);
int main()
{  
	int n1,n2,n3;  	
	printf("Enter 3 inputs: ");
	scanf("%d %d %d",&n1,&n2,&n3);
	int c1,c2;
	if(compute_flips(n1,n2,n3,&c1,&c2)==1)
	{ printf("Possible!\n");
		printf("%d flip(s) for %d-minute hourglass and %d flip(s) for %d-minute hourglass.\n",c1,n1,c2,n2);
	}
	else
	{   printf("Impossible!\n");
	}
	return 0;

}
int compute_flips(int n1, int n2, int n3, int *pc1, int *pc2)
{   int sum1=0,sum2=0,c1,c2,c3,c4,i,j;   

    for (i=0;i<(n3/n1);i++)
	{  for(j=0;j<(n3/n1);j++)
		{   
			if((i*n2+j*n1)==n3)
			{  c1=j,c2=i,sum1=i+j;
				break;
			}

		}
	}
	int p,q;
	for (p=0;p<(n3/n1);p++)
	{  for(q=0;q<(n3/n1);q++)
		{   
			if((p*n2+q*n1)==n3)
			{  c3=q,c4=p,sum2=p+q;
				break;
			}  
		}
	}
    if(sum1==0&& sum2==0)
    {	return 0;
    }
	else
	{	
	if(sum1<sum2)
	{  *pc1=c1;
		*pc2=c2;
		return 1;
	}
	else
	{   *pc1=c3;
		*pc2=c4;
		return 1;
	}
	}
}


