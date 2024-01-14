/*
Autor: Antoni Wiœniewski
Nr indeksu: 333516
Gra w Statki

utworzy³em ten rozdzia³ na dwa pliki aby oddzieliæ funkcje gry od logiki gry*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "warships.h"
#include "winbgi2.h"

int main()
{
	graphics(swidth, sheight);
	switch (welcomeScreen())
	{
	case 0:
		return 0;
	case 1:
		Ship player_ships[10] = { 0 };
		Ship enemy_ships[10] = { 0 };
		int control_tab[10][10] = {
			{1,1,1,1,1,1,0,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1}};
		random_CPU_ships(enemy_ships, control_tab);
		displayBoard();
		wait();
		break;
	}
	return 0;
}