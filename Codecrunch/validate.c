#include<stdio.h>
int main()
{ int age;int i;
  int count=0;
  for (i=0; i>=0; i++)
  {    printf("Enter age: ");
       scanf("%d",&age);
	   count+=1;
    if(age<=100&&age>0)
    { 	printf("Your age is %d.\n",age);
	printf("Number of attempts = %d\n",count);
	break;
	}
  }

	return 0;

}
