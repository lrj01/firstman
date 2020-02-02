#include <stdio.h>
#define EL 11
char generateCode(); 
int main(void)
{   int n;
	printf("Enter 7-digit NRIC number: ");
    scanf("%d",&n);
    printf("Check code is %c\n",generateCode(n));
	return 0;
}
 char generateCode(int num) 
{  int i,sum=0,no[7]={2,7,6,5,4,3,2};
   for ( i=6;i>=0; i--)
{  int rem=num%10;
   sum+= rem*no[i];
   num/=10;
}
int s=sum%EL;char m;
int p=EL-s;
 switch(p)
 {  case 1:m='A';break;
    case 2:m='B';break;
	case 3:m='C';break;
	case 4:m='D';break;
	case 5:m='E';break;
	case 6:m='F';break;
	case 7:m='G';break;
	case 8:m='H';break;
	case 9:m='I';break;
	case 10:m='Z';break;
	case 11:m='J';break;
 }
return m;
}
