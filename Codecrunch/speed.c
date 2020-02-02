#include <stdio.h>
#include<stdlib.h>
int scan (int s[]);
void slowdown (int sd[], int size, int p, int s[]);
void speedup (int su[], int size, int p, int s[]);
void print (int s[], int size, int p);
int main ()
{
	int p;
	int s[100];
	int size = scan (s);
	printf ("Enter speed change: ");
	scanf ("%d", &p);
	int m=abs(p);
	int sd[size*m], su[size/m];
	printf("The sound wave after speed change: \n");
	if (p < 0)
	{
		slowdown (sd, size, p, s);
		print(sd, size, p);

	}
	else
	{
		speedup (su, size, p, s);
		print(su, size, p);
	}
	return 0;
}
int scan (int s[])
{
	int i, size;
	printf ("Enter size: ");
	scanf ("%d", &size);
	printf ("Enter values: \n") ;
	for (i = 0; i < size; i++)
	{
		scanf ("%d", &s[i]);
	}
	return size;
}
void slowdown (int sd[], int size, int p, int s[])
{
	int i, j, k = 0;int m=abs(p);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < m; j++)
		{
			sd[k++] = s[i];
		}
	}
}
void speedup (int su[], int size, int p, int s[])
{
	int i, j, k = 0,sum=0, m=abs(p);
	for (i = 0; i < size;i+= m)
	{
		sum = 0;
		for (j = 0; j < m; j++)
		{
			sum += s[i + j];
		}
		su[k++] = sum/m;
		;
	}
}
void print (int s[], int size, int p)
{
	int i;int m=abs(p);
	if (p < 0)
	{
		for (i = 0; i < size *m; i++)
		{
			printf ("%d ", s[i]);
		}
	}
	else
	{
		for (i = 0; i < size/m; i++)
		{
			printf ("%d ", s[i]);
		}
	}
     printf("\n");
}
