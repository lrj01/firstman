#include<stdio.h>
#define M1 31
#define M2 28
#define M3 30

int computeDays();
int main()
{  int days; int month;
   printf("Enter day and month: ");
   scanf("%d %d",&days,&month);
   printf("Day %d of month %d is the %dth day of 2017.\n",days,month,computeDays(days,month));
   return 0;
}
int computeDays(int days,int month)\
{  int totdays;
   switch(month)
  {     case 1: totdays=days;
              break;
        case 2:totdays=days+M1;
		      break;
	    case 3:totdays=days+M1+M2;
		      break;
	    case 4:totdays=days+M2*2+M1;
		      break;
		case 5:totdays=days+M2+M1*2+M3;
		      break;
		case 6:totdays=days+M2+M1*3+M3;
		      break;
		case 7:totdays=days+M2+M1*3+M3*2;
		      break;
		case 8:totdays=days+M2+M1*4+M3*2;
		      break;
		case 9:totdays=days+M2+M1*5+M3*2;
		      break;
		case 10:totdays=days+M2+M1*5+M3*3;
		       break;
		case 11:totdays=days+M2+M1*6+M3*3;
		       break;
		case 12:totdays=days+M2+M1*6+M3*4;
		       break;

  }
   return totdays;
}
