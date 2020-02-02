/**
* CS1010 AY2017/8 Semester 1 Lab6 Ex1
* prerequisites.c
* This program finds the prerequisites of a inputed module from the list of arrays.
* TD05
* Leah Roselyn James
*/

# include<stdio.h>
#include<string.h>
#define MAX_MOD  10
#define MAX_LEN  7
int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);

int main(void) 
{
	
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],         // the list of modules codes
		 target[MAX_LEN],                 // the target module
		 prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target module
	
	numModules = scanModules(codes);
	
	printf("Choose a module: ");
	scanf("%s", target);
	
	numPrereq = computePrereq(codes, numModules, target, prerequisites);
	printPrereq(prerequisites, numPrereq, target);
	
	return 0;
}

// This function reads modules into an array. 
int scanModules(char codes[][MAX_LEN])
{
	int i, num;
	printf("Enter number of modules: ");
	scanf("%d",&num);
	printf("Enter %d modules:\n", num);
	for(i = 0; i < num; i++)
		scanf("%s",codes[i]);
	return num;
}

//This function computes the prerequisites of a given module and return an integer to indicate whether it has been found or not.
int computePrereq(char codes[][MAX_LEN], int numModules, char target[], char prerequisites[][MAX_LEN])
{ 
	int i,k,l=0,count=0,check=0,sum=0;
	for(i=0;i<numModules;i++)
	{  

		if (strcmp(codes[i],target)==0)
		{      check=1;
			continue;
		}
		else
		{ 
			if(codes[i][0]==target[0])
				count+=1;
			if(codes[i][2]<target[2])
				count+=1;
			for(k=3;k<strlen(target);k++)
			{    if(codes[i][k]<=target[k])
				sum+=1;
			}
			if(sum==3)
				count+=1;

			if(count==3)
				strcpy(prerequisites[l++],codes[i]);

			count=0;
			sum=0;
		}
	}

	if(check==1)
		return l;
	else
		return -1;
}

// Print the prerequisites
// This function is given. You are NOT to modify it.
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) 
{
	int i;
	if (numPrereq == -1) 
	{
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) 
	{
		printf("No prerequisites for %s\n", target);
	}
	else 
	{
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++)
		{
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}

