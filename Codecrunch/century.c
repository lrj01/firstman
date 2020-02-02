#include<stdio.h>
int printCentury();
void printOrdinal();
int main(void)
{   
	int year;
	printf("Enter year: ");
	scanf("%d",&year);
	printOrdinal(printCentury(year),year);
	return 0;

}
int printCentury(int year)
{   
	
	int cent;
		 cent= year/100+1;
		
		return cent;
}
void printOrdinal(int cent,int year)
{   
	int count=0;
	int newnum=0;
	int rem=cent%10; 
	while(cent!=0)
	{  int rem2=cent%10;
		newnum=newnum*10+ rem2;
		count+=1;
		cent/=10;
		if (count==2) 
		{   break;
		}
	}
	if( newnum==11||newnum==31||newnum==21)
	{   
		printf("The year %d falls in the %dth century.\n",year,printCentury(year));

	}
	else if(rem==1)
	{	
		printf("The year %d falls in the %dst century.\n",year,printCentury(year));

	}
	else if(rem==2)
	{ 	
		printf("The year %d falls in the %dnd century.\n",year,printCentury(year)) ;

	}
	else if(rem==3)		 
	{   
		printf("The year %d falls in the %drd century.\n",year,printCentury(year));

	}
	else
	{  
		printf("The year %d falls in the %dth century.\n",year,printCentury(year));
	}
	
}	




