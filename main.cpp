/*
Autor: Antoni Wiœniewski
Nr indeksu: 333516
Gra w Statki

utworzy³em ten rozdzia³ na dwa pliki aby oddzieliæ funkcje gry od logiki gry*/

#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include "warships.h"

int main()
{
	graphics(swidth, sheight);
	switch (welcomeScreen())
	{
	case 0:
		return 0;
	case 1:
		displayBoard();
		wait();
		break;
	}
	return 0;
}