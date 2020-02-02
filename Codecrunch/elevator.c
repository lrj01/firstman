/**
* CS1010 AY2019/20 Semester 1 Lab6 Ex3
* elevator.c
* This program simulates the elevator's movement and return the end state 
* Leah Roselyn James
* T05
*/

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	int currentFloor;
	int passengers;
	int usage;
} elevator_t;

//Function prototype
void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);


int main(void)
{
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];

	printf("Enter number of elevators: ");
	scanf("%d", &size);

	setupElevators(elevators, size);
	readSequences(sequences, size);

	runElevators(elevators, sequences, size);

	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));

	return 0;
}

//This functions initalizes n number of elevators array to the respective values
void setupElevators(elevator_t elevators[], int size)
{
	int i;
	for(i = 0; i < size; i ++)
	{ 
		elevators[i].currentFloor = 1;
		elevators[i].passengers = 0;
		elevators[i].usage = 0;
	}
}	

// Read in the sequences of floors the elevators go to.
void readSequences(char sequences[][MAX_LEN], int size)
{
	int i;

	for (i = 0; i<size; i++)
	{
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

//This functions simulates the elevator as it goes through the sequence
void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size)
{
	int i,j,len;
	for(i = 0; i < size; i ++)
	{ 
		len = strlen(sequences[i]);
		for(j = 0; j < len; j++)
		{ 
			goToFloor(&elevators[i],sequences[i][j]-48);
		}
	}
}

//This function updates the number of passengers,floor and usage after every level
void goToFloor(elevator_t *elevator, int floor)
{
	if((*elevator).currentFloor < floor) 
	{
		elevator->passengers += floor; 
		if(elevator->passengers > 15) 
		{
			elevator->passengers = 15;
		}
		elevator->currentFloor = floor;
	}
	else if(elevator->currentFloor > floor)
	{
		if(elevator->passengers > 0)
		{
			if(elevator->passengers < floor)
			{
				(*elevator).usage += elevator->passengers;   
				elevator->passengers = 0;
			}
			else
			{
				elevator->passengers -= floor; 
				(*elevator).usage += floor; 
			}
		}
		elevator->currentFloor = floor;
	}
}

//This functions prints the respective value in elevator_t structure for each element in the array
void printElevators(elevator_t elevators[], int size)
{
	int i;
	for(i = 0; i < size; i ++)
	{
		printf("Elevator %d:\n",i+1); 
		printf("Floor: %d\n",elevators[i].currentFloor);
		printf("Number of passengers: %d\n",elevators[i].passengers);
		printf("Usage: %d\n",elevators[i].usage);
	}
}

//This functions computes the elevator with highest usage
int mostUsedElevator(elevator_t elevators[], int size)
{
	int i, max = -1, mostUsed;
	for(i = 0; i < size; i++)
	{
		if(elevators[i].usage > max)
		{
			max = elevators[i].usage;
			mostUsed = i+1;
		} 
	}
	return mostUsed;
}

