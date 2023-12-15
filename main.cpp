#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
void displayBoard();
int main()
{
	graphics(1000, 800);
	displayBoard();
	
	wait();
	return 0;
}
void displayBoard()
{
	//obramowanie
	/*line(5, 5, 990, 5);
	line(5, 5, 5, 780);
	line(990, 5, 990, 780);
	line(5, 780, 990, 780);*/
	//powy¿sze instrukcje zast¹pi³em rectangle'm
	rectangle(5, 5, 990, 780);
	//podzia³ka na graczy
	line((double)(990 - 5) / 2, 5, (double)(990 - 5) / 2, 780);
	line(5, (double)2*(780 - 5)/3, 990, (double)2*(780 - 5)/3);
	//plansza gracza
	rectangle(30, 30, ((990-5)/2)-30, (2 * (780 - 5) / 3)-30);
}