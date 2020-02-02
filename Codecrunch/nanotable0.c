/**
 * CS1010 AY2019/20 Semester 1 Lab2 Ex1
 * nanotable0.c
 * This program uses loops to allow the user to enter different commands like help,average, sum etc until the user terminates it by typing exit
 * Leah Roselyn James
 * Tutorial T05
 */


#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();
int check_command(char* input);
void print_help();
int simple_sum();
int simple_average();
int enddigit(int);

int main() 
{

	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");
	parse_command();

	return 0;
}

//This function acts like a menu for the user to choose the command available.
int parse_command() 
{
	char command[100];
	int command_code;
	int n=1;
	while(n>=0)
	{	
		printf("Waiting for command...\n");
		scanf("%s", command);

		command_code = check_command(command);    

		if(command_code == COMMAND_HELP) 
		{
			print_help();
		}
		else if(command_code == COMMAND_EXIT)
		{
			printf("See you!\n");
			break;
		}
		else if(command_code == COMMAND_SUM)
		{
			simple_sum();
		}
		else if(command_code == COMMAND_AVE)
		{
			simple_average();
		}
		else 
		{
			// others
			printf("No such command: %s, please input command again!\n",command);
		}

		n++;
	}
	return 0;
}

//This function calculates the sum of numbers that the user inputs. 
int simple_sum() 
{
	int i=1; int num;int dig;
	printf("Please indicate the number of integers:\n");
	scanf("%d",&num);
	int sum=0;

	while (i<=num)
	{   if(enddigit(i)==0)
		{   
			printf("Please input the %dth number:\n",i);
			scanf(" %d",&dig);
		}
		else if(enddigit(i)==1)
		{	
			printf("Please input the %dst number:\n",i);
			scanf(" %d",&dig);
		}
		else if(enddigit(i)==2)
		{	
			printf("Please input the %dnd number:\n",i);
			scanf(" %d",&dig);
		}
		else if(enddigit(i)==3)
		{	
			printf("Please input the %drd number:\n",i);
			scanf(" %d",&dig);
		} 

		sum+=dig;
		i++;
	}

	printf("sum is %d\n",sum);
	return 0;
}

//This function calculates the average of numbers that the user inputs.
int simple_average() 
{
	int i=1;
	int num;
	int dig;
	printf("Please indicate the number of integers:\n");
	scanf("%d",&num);
	double sum=0;

	while (i<=num)
	{   
		if(enddigit(i)==0)
		{   
			printf("Please input the %dth number:\n",i);
			scanf(" %d",&dig);
		}
		else if(enddigit(i)==1)
		{	
			printf("Please input the %dst number:\n",i);
			scanf(" %d",&dig);
		}
		else if(enddigit(i)==2)
		{	
			printf("Please input the %dnd number:\n",i);
			scanf(" %d",&dig);
		}
		else if(enddigit(i)==3)
		{	
			printf("Please input the %drd number:\n",i);
			scanf(" %d",&dig);
		}

		sum+=dig;
		i++;
	}

	int avg=round(sum/num);
	printf("average is %d\n",avg);
	return 0;
}

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) 
{
	if(strcmp(input,"help") == 0) 
	{
		return COMMAND_HELP;
	}
	else if(strcmp(input,"exit") == 0) 
	{
		return COMMAND_EXIT;
	}
	else if(strcmp(input,"sum") == 0) 
	{
		return COMMAND_SUM;      
	}
	else if(strcmp(input,"ave") == 0)
	{
		return COMMAND_AVE;
	}
	else 
	{
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() 
{
	printf("Commands available: sum, ave, help, exit\n");
}

//This function returns an integer than indicates which Ordinal Character should be used based on the end digit or digits. 
int enddigit(int num)
{   int dig;   
	int count=0;
	int newnum=0;
	int rem=num%10;
	while(num!=0)
	{  int rem2=num%10;
		newnum=newnum*10+ rem2;
		count+=1;
		num/=10;
		if (count==2)
		{  
			break;
		}
	}
	if(newnum==11||newnum==21||newnum==31)
	{     
		dig=0; 
	}
	else if(rem==1)
	{ 
		dig=1;
	}
	else if(rem==3)
	{	  
		dig=3;
	}
	else if(rem==2)
	{
		dig=2;
	}
	else 	
	{   
		dig=0;
	}
	return dig;
}

