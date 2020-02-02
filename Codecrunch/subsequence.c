/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the k-interval subsequence with the largest sum.
 * Leah Roselyn James
 * Tutorial T05
 */

#include <stdio.h>

int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) 
{
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // stores the required answers

	size = scan_list(list); 

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) 
{
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}
      
	return num;
}

// This function checks every interval k at every position i to find the maximum sum with the minimum position 
//   ans[0] = maximum sum of solution subsequence
//   ans[1] = interval k of the solution subsequence
//   ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) 
{  
    int k=1,sum,i,j,interval,position,max;
    max=arr[0];
    interval=1;
    position=0;
    
    while(k<=size)
    {    
        for(i=0;i<size;i++)
        {  
           sum=0;
           for(j=i;j<size;j+=k)
           { 
               sum+=arr[j];
           }
           
           if(sum>max)
           {
             max=sum;
             interval=k;
             position=i;
               
            }
        }
        
        k+=1;
    }
	
   ans[0]=max;
   ans[1]=interval;
   ans[2]=position;
    
   
}