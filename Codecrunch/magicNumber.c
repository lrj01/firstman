


#include<stdio.h>

int get_magic(int);
int main(void)
{  int n1,n2;
	
   printf("Enter 1st value: ");
   scanf("%d", &n1);
   printf("Magic number = %d\n",get_magic(n1));

   printf("Enter 2nd value: ");
   scanf("%d", &n2);
   printf("Magic number = %d\n",get_magic(n2));
   return 0;
}
 int get_magic(int n)
{     int num[5],sum=0,count=0,j;
        
	  
	   
		   
	    while (n!=0)
	       { num[count]=n%10;
	        n/=10;
			
		
	   count++;
	   }

       for (j=0;j<count; j+=2)
	   {    sum=sum+num[j];
	   } 
       return sum%10;
}
