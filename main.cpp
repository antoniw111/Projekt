/*
Autor: Antoni Wiœniewski
Nr indeksu: 333516
Gra w Statki

utworzy³em ten rozdzia³ na dwa pliki aby oddzieliæ funkcje gry od logiki gry*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "warships.h"
#include "winbgi2.h"

int main()
{
	/*int w = 0;
	int k = 0;*/ //used for debug

	int last_CPU_hit[2] = { 0 }; //ostatnie trafienie komputera
	bool did_CPU_hit = false; //czy komputer trafil ostatnie
	bool game = true; //do petli gry
	int win = -1; // status wygranej 0 komputer; 1 gracz;-1 nikt

	setcolor(WHITE);
	graphics(swidth, sheight);
	switch (welcomeScreen())
	{
	case 0:
		return 0;
	case 1:
		int enemy_control_tab[10][10] = { 0 }; //tablice kontrolne gracza i komputera
		int player_control_tab[10][10] = { 0 };
		int player_ships[4] = { 4*1,3*2,2*3,1*4 };//tablice segmentow poszczegolnych statkow {1-masz,2-masz,3-maszt,4-maszt}
		int enemy_ships[4] = { 4*1,3*2,2*3,1*4 };
			/*{1,1,1,1,1,1,0,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1}};*/ //DEBUG ONLY
		displayInstrucions();
		random_CPU_ships(enemy_control_tab);
		displayBoard();
		place_PLAYER_ships(player_control_tab,enemy_control_tab);
		/*for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				printf("%d ", enemy_control_tab[i][j]);
			}
			printf("\n");
		}*/ //ONLY FOR DEBUG
		while (game)
		{
			displayBoard();
			drawShips(player_control_tab,enemy_control_tab, 1);
			drawScore(player_ships, enemy_ships);
			win = PLAY(player_control_tab, enemy_control_tab, player_ships, enemy_ships, last_CPU_hit, &did_CPU_hit);
			if (win != -1) game = false;
			
			delay(1000. / 165.);
		}
		clear();
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		if (win == 1) outtextxy(1000 / 2., 800 / 2.,"WYGRALES");
		if (win == 0) outtextxy(1000 / 2., 800 / 2.,"PRZEGRALES");
		wait();
		break;
	}
	return 0;
}