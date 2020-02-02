/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex3
 * Game of Life
 * Leah Roselyn James
 * T05
 */

#include <stdio.h>
#define DIM_ROW 20
#define DIM_COL 20
#define DEAD '-'
#define LIFE 'O'
#define MAX_GEN 5

int genesis(char[][DIM_COL+2]); 
void display(int, char[][DIM_COL+2]);
int generation(char[][DIM_COL+2],char new[DIM_ROW+2][DIM_COL+2]);
int check(char grid[][DIM_COL+2]);
int same(char[][DIM_COL+2],char new[DIM_ROW+2][DIM_COL+2]);
int countsum(char[][DIM_COL+2],int i, int n);

int main(void) 
{
	char board[DIM_ROW+2][DIM_COL+2];// the community
	char new[DIM_ROW+2][DIM_COL+2];
	int  gen = 0;              // generation

	genesis(board);
	// display(generation, board); // for checking


	gen=generation(board,new);
	// Display the final generation
	display(gen, board); 

	return 0;
}

// To initialise the community with generation 0 from user's input, and
// return the number of life cells read.
// Sentinels are used here. Dead cells are padded around the actual
// community area.
int genesis(char community[][DIM_COL+2]) 
{
	int population = 0;
	int r, c; 

	// Fill left-most and right-most columns with dead cells.
	for (r=0; r < DIM_ROW + 2; r++)
		community[r][0] = community[r][DIM_COL + 1] = DEAD;

	// Fill top and bottom rows with dead cells.
	for (c=1; c < DIM_COL + 1; c++)
		community[0][c] = community[DIM_ROW + 1][c] = DEAD;

	// Fill the middle 20x20 area with input data
	for (r=1; r<=DIM_ROW; r++)
	{
		for (c=1; c<=DIM_COL; c++) 
		{
			community[r][c] = fgetc(stdin);
			if (community[r][c] == LIFE)
				population++;
		}
		fgetc(stdin);  // to read the newline character
	}

	return population;
}

// To display the community
void display(int generation, char community[][DIM_COL+2]) 
{
	int r, c;
	printf("Generation %d:\n", generation);


	for (r=1; r <= DIM_ROW; r++) 
	{
		for (c=1; c <= DIM_COL; c++)
		{
			printf("%c", community[r][c]);
		}
		printf("\n");
	}
}

// To generate next generation and
// return number of live cells in next generation.
// next_generation()
int generation(char grid[][DIM_COL+2],char new[DIM_ROW+2][DIM_COL+2])
{    
	int k=0,r,c,i,n,count=0;
	while(k<5)
	{   
		for (i=1; i <= DIM_ROW; i++) 
		{
			for (n=1; n <= DIM_COL; n++)
			{   
				if(grid[i][n]==LIFE)
				{ 
					count=countsum(grid,i,n);

					if(count==2 ||count==3)
					{  
						new[i][n]=LIFE;
					}
					else
					{ 
						new[i][n]=DEAD;
					}
					count=0;
				}
				else
				{
					count=countsum(grid,i,n);

					if(count==3)
					{ 
						new[i][n]=LIFE;
					}
					else
					{
						new[i][n]=DEAD;
					}

					count=0;
				}
			}

		}

		k+=1;
		if(check(new)==1||same(grid,new)==1)
		{  
			break;
		}
		else
		{ 
			for(r = 1; r<=DIM_ROW; r++)
			{
				for(c = 1; c<=DIM_COL; c++)
				{
					grid[r][c] = new[r][c];
				}
			}
		}


	}

	return k;
}

//To count the sum of live cells in the grid.
int countsum(char grid[][DIM_COL+2],int i, int n)
{   
	int count=0;

	if(grid[i+1][n-1]==LIFE) count++;
	if(grid[i+1][n] == LIFE) count++;
	if(grid[i+1][n+1]==LIFE) count++;
	if(grid[i][n+1] == LIFE) count++;
	if(grid[i][n-1] == LIFE) count++;
	if(grid[i-1][n-1]==LIFE) count++;
	if(grid[i-1][n] == LIFE) count++;
	if(grid[i-1][n+1]==LIFE) count++;

	return count;
}

//To check if all the cells are dead after each generation.
int check(char grid[][DIM_COL+2])
{   
	int r,c;
	
	for (r=1; r <= DIM_ROW; r++) 
	{
		for (c=1; c <= DIM_COL; c++)
		{   
			if(grid[r][c]!=DEAD)
			{    
				return 0;
			}
		}
	}

	return 1;
}

//To check if the grid remaiins the same after a generation.
int same(char grid[][DIM_COL+2],char new[DIM_ROW+2][DIM_COL+2])
{   
	int r,c;
	for (r=1; r <= DIM_ROW; r++) 
	{
		for (c=1; c <= DIM_COL; c++)
		{   
			if(grid[r][c]!=new[r][c])
			{    
				return 0;
			}
		}
	}

	return 1;
}



