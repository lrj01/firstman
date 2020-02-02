#include<stdio.h>
void histogram(int n);
int main()
{   
	int n;
	printf("Enter mark (negative number to end): ");
	scanf("%d",&n);
	int max=n;int k=0,A=0,B=0,C=0,D=0,F=0;
	int min=n;
	int sum=0;
	while (n>=0)
	{  
		sum+=n;
		k++;
		switch(n/10)
		{   case 10:
			case 9:
		    case 8:A++;
			       break;
			case 7:B++;
			       break;
			case 6:C++;
			       break;
			case 5:D++;
			       break;
			case 4:
			case 3:
			case 2:
			case 0:F++;
			       break;
		}
        
		if (n>max)
		{  
			max=n;
		}
		if (n<min)
		{ 
			min=n;
		} 

		printf("Enter mark (negative number to end): ");
		scanf("%d",&n);
	}
	double avg =sum/k;
	int c;
	while(c!=5)
	{ 
		printf("1. Show the maximum and minimum marks\n");
		printf("2. Show the average mark\n");
		printf("3. Show the grade frequency table\n");
		printf("4. Show the grade histogram\n");
		printf("5. Exit\n");
		printf("Select your choice: ");
		scanf("%d",&c);
		
		switch(c)
		{   case 1:printf("The maximum and minimum are %d and %d respectively.\n",max,min);break;
			
			case 2:printf("The average mark is %0.2f.\n",avg);break;
			
			case 3:printf("Grade Frequency Table\n");
				   printf("=====================\n");
				   printf("A: %d\n",A);
				   printf("B: %d\n",B);
				   printf("C: %d\n",C);
				   printf("D: %d\n",D);
				   printf("F: %d\n",F);
				   break;
			
			case 4:printf("Grade Histogram\n");
				   printf("=====================\n");
				   printf("1\n");histogram(F);histogram(D);histogram(C);histogram(B);histogram(A); 
				   printf("2\n");
				   printf("3\n");


				   break;
			
			case 5:printf("Thank you and goodbye!\n");break;
		}

       printf("\n");
	}
	
	return 0;
}
void histogram(int n)
{  int i;  

	for (i=1;i<=n;i++)
	{  printf("***\n");
	}
}



