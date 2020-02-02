#include <stdio.h>
int countJumps (int[], int);
int main ()
{
	int n;
	printf ("Enter number of rocks: ");
	scanf ("%d", &n);
	int i, a[20];
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	int sum = countJumps (a, n);
	printf ("%d\n", sum);
	return 0;
}
int countJumps (int a[], int n)
{
	int i, p = 0, sum = 0;
	int l = n - 1;
	for (i = l; i >= 0; i--)
	{
		if ((a[i] - p) <= 50)
		{
			if ((a[i] - p) == 0)
			{
				break;
			}
			else
			{
				sum += 1;
				p = a[i];
				i = n;
			}
		}
		else
		{
			if (a[i] - a[i - 1] > 50)
			{
				return -1;
			}
		}
	}
	return sum;
}
