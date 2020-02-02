#include<stdio.h>
#include<math.h>
void compute_AM_GM(float,float,float,float *,float *);
int main()
{ 
   float n1,n2,n3;	
   printf("Enter 3 positive integers: ");
   scanf("%f %f %f",&n1,&n2,&n3);
   float AM,GM;
   compute_AM_GM(n1,n2,n3,&AM,&GM);
   printf("Arithmetic mean = %0.2f\n",AM);
   printf("Geometric mean = %0.2f\n",GM);
   
   return 0;
}
void compute_AM_GM(float n1,float n2,float n3,float *pAM,float *pGM)
{  
	*pAM = (n1+n2+n3)/3.0;
	*pGM = pow(n1*n2*n3,1.0/3.0);

}	
	

