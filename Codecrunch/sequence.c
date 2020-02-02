/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * Leah Roselyn James
 * T05
 */

#include <stdio.h>
#define DIM 12

int search(int arr[][DIM],int k,int *pr, int *pc);
int scanBoard(int arr[][DIM]);
int length1(int arr[][DIM],int r, int c,int k);
int length2(int arr[][DIM],int r, int c,int k);
int length3(int arr[][DIM],int r, int c,int k);

int main(void) 
{
	int board[DIM][DIM];     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board
	// call scanBoard() 
	int key=scanBoard(board);
	length=search(board,key,&bestRow,&bestCol);	// call search()
	if (length > 0) 
	{
		printf("Length of longest sequence = %d\n", length+1); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");
	return 0;
}
// This function scans the values of the board from the user.
int scanBoard(int arr[][DIM])
{ int i,j,key;
	for(i=0;i<DIM;i++)
	{  
		for(j=0;j<DIM;j++)
		{ 
			scanf("%d",&arr[i][j]);
		}
	}
	scanf("%d",&key);
	return key;
}
// This function find the maximum length of k at the minimum row and column.
int search(int arr[][DIM],int k, int *prow, int *pcol) 
{   

	int i ,j,r,c,len=0,max=0,min_r,min_c,flag;



	len=0;flag=0;
	for(r=0;r<DIM-1;r++)
	{       
		for(c=0;c<DIM-1;c++)
		{   
			if(arr[r][c]==k)
			{    
				if(arr[r][c+1]==k || arr[r+1][c]==k || arr[r+1][c+1]==k)
				{   

					int len1=length1(arr,r,c,k);
					int len2=length2(arr,r,c,k);
					int len3=length3(arr,r,c,k);
					if(len1>=len2 && len1>=len3)
					{   
						len+=len1;
					}
					else if(len2>=len1 && len2>=len3)
					{   
						len+=len2;
					}
					else   
					{   
						len+=len3;
					}

					if(len>max|| (len==max && r<=min_r && c<=min_c))
					{ 
						max=len;
						min_r=r;
						min_c=c;
					}
					len=0;
				}


			}

		}
	}





	*prow=min_r;
	*pcol=min_c;

	return max;
}
//This function finds the the maximum length to the right of the given position and returns the length.
int length1(int arr[][DIM],int r, int c,int k)
{   

	int len=0,i,j,flag=0; 
	for(i=r;i<DIM-1;i++)
	{
		for(j=c;j<DIM-1;j++)
		{
			if(arr[i][j+1]==k )
			{   

				len+=1;

			}
			else
			{ flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	return len;
}
//This function finds the the maximum length to the bottom of the given position and returns the length.
int length2(int arr[][DIM],int r, int c,int k)
{   int len=0,i,j,flag=0; 
	for(i=r;i<DIM-1;i++)
	{
		for(j=c;j<DIM-1;j++)
		{
			if(arr[i+1][j]==k )
			{   
				i=i+1;
				j=j-1;
				len+=1;
			}          
			else
			{  
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	return len;
}
//This function finds the the maximum length to the south-east of the given position and returns the length.
int length3(int arr[][DIM],int r, int c,int k)
{   int len=0,i,j,flag=0; 
	for(i=r;i<DIM-1;i++)
	{
		for(j=c;j<DIM-1;j++)
		{
			if(arr[i+1][j+1]==k )
			{   
				i=i+1;
				len+=1;

			}
			else
			{   flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	return len;
}
