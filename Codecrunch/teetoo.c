#include<stdio.h>
long rev( long n);
int main()
{  
	long n;
	long teetoo=0,k=0;
	printf("Enter a positive integer: ");
	scanf("%li",&n);
    k=rev(n);
    printf("%li",k);
	while(k!=0)
	{  teetoo+= rev(k%1000);
	   k/=10000;
	}
    
	printf("%li\n",teetoo);
	return 0;
	
}
long rev(long n)
{  long sum=0;
   while(n!=0)
   { 
	   int rem=n%10;
       sum*=10+rem;
	   n/=10;
   }
   return sum;
}









