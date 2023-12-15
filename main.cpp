#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
void ramka();
int main()
{
	graphics(1000, 800);
	ramka();
	
	wait();
	return 0;
}
void ramka()
{
	line(5, 5, 990, 5);
	line(5, 5, 5, 780);
	line(990, 5, 990, 780);
	line(5, 780, 990, 780);
	line((double)(990 - 5) / 2, 5, (double)(990 - 5) / 2, 780);//podzia³ka na graczy
}