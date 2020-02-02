#include<stdio.h>
#include<math.h>
int luhnah();
void issued();
int main(void) {
	int uCardNo,psum=0;
	printf("Enter uCard Number: ");
	scanf("%d",&uCardNo);
	int count=luhnah(uCardNo,&psum);
	issued(count,uCardNo,psum);
	return 0;
}
int luhnah(int uCardNo,int *sum)
{   int count=1;int rem;
	int num1,num2,doub;
	*sum=0;
	while (uCardNo!=0)
	{   rem=uCardNo%10;
		if(count%2==0)
		{ doub =rem*2;   
			num1=doub %10;
			num2=(doub/10)%10;
			*sum+=num1+num2;
		}
		else
		{ *sum+=rem;
		}

		uCardNo/=10;
		count++;
	}
	printf("The check number is %d\n",*sum);
	if(*sum%7==0)
		printf("Valid\n");
	else 
		printf("Invalid\n");

	return count;	   
}
void issued(int count,int uCardNo,int psum)
{   uCardNo/=(pow(10,count-3));
	
	if(psum%7==0)
	{
	if(uCardNo>=31 && uCardNo<=35)
	{	printf("Issued by East branch\n");
	}
	else if(uCardNo>=51 && uCardNo<=55)
	{	printf("Issued by West branch\n");
	}
	else	  
	{	printf("Issued by Central branch\n");
     }
	 }
}
