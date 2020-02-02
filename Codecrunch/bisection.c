/**
 * CS1010 AY2019/20 Semester 1 Lab3 Ex3
 * bisection.c
 * This program asks the user to enter the integer coefficients (c3, c2, c1, c0) for a polynomial of degree 3 and  for the two 
 * endpoints , using Bisection methold it  returns the root and the value of its polynomial function.
 * Leah Roselyn James
 * Tutorial T05
 */

#include<stdio.h>
#include<math.h>
#define THRESHOLD 0.0001
double polynomial(double,int ,int ,int ,int);
double findroot(double,double,int,int,int,int);

int main()
{   
	int c3, c2, c1, c0;
	double a, b;           

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a,&b);

	double m=findroot(a ,b,c0,c1,c2,c3);
	double pM=polynomial(m,c0,c1, c2,c3);
	printf("root = %0.6f\n", m);
	printf("p(root) = %0.6f\n", pM);

	return 0;
}


//This function take in all values and returns its polynomial value.
double polynomial(double x, int c0, int c1, int c2, int c3)
{   
	return x*x*x*c3 +x*x*c2 +x*c1 +c0;
}


//The loop in this function terminates when the midpoint is the root, or when the two endpoints a and b are very close 
//to each other(0.0001).
double findroot(double a , double b, int c0, int c1, int c2, int c3 )
{  

	double pA,pB,pM;

	while (fabs(a-b)>=THRESHOLD)    
	{   
		
		pA=polynomial(a,c0,c1,c2,c3);
		pB=polynomial(b,c0,c1,c2,c3);
		pM=polynomial((a+b)/2,c0,c1,c2,c3);
      
		if(pM<0)
		{   
			a=(pA<0)?(a+b)/2:a;
			b=(pB<0)?(a+b)/2:b;
		}
		else if( pM==0)
		{ 
			break;
		}
		else
		{   
			a=(pA>0)? (a+b)/2:a;
			b=(pB>0)? (a+b)/2:b;
		} 

	}

	return (a+b)/2;

}

