#include<stdio.h>
int main()
{  int n,num;int i=1;int num2=0;
	while(i!=0)
	{   printf("Enter positive integer: ");
		scanf("%d",&num);
		n=num;num=num2; num2=n;

		if(num2<num||num==num2)
		{   if( num2==0)
			{ printf("Data are in increasing order.\n");
			  break;
			}
			else
			{ printf("Data are not in increasing order.\n");
			  break;
			}
		}
      i+=1;
	}
	return 0;

} 
