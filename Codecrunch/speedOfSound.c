#include <stdio.h>
#include<math.h>
 float speedOfSound(float);
int main()
{   float T;
    printf("Temperature in degree Fahrenheit: ");
	scanf("%f",&T);
	


	printf("Speed of sound in air of %0.2f degree = %0.2f ft/sec\n",T,speedOfSound(T)  );
     return 0;
}

float speedOfSound(float t)
{   return 1086.0*sqrt((5*t+297.0)/247.0);
    
}
