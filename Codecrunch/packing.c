/**
 * CS1010 AY2019/20 Semester 1 Lab1  Ex3
 * packing.c
 * This program aims to find the maximum no of slabs of a certain dimension that can fit into a tray of certain dimensions.
 * Leah Roselyn James
 * Tutorial T05
 */

#include <stdio.h>

int compute_max_slabs(int,int,int,int);
int main(void)
{
	int tray_len,tray_wid;
	int slab_len,slab_wid;

	printf("Enter dimension of tray: ");
	scanf("%d %d",&tray_len,&tray_wid);

	printf("Enter dimension of slab: ");
	scanf("%d %d",&slab_len,&slab_wid);



	printf("Maximum number of slabs = %d\n", compute_max_slabs(tray_len,tray_wid,slab_len,slab_wid));

	return 0;
}
// This function checks for the maximum no of slabs that can be fitted in the tray: no1 or no2. We divide the tray length and width with the slab width and length alternatively and multiply them to find the best fit. 
int compute_max_slabs(int tray_len,int tray_wid,int slab_len, int slab_wid)
{   int no_slabs;
	int no1=(tray_len/slab_wid)*(tray_wid/slab_len);
	int no2=(tray_len/slab_len)*(tray_wid/slab_wid);
	if( no1>no2)
	{  no_slabs=no1;
	}
	else
	{  no_slabs=no2;
	}

	return no_slabs;
}

