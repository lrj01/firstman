#include<stdio.h>
void printSuffix(int); 
int main()
{   int day;
	printf("Enter value: ");
	scanf("%d",&day);
	printSuffix(day);
	return 0;

}
void printSuffix(int day)
{   
	int count=0;
	int daycpy=day;
	int newnum=0;
	int rem=day%10;
	while(day!=0)
	{  int rem2=day%10;
		newnum=newnum*10+ rem2;
		count+=1;
		day/=10;
		if (count==2) 
		{   break;
		}
	}
	if( newnum==11||newnum==31||newnum==21)
	{ printf("%dth\n",daycpy);
	}
	else	if(rem==1)
	{		printf("%dst\n",daycpy);
	}
	else if(rem==2)
	{	 printf("%dnd\n",daycpy);
	}
	else if(rem==3)		 
	{    printf("%drd\n",daycpy);
	}
	else
	{    printf("%dth\n",daycpy);
	}

}	
