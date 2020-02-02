/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * This program simulates a way for the frogs to cross the bridge. 
 * Leah Roselyn James
 * Tutorial T05
 */

#include <stdio.h>

void jump (int [], int, int []);
void printBridge (int, int[]);
int checkstate (int[], int);

int main (void)
{
	int bridge[1000];
	int i;
	int lengthOfBridge;
	printf ("Please enter the length of the bridge: ");
	scanf ("%d", &lengthOfBridge);
	int start=0,end=lengthOfBridge-1,check[lengthOfBridge];
	for (i = 0; i < lengthOfBridge; i++)
	{
		int frogType;
		printf ("Please insert frogs at position %d: ", i);
		scanf ("%d", &frogType);
		bridge[i] = frogType;
		if(frogType<0)
		{  
			check[start++]=frogType;
		}
		else
		{  
			check[end--]=frogType;
		}
	}
	check[start]=0;
	printf ("Input completed\n");
	printBridge (lengthOfBridge, bridge);
	printf ("Please start moving the frogs\n");
	jump (bridge, lengthOfBridge,check);
	return 0;
}

/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge (int size, int bridge[])
{
	int i;
	printf ("Position: ");
	for (i = 0; i < size; i++)
	{
		printf ("%2d ", i);
	}
	printf ("\n");
	printf ("Bridge:   ");
	for (i = 0; i < size; i++)
	{
		printf ("%2d ", bridge[i]);
	}
	printf ("\n");
}

// This function enables the frogs to jump only in the intended direction and only terminates the loop if all the frogs have successfully crossed or there are no moves left to play.
void jump (int arr[], int len, int check[])
{
	int position,j, i,jump=0,count=0;
	while (1)
	{
		count=0;
		printf ("Move the frog at position: ");
		scanf ("%d", &position);
		for (i = 0; i < len; i++)
		{
			if (arr[i] == 0)
			{
				if (fabs (i - position) <= 2 && arr[position] != 0)
				{
					if ((arr[position] == -1 && i < position) || (arr[position] == 1 && i > position))
					{
						int temp = arr[position];
						arr[position] = arr[i];
						arr[i] = temp;
						printBridge (len, arr);
						jump+=1;
						break;
					}
					else
					{
						printf ("Invalid move!\n");
					}
				}
				else
				{
					printf ("Invalid move!\n");
				}
			}
		}
		for(j=0;j<len;j++)
		{  
			if(check[j]==arr[j])
			{
				count+=1;
			}
		}
		if(count==len)
		{ 
			printf("Congratulations! The frogs took %d jumps to cross the bridge!\n",jump);	
			break;
		}
		if (checkstate (arr, len) == 1)
		{
			printf("Oh no! It seems like the two clans of frogs are stuck!\n");
			break;
		}
	}
}

//This function checks the state of the frogs after every position enetered by the user and returns 1 if there are no moves left to play.
int checkstate (int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == 0 && (i == 0 || i == size - 1))
		{
			if (i == 0 && arr[i + 1] == 1 && arr[i + 2] == 1)
			{
				return 1;
			}
			if (i == (size - 1) && arr[i - 1] == -1 && arr[i - 2] == -1)
			{
				return 1;;
			}
		}
	}

	return 0;
}

