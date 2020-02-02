/**
* CS1010 AY2017/8 Semester 1 Lab5 Ex1
* square.c
* Given the size of a square and the values in
* in the square, this program determines whether 
* the given square is a semi-magic square.
* Leah Roselyn James
* T05
*/
#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE]);
int isSemiMagic(int [][MAXSIZE],int );
int checkduplicate(int square[][MAXSIZE],int size);

int main(void) 
{ 
	int square[MAXSIZE][MAXSIZE];
	int size=scanSquare(square);

	if( checkduplicate(square,size)==0 && isSemiMagic(square,size)==0 )
		printf("It is a semi-magic square.\n");
	else
		printf("It is not a semi-magic square.\n");
	return 0;
}

// Read in size of square and values in the square. 
// Return the size of square.
int scanSquare(int square[][MAXSIZE])
{	
	int r, c, size;
	printf("Enter size of square: ");
	scanf("%d", &size);
	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) 
	{
		for (c=0; c<size; c++) 
		{
			scanf("%d", &square[r][c]);
		}
	}
	return size;
}

//This function checks for duplicate values in the square.
int checkduplicate(int square[][MAXSIZE],int size)
{   
	int i,j,r,c;
	for (i=0; i<size; i++) 
	{
		for (j=0; j<size; j++) 
		{
			for (r=0; r<size; r++) 
			{
				for (c=0; c<size; c++) 
				{    
					if (i!=r && j!=c && square[i][j]==square[r][c] )
					{  
						return 1;

					}
				}
			}
		}
	}

	return 0;
}

//This function checks if the sum of each row or colum corresponds to the appropriate value.
int isSemiMagic(int square[][MAXSIZE], int size)
{   

	int r,c,sum_r,sum_c;

	for (r=0; r<size; r++) 
	{   
		sum_r=0,sum_c=0;
		for (c=0; c<size; c++) 
		{ 
			sum_r+= square[r][c];
			sum_c+=square[c][r];
		}

		if(sum_r!=sum_c)
		{      
			return 1;
		}
	}


	return 0;
}
