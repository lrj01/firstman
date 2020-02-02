#include<stdio.h>
int isSubset(int arrA[], int sizeA, int arrB[], int sizeB);
int main()
{   int arrA[4],sizeA,arrB[7],sizeB;
	sizeA=4;sizeB=7;
    int i;int j;
	printf("1st array:\n");
	printf("Enter 4 values: ");
	for(i=0;i<sizeA;i++)
	{  scanf("%d",&arrA[i]);
	}
	printf("2nd array:\n");
	printf("Enter 7 values: ");
	for(j=0;j<sizeB;j++)
	{  scanf("%d",&arrB[j]);
	}
    
	if(isSubset(arrA,4,arrB,7)==1)
	{ printf("arrayA[0..3] is a subset of arrayB[0..6]\n");
	}
	else
	{ printf("arrayA[0..3] is not a subset of arrayB[0..6]\n");
	}
	 if(isSubset(arrA,4,arrB,6)==1)
	{	 
	printf("arrayA[0..3] is a subset of arrayB[0..5]\n");
	}
	else
	{ printf("arrayA[0..3] is not a subset of arrayB[0..5]\n");
	}
    
return 0;

}
int isSubset(int arrA[], int sizeA, int arrB[], int sizeB)
{    int i; int j; int sum=0;
	for(i=0;i<sizeA;i++)
	{  
		for (j=0;j<sizeB;j++)
		{ 
			if(arrA[i]==arrB[j])
			{  sum+=1;
			}
        }

	}
	if(sum==sizeA)
	{    return 1;
    }
	else
	{	return 0;
    }
}















