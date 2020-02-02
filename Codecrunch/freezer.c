#include<stdio.h>

int main(void)
{   
	int min;
	int hour;
	 double t,T;
	printf("Enter hours and minutes since power failure: ");
    scanf("%d %d",&hour,&min);
    t=hour+(min/60.0);
    T=((t*t*4.0)/(t+2.0))-20.0;
    printf("Temperature in freezer = %0.2f\n",T);
	return 0;
}
