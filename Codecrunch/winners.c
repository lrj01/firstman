//CS1010 AY2011/2 Semester 1
// PE1 Ex2: winners.c
// Name:
// Matriculation number:
// plab account-id:
// Discussion group:
// Description:
#include<stdio.h>
int winner(int,int,int);
int main(void)
{
	int factor_dig,musthave_dig,num_part;
	printf("Enter factor-digit: ");
	scanf("%d",&factor_dig);
	printf("Enter must-have-digit: ");
	scanf("%d",&musthave_dig);
	printf("Enter number of participants: ");
	scanf("%d",&num_part);
	printf("Number of winners: %d\n", winner(factor_dig,musthave_dig,num_part));
	return 0;
}

int winner(int factor_dig,int musthave_dig,int num_part)
{   int i,n;int count=0;int rem;
      for(i=1;i<=num_part;i++)
	{  
		if(i%factor_dig==0)
	    {    n=i;
		    while(n!=0)
		   { 
		     rem=n%10;
		     if(rem==musthave_dig)
			  { count+=1;
			    break;
			  } 
		     n/=10;
		   }
	   }  
	
	}
	return count;
}
