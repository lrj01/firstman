/**
 * CS1010 AY2017/8 Semester 1 Lab0 Ex  * box_volume.c
 * This program calculates the volume of a box.
 * <Leah James>
 * <T05>
 */

#include <stdio.h>
#include<math.h>
int main() {

	int length, width, height, volume;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	
	scanf("%d", &height);

	volume = length*width*height;

	printf("Volume = %d\n", volume);

	return 0;
}

