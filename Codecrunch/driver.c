/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex2
 * driver.c
 * This program calculate the possible routes given an array of gas stations available within distance.
 * Leah Roselyn James
 * TD05
 */

#include <stdio.h>
#define MAX_STATIONS 20

void readStations(int [], int [], int *, int *);
void printStations(int [], int [], int, int);
int calcPossibleRoutes(int fuels[],int totalDist,int num,int numStation, int totf);

int main() 
{
	int distances[MAX_STATIONS];
	int fuels[MAX_STATIONS];
	int totalDist, numStation;
	int possibleRoute,num=0,totf=100,f;

	readStations(distances, fuels, &totalDist, &numStation); 
	printStations(distances, fuels, totalDist, numStation); 
	
	if(totalDist<=100)
		f=1;
	else
	{
		possibleRoute = calcPossibleRoutes(fuels,totalDist,num,numStation, totf);
        f=numStation-possibleRoute+1;
	}	
	printf("Possible number of routes = %d\n", f);

	return 0;
}

// Read the gas stations' distances and available fuel 
// and return the total distance and number of gas stations read.
// Note: Do not change this function
void readStations(int distances[], int fuels[], int *totalDistPtr, int *numStationPtr) 
{
	int i;
	
	printf("Enter total distance: ");
	scanf("%d", totalDistPtr);
	printf("Enter number of gas stations: ");
	scanf("%d", numStationPtr);
	printf("Enter distance and amount of fuel for each gas station:\n");
	// gasStation Array will store in such way [dist0, fuel0, dist1, fuel1, dist2, fuel2, ...]
	
	for (i = 0; i < *numStationPtr; i++) 
	{
		scanf("%d %d", &distances[i], &fuels[i]);
	}
}

// Print total distance and gas stations' distances and fuel
// Note: Do not change this function
void printStations(int distances[], int fuels[], int totalDist, int numStation) 
{
	int i;
	printf("Total distance = %d\n", totalDist);
	printf("Number of gas stations = %d\n", numStation);
	printf("Gas stations' distances: ");
	
	for (i = 0; i < numStation; i++) 
	{
		printf("%4d ", distances[i]);
	}
	printf("\n");
	printf("Gas stations' fuel amt : ");
	for (i = 0; i < numStation; i++) 
	{
		printf("%4d ", fuels[i]);
	}
	printf("\n");
}

//This recursive function takes in the sum and returns the last index number at which the fuel amount has been reached.
int calcPossibleRoutes( int fuels[],int totalDist,int num,int numStation,int totf)
{   

	totf+=fuels[num];
	if(totf<totalDist && num<numStation )
		return calcPossibleRoutes(fuels, totalDist, num+1 ,numStation, totf);
	else 
		return num+1; 

}

