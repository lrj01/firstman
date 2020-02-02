#include<stdio.h>
int maxCherries(int [],int );
int add(int [],int ,int );
int main()
{   
	int n,i,c[]={0};
	printf("Enter number of slices: ");
	scanf("%d",&n);
	printf("Enter numbers of cherries: ");
	for(i=0;i<n;i++)
	{    scanf("%d",&c[i]);
	}
	printf("The maximum number of cherries Alice can get is %d.\n",maxCherries(c,n));
	return 0;
}
int maxCherries(int arr[],int n)
{   int i,j,p=0,arrC[]={0};
    int d, k;
	 for(i=0;i<n-1;i++)
	 {    
	      for (j=0;j<n;j++)
		{
		    
			if(add(arr,0,n-j)<=(add(arr,n-j,n)+add(arr,0,0-j)))
			{   
				arrC[p]=add(arr,0,n-j);
			    p++;
			}
		}
		d = arr[0];
		for(k = 0;k<n-1 ;k++)
		{
			arr[k]=arr[k+1];
		}
		arr[n-1] = d;
	}

	int s=0,max=arrC[0];
	for (s=0;s<p;s++)
	{  
		if(arrC[s]>max)
		{  
			max=arrC[s];
		}
	}


	return max;
}
int add(int arr[],int n1,int n2)
{  int i,sum=0;
   
    for (i=n1;i<n2;i++)
	 { 
		sum+=arr[i];
	 }
	
	return sum;
}









