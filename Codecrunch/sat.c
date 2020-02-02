#include<stdio.h>
void compute_percentile(int ,int, int);
void compute_iqscore(int,int,int);
int main(void) 
{
	int verbal, math, writing ; // user’s input
	printf("Enter scores: ");
	scanf("%d %d %d",&verbal,&math, &writing);
	compute_percentile(verbal, math, writing);
	compute_iqscore(verbal, math, writing);
	return 0;
}
void compute_percentile(int verbal,int math, int writing)
{ int sum=verbal+math+writing;
	if(sum>=2200)
		printf("The SAT score is in the 99 percentile.\n");
	else if( sum>=2000)
		printf("The SAT score is in the 95 percentile.\n");
	else if(sum>=1500)
		printf("The SAT score is in the 50 percentile.\n");
	else
		printf("The SAT score is in the 10 percentile.\n");

}

void compute_iqscore(int verbal,int math,int writing)
{  float IQ = 0.095*math + 0.003* verbal + 50.241;
	if ((verbal>600 && math>600 && writing>600)||IQ>=120)
	{ printf("The IQ score is %0.2f\n",IQ);
		printf("Wow, this is amazing!\n");
	}
	else
	{ printf("The IQ score is %0.2f\n",IQ);	
	}

}
