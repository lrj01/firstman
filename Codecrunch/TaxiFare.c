#include<stdio.h>
#include<math.h>
float computeFare(int,int,int);
int main()

{ int dayType,boardHour, boardMin,distance;
	printf("Day type: ");
	scanf("%d",&dayType);
	printf("Boarding hour and minute: ");
	scanf("%d %d",&boardHour,&boardMin);
	printf("Distance: ");
	scanf("%d",&distance);

	int boardTime=boardHour*60+boardMin;
	printf("Boarding time is %d minutes\n",boardTime);
	printf("Total taxi fare is $%0.2f\n",computeFare(dayType,boardTime,distance));
	return 0;
}	
float computeFare(int dayType, int boardTime, int distance)
{  int diff=distance-1000;int diff2=distance-10200;
	double fare;	    
	
	if (distance<=1000)
	{   fare=3.4;
	}
	else  if(distance<=10200&&distance>1000)
	{   

		fare=3.4+(0.22*ceil(diff/400.0));
	}
	else 
	{   
		fare=3.4+(23*0.22+0.22*ceil(diff2/350.0));
	}

	double totfare;
	if(dayType==0)
	{ if(boardTime>=0 && boardTime<=359)
		{ totfare=fare+fare*0.5;
		}
		else  if(boardTime>=360 && boardTime<=569)
		{ totfare=fare;
		}
		else  if(boardTime>=1080 && boardTime<=1439)
		{ totfare=fare+(ceil(fare*0.25*100)/100);
		}
		else
		{  totfare=fare;
		}
	}
	else
	{
		if(boardTime>=0 && boardTime<=359)
		{ totfare=fare+fare*0.5;
		}
		else  if(boardTime>=360 && boardTime<=569)
		{ totfare= fare+(ceil(fare*0.25*100)/100);
		}
		else  if(boardTime>=1080 && boardTime<=1439)
		{ totfare= fare+(ceil(fare*0.25*100)/100);							         
		}
		else
		{ totfare=fare;
		}
	}
	return totfare;

}
