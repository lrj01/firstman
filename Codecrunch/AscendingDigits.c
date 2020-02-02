#include<stdio.h>
int isAscending();
int main()
{  int num1,num2,num3;
	printf("Enter 3 positive integers: ");
	scanf("%d %d %d",&num1,&num2,&num3);
	printf("The integers are %d, %d and %d\n",num1,num2,num3);
    if(isAscending(num1,num2,num3)==1)
   { printf("Yes\n");
   }else
   { printf("No\n");
   }
   return 0;

}
int isAscending(int num1,int num2,int num3)
{  int count1,count2,count3;
   count1=count2=count3=0;
   int rem1,rem2,rem3;
   int ans;
	while(num1!=0)
	{rem1=num1%10;
		num1/=10;
		count1+=1;
			if( count1==3)
			{   break;
			}
	}
	
	
	while(num2!=0)
	{rem2=num2%10;
		num2/=10;
		count2+=1;
			if( count2==3)
			{   break;
			}
	}
	while(num3!=0)
	{rem3=num3%10;
		num3/=10;
		count3+=1;
			if( count3==3)
			{   break;
			}
	}
  if(count1>=3&&count2>=3&&count3>=3)
  {	if(rem1<rem2&&rem2<rem3)
	{ ans=1;
	}
	else
	{ans=0;
	}
  }
  else
  {  ans=0;
  }
	return ans;
  
}
    		
