#include <stdio.h>
int scan(int []);
void echoing(int ,int [],int ,int [],int);
void print(int ,int,int []);
int main()
{
	int c,p;int echo[100];
	int size=scan(echo);
	int fin[size*(c+1)];
	printf ("Enter number of echoes and decay percentage: ");
	scanf ("%d %d", &c, &p);
	echoing(size,echo,c,fin,p);
	printf ("The sound wave with echoes added: \n");
	print(size,c,fin);  
	return 0;
}
int scan(int echo[] )
{
	int i,size;  
	printf ("Enter size: ");
	scanf ("%d", &size);
	printf ("Enter values: \n");
	for (i = 0; i < size; i++)
	{
		scanf ("%d", &echo[i]);
	}
	return size;
}
void echoing(int size,int echo[],int c,int fin[],int percentage)
{ 
	int s=1;
	int i,j,l; 
	double p=(100-percentage)*0.01;
	for(i=0;i<size;i++)
	{   
		fin[i]=echo[i];
	}

	for(l=0;l<c;l++)
	{  for(j=0;j<size;j++)
		{  fin[size*s+j]=fin[size*s-size+j]*p;
		}

		s+=1;
	} 
}
void print(int size,int c,int fin[])
{   int i;
	for (i=0;i<size*(c+1);i++)
	{ 
		printf("%d ", fin[i]);
	}
     printf("\n");
}

