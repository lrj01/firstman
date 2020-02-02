#include<stdio.h>
	int
main ()
{
	int a, b,c,d;
	printf ("Enter size of tray: ");
	scanf ("%d %d", &a, &b);
	printf("Enter size of slab: ");
	scanf("%d %d",&c,&d);
	int count = 0; double temp;
	double max = (a > b) ? a : b;
	double min = (a < b) ? a : b;
	while (count != 3)
	{
		max /= 2;
		if (max < min)
		{
			temp = max;
			max = min;
			min = temp;
		}
		count++;
	}
	int n1=(a/c)*(b/d);
	int n2=(a/d)*(b/c);

	int max1=(n1 > n2) ? n1 : n2;
	int unused=a*b-max1*c*d;


	double p = min*2+2* max;
	printf ("Minimum unused area = %d\n", unused);
	printf ("Minimum perimeter after folding = %0.2f\n", p);

return 0;
}

