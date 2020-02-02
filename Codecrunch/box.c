/**
 * CS1010 AY2019/20 Semester 1 Lab1 Ex2
 * box.c
 * This program calculates the Surface area and the Diagonal using length,width and height.
 * Leah Roselyn James
 * Tutorial T05
 */
#include<stdio.h>
#include<math.h>
int compute_surface_area(int,int,int);
double compute_diagonal(int,int,int); 

int main(void)
{  
	int length,width,height;
	printf("Enter length: ");
	scanf("%d",&length);
	printf("Enter width : ");
	scanf("%d",&width);
	printf("Enter height: ");
	scanf("%d",&height);

	printf("Surface area = %d\n",compute_surface_area(length,width,height));
	printf("Diagonal = %0.2f\n",compute_diagonal(length,width,height));

	return 0;
}
int compute_surface_area(int length,int width,int height)//This function calculates the Surface area using a mathematical formula
{   int surf_area=2*length*width+2*length*height+2*width*height;
    return surf_area;
}
double compute_diagonal(int length,int width,int height)//This function first calculates length of hypotenuse and then calculates the length of diagonal using that.
{   double hypo=sqrt(pow(length,2)+pow(width,2));
	double diagonal=sqrt(pow(height,2)+pow(hypo,2));
	return diagonal;

}


