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
void displayBoard()
{
	clear();
	rectangle(5, 5, x_end, y_end);
	//podzia³ka na graczy
	line(screenOffset_width / 2.0, 5, screenOffset_width / 2.0, y_end);
	//podzia³ka pola jednego gracza 1:2
	line(5, 2 * screenOffset_height / 3.0, x_end, 2 * screenOffset_height / 3.0);
	//plansza gracza i komputera
		//gracz



	//gracz
	line(left_screenOffset+left_plane_leftOffset, upper_screenOffset+left_plane_upperOffset,
		left_screenOffset + left_plane_leftOffset, (2 * screenOffset_height / 3.0) - left_plane_lowerOffset);
	line(left_screenOffset + left_plane_leftOffset, (2 * screenOffset_height / 3.0) - left_plane_lowerOffset,
		(screenOffset_width / 2.0) - left_plane_rightOffset, (2 * screenOffset_height / 3.0) - left_plane_lowerOffset);
	line((screenOffset_width / 2.0) - left_plane_rightOffset, (2 * screenOffset_height / 3.0) - left_plane_lowerOffset,
		(screenOffset_width / 2.0) - left_plane_rightOffset, upper_screenOffset+left_plane_upperOffset);
	line((screenOffset_width / 2.0) - left_plane_rightOffset, upper_screenOffset + left_plane_upperOffset,
		left_screenOffset + left_plane_leftOffset, upper_screenOffset + left_plane_upperOffset);
	//komputer
	line((screenOffset_width / 2.0) + right_plane_leftOffset, right_plane_upperOffset+upper_screenOffset,
		(screenOffset_width / 2.0) + right_plane_leftOffset, (2 * screenOffset_height / 3.0) - right_plane_lowerOffset);
	line((screenOffset_width / 2.0) + right_plane_leftOffset, (2 * screenOffset_height / 3.0) - right_plane_lowerOffset,
		screenOffset_width - right_plane_rightOffset, (2 * screenOffset_height / 3.0) - right_plane_lowerOffset);
	line(screenOffset_width - right_plane_rightOffset, (2 * screenOffset_height / 3.0) - right_plane_lowerOffset,
		screenOffset_width - right_plane_rightOffset, right_plane_upperOffset+upper_screenOffset);
	line(screenOffset_width - right_plane_rightOffset, right_plane_upperOffset + upper_screenOffset
		, (screenOffset_width / 2.0) + right_plane_leftOffset, right_plane_upperOffset + upper_screenOffset);
	//szachownica dla garcza i prawie dla komputera
	for (int i = 1; i < 10; i++)
	{
		//szachownica dla gracza
		line((i / 10.0) * left_plane_lenght + left_plane_leftOffset+left_screenOffset,upper_screenOffset+left_plane_upperOffset , (i / 10.0) * left_plane_lenght + left_plane_leftOffset + left_screenOffset, (2 * screenOffset_height / 3.0) - left_plane_lowerOffset);
		line(left_screenOffset+left_plane_leftOffset, (i / 10.0) * left_plane_height + left_plane_upperOffset+upper_screenOffset, (screenOffset_width / 2.0) - left_plane_rightOffset, (i / 10.0) * left_plane_height + left_plane_upperOffset+ upper_screenOffset);

		line((i / 10.0) * right_plane_lenght + right_plane_leftOffset + screenOffset_width/2.0, upper_screenOffset + right_plane_upperOffset, (i / 10.0) * right_plane_lenght + right_plane_leftOffset + screenOffset_width / 2.0, (2 * screenOffset_height / 3.0) - right_plane_lowerOffset);
		line(screenOffset_width / 2.0 + right_plane_leftOffset, (i / 10.0) * right_plane_height + right_plane_upperOffset + upper_screenOffset, screenOffset_width - right_plane_rightOffset, (i / 10.0) * right_plane_height + right_plane_upperOffset + upper_screenOffset);


	}

}

int welcomeScreen()
{
	int option = 0;
	const char* welcome_msg = "WARSHIPS v0.1";
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 7);
	outtextxy(1000 / 2., title_upperOffset, welcome_msg);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	outtextxy(1000 / 2., title_upperOffset + 150, "Play");
	outtextxy(1000 / 2., title_upperOffset + 300, "Quit");
	//while (!(mousedown())) //FUNKCJA DO TESTÓW
	//{
	//	printf("x: %d y: %d\n", mousecurrentx(), mousecurrenty());
	//	system("cls");
	//}
	while (true)
	{
		if (mousedown())
		{
			if (mouseclickx() > 422 && mouseclickx() < 581 && mouseclicky() > 324 && mouseclicky() < 357) option = 1;
			if (mouseclickx() > 425 && mouseclickx() < 575 && mouseclicky() > 473 && mouseclicky() < 500) option = 2;
		}
		switch (option)
		{
		case 0:
			break;
		case 1:
			printf("PLAYING MODE\n");
			return 1;
		case 2:
			return 0;
		}
	}
	return 0;
}

void cords_to_matrix(int x, int y, int** tab, int mode)
{
	if (mode)
	{

	}
	else
	{

	}
}
void drawShips(Ship* ship_tab,int player_type)
{

}
void random_CPU_ships(Ship* enemy_tab, int** control_tab)
{
	int ship_type = 1;
	int ship_made[4] = { 4,3,2,1 };
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		switch (ship_type)
		{
		case 1:
			if (ship_made[ship_type - 1] == 0)
			{
				ship_type++;
				break;
			}
			while (true)
			{
				int w = rand() % 10;
				int k = rand() % 10;
				if (control_tab[w][k] == 0 &&
					control_tab[w - 1][k] == 0 &&
					control_tab[w - 1][k + 1] == 0 &&
					control_tab[w][k + 1] == 0 && //x=k;y=w
					control_tab[w + 1][k + 1] == 0 &&
					control_tab[w + 1][k] == 0 &&
					control_tab[w + 1][k - 1] == 0 &&
					control_tab[w][k - 1] == 0 &&
					control_tab[w - 1][k - 1] == 0)
				{
					control_tab[w][k] = ship_type;
					enemy_tab[i].x_back = k;
					enemy_tab[i].x_front = k;
					enemy_tab[i].y_front = w;
					enemy_tab[i].y_back = w;
					ship_made[ship_type - 1]--;
					break;
				}
			}
			break;
		case 2:
			if (ship_made[ship_type - 1] == 0)
			{
				ship_type++;
				break;
			}
			while (true)
			{
				int w = rand() % 10;
				int k = rand() % 10;
				if (control_tab[w][k] == 0 &&
					control_tab[w - 1][k] == 0 &&
					control_tab[w - 1][k + 1] == 0 &&
					control_tab[w][k + 1] == 0 && //x=k;y=w
					control_tab[w + 1][k + 1] == 0 &&
					control_tab[w + 1][k] == 0 &&
					control_tab[w + 1][k - 1] == 0 &&
					control_tab[w][k - 1] == 0 &&
					control_tab[w - 1][k - 1] == 0)
				{

				}
			}
		}
	}
}