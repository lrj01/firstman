#include<stdio.h>
#include<math.h>
void centroid(float,float,float,float,float,float,float *,float *);
int main()
{
	float n1,n2,n3,n4,n5,n6;

	printf("Coordinates of 1st vertex: ");
	scanf("%f %f",&n1,&n2);
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f",&n3,&n4);
	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f",&n5,&n6);

	float x=0.0,y=0.0;

	centroid(n1,n2,n3,n4,n5,n6,&x,&y);
	printf("Coordinates of incenter = (%0.2f, %0.2f)\n",x,y);

	return 0;
}
void centroid(float n1,float n2,float n3,float n4,float n5,float n6,float *px,float *py)
{      
	float a=sqrt(pow(n3-n5,2)+pow(n4-n6,2));
	float b=sqrt(pow(n1-n5,2)+pow(n2-n6,2));
	float c=sqrt(pow(n1-n3,2)+pow(n2-n4,2));
	*px=(n1*a+n3*b+n5*c)/(a+b+c);
	*py=(n2*a+n4*b+n6*c)/(a+b+c);

}














