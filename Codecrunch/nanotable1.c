/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * This program uses loops to allow the user to enter different commands like help,average, sum etc until the user terminates it by typing exit
 * Leah Roselyn James
 * Tutorial T05
 */
 
 
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100
#define MAX_ENTRIES 100

int count_entries(int []);
int insert_table(int [],int [],int );
void clear_table(int [],int [],int);
int sum_table(int []);
void ave_table(int []);
void rank_table(int [],int [],int);
void print_help();

int main(void) 
{
    int i,p=0;
    int sum, table[MAX_ENTRIES]={0},id[MAX_ENTRIES], table_empty = 1;
    char input[MAX_COMMAND_LENGTH];

    
    printf("Welcome to Nanotable!\n");
    printf("Type \"help\" for more information...\n");

    while (TRUE) 
    {
        printf("Waiting for command...\n");
        scanf("%s", input);

        if (strcmp(input,"help") == 0)
        {    
            print_help();
        }
        else if (strcmp(input,"exit") == 0)
        {
            printf("See you!\n");
            break;
        }

        else if (strcmp(input,"sum") == 0)
        {
            // Need to determine whether the table is empty
            if (table_empty == 1)
            {    
                printf("The table is empty\n");
            }
            else 
            {
                sum = sum_table(table);
                printf("The sum of score is %d\n", sum);
            }
        }

        else if (strcmp(input,"ave") == 0) 
        {
            if (table_empty == 1)
            {    
                printf("The table is empty\n");
            }
            else
            {    
                ave_table(table);
            }
        }

        else if (strcmp(input,"insert") == 0) 
        {
            table_empty = 0;
            p=insert_table(table,id,p);
            p+=1;
            
        }

        else if (strcmp(input,"init") == 0) 
        {
            table_empty = 1;
            clear_table(table,id,p);
            p=0;
        }

        else if (strcmp(input,"rank") == 0) 
        {
            if (table_empty == 1)
            {   
                 printf("The table is empty\n");
            }
            else
            {    
                rank_table(table,id,p);
            }
        }

        else
         {   
             printf("No such command: %s, please input command again!\n", input);
         }
    }
    
     return 0;
}

// This function calculates the number of entries in the table
int count_entries(int table[]) 
{
    int i, count = 0;
    for(i = 0; i < MAX_ENTRIES; i++) 
    {
        if(table[i] != 0)
            count++;
    }

    return count;
}

// This function inserts a value corresponding to the student's ID into the table
int insert_table(int table[],int id[],int p) 
{
    
    printf("Please input the student's ID...\n");
    scanf("%d", &id[p]);
    printf("Please input the student's score...\n");
    scanf("%d", &table[p]);
    
    int count=p;
    while(count!=0)
    {
     if ((table[count]<table[count-1])||(table[count]==table[count-1]&&id[count]<id[count-1]))
      {   
          int temp=table[count];
          table[count]=table[count-1];
          table[count-1]=temp;
          
          temp=id[count];
          id[count]=id[count-1];
          id[count-1]=temp;
          
          
      }
      
      count-=1;
    }
 
         return p;
   
}

// This function empties the entire table
void clear_table(int table[],int id[],int p) 
{
    int i;

    for(i = 0; i <= p; i++)
    {   
        table[i] = 0;
        id[i]=0;
    }
    

    printf("Initializing table...\n");
}

// This function finds the sum of the values in the table
int sum_table(int table[]) {
    int i, sum = 0;

    for(i = 0; i < MAX_ENTRIES; i++) 
    {
        if(table[i] != 0)
            sum += table[i];
    }

    return sum;
}

// This function finds the average of the values in the table
void ave_table(int table[]) 
{
    int sum, count;
    double average;

    sum = sum_table(table);
    count = count_entries(table);
    average = sum * 1.0 / (count * 1.0);

    printf("The average of score is %.0lf\n", round(average));
}

// This function prints the student ID and score of the rank-th entry in the table
void rank_table(int table[],int id[],int p) 
{
    
    int input_rank;
    while(1)
    {
        printf("Please input the rank (1 - %d)...\n", p);
        scanf("%d", &input_rank);
        
        if(input_rank<(p+1))
        {
           printf("ID: %d, Score: %d\n", id[input_rank-1], table[input_rank-1]);
           break;
        }
       else
        {  
           printf("Invalid rank: %d\n",input_rank);
        }
    }
       
}


// This function prints the help information
void print_help() 
{
    printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}