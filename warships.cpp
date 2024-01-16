/*
Autor: Antoni Wiœniewski
Nr indeksu: 333516
Gra w Statki

utworzy³em ten rozdzia³ na dwa pliki aby oddzieliæ funkcje gry od logiki gry*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
#include <stdbool.h>
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
/// <summary>
/// Funkcja obslugjaca ekran powitalny
/// </summary>
/// <returns> 0 jesli urzytkownik kliknal QUIT</para> 1 jesli kliknal PLAY</returns>
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
/// <summary>
/// Funkcja do tlumaczenia wspolrzednych na ekranie, na indeksy tablicy 2d
/// </summary>
/// <param name="x"> Wspolrzedna na ekranie </param>
/// <param name="y"> Wspolrzedna na ekranie </param>
/// <param name="tab"> Tablica do wpisania </param>
/// <param name="mode"> Wybor tablicy (1-gracz,2-CPU) </param>
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
/// <summary>
/// Funkcja generowania statkow przeciwnika
/// </summary>
/// <param name="enemy_tab">Tablica struktor Ship przeciwnika</param>
/// <param name="control_tab">Tablica pozycji przeciwnika</param>
void random_CPU_ships(Ship* enemy_tab, int control_tab[10][10])
{
	int ship_type = 1;
	int ship_made[4] = { 4,3,2,1 };
	bool place_success = false, heading_success = false;
	int heading = 0; // 1 = góra; 2 = prawo; 3 = dó³ 4 = lewo
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		switch (ship_type)
		{
		case 1:
			place_success = false;
			while (!place_success)
			{
				int w = rand() % 10;
				int k = rand() % 10;
				switch (check_surroundings(w, k, control_tab))
				{
				default:
					control_tab[w][k] = ship_type;
					enemy_tab[i].x_back = k;
					enemy_tab[i].x_front = k;
					enemy_tab[i].y_front = w;
					enemy_tab[i].y_back = w;
					enemy_tab[i].alive = true;
					ship_made[ship_type - 1]--;
					place_success = true;
					break;
				case -1:
					break;
				case -2:
					exit(100); //error handling
					break;
				}
			}
			break;
		case 2:
			place_success = false;
			while (!place_success)
			{
				int w = rand() % 10;
				int k = rand() % 10;
				/*int w = 0;
				int k = 9;*/ //DEBUG ONLY
				switch (check_surroundings(w, k, control_tab))
				{
				case -2:
					exit(100); //error handling
					break;
				case -1:
					break;
				case 0:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 4 + 1; //[1;4]
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1) //góra
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1) //prawo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								enemy_tab[i].x_back = k + 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1) //dó³
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1) // lewo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								enemy_tab[i].x_back = k - 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 1: //losujemy tylko 2 lub trójke czyli prawo i dó³
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 2;
						switch (heading)
						{
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1) //prawo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								enemy_tab[i].x_back = k + 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1) //dó³
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 2: //losujemy wszystko oprócz góry czyli 2,3,4
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3 + 2;
						switch (heading)
						{
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1) //prawo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								enemy_tab[i].x_back = k + 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1) //dó³
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1) // lewo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								enemy_tab[i].x_back = k - 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 3: //wszystko oprócz lewo czyli 1,2,3
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3 + 1;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1) //góra
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1) //prawo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								enemy_tab[i].x_back = k + 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1) //dó³
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 4: //lewo i góra (1 lub 4)
					heading_success = false;
					while (!heading_success)
					{
						heading = (rand() % 2 == 1) ? 1 : 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1)
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1)
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								enemy_tab[i].x_back = k - 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 5:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3;  //muszê zmeiniæ koncepcje bo losowanie z 1,2,4
						if (heading == 0) heading = 1;
						if (heading == 1) heading = 2;
						if (heading == 2) heading = 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1)
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1) //prawo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								enemy_tab[i].x_back = k + 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1) // lewo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								enemy_tab[i].x_back = k - 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 6:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3; //losowanie 1,3,4
						if (heading == 0) heading = 1;
						if (heading == 1) heading = 3;
						if (heading == 2) heading = 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1) //góra
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1) //dó³
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1) // lewo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								enemy_tab[i].x_back = k - 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 7:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 1; //losujemy 1,2
						switch (heading)
						{
						case 1:
							if(check_surroundings(w - 1, k, control_tab) != -1) //góra
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1) //prawo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								enemy_tab[i].x_back = k + 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 8:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 3; //losujemy 3,4
						switch (heading)
						{
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1) //dó³
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 1;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1) // lewo
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								enemy_tab[i].x_back = k - 1;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				}
				//break; //DEBUG ONLY
			}
			break;
		case 3:
			place_success = false;
			while (!place_success)
			{
				int w = rand() % 10;
				int k = rand() % 10;

				/*int w = 0;
				int k = 9*/; //DEBUG ONLY
				switch (check_surroundings(w, k, control_tab))
				{
				case -2:
					exit(100); //error handling
					break;
				case -1:
					break;
				case 0:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 4 + 1; //[1;4]
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w>1 && check_surroundings(w - 2, k, control_tab) != -1) //góra dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k<8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								enemy_tab[i].x_back = k + 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w<8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k>1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								enemy_tab[i].x_back = k - 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 1: //losujemy tylko 2 lub trójke czyli prawo i dó³
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 2;
						switch (heading)
						{
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								enemy_tab[i].x_back = k + 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 2: //losujemy wszystko oprócz góry czyli 2,3,4
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3 + 2;
						switch (heading)
						{
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								enemy_tab[i].x_back = k + 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								enemy_tab[i].x_back = k - 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 3: //wszystko oprócz lewo czyli 1,2,3
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3 + 1;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 1 && check_surroundings(w - 2, k, control_tab) != -1) //góra dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								enemy_tab[i].x_back = k + 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 4: //lewo i góra (1 lub 4)
					heading_success = false;
					while (!heading_success)
					{
						heading = (rand() % 2 == 1) ? 1 : 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 1 && check_surroundings(w - 2, k, control_tab) != -1) //góra dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								enemy_tab[i].x_back = k - 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 5:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3;  //muszê zmeiniæ koncepcje bo losowanie z 1,2,4
						if (heading == 0) heading = 1;
						if (heading == 1) heading = 2;
						if (heading == 2) heading = 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 1 && check_surroundings(w - 2, k, control_tab) != -1) //góra dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								enemy_tab[i].x_back = k + 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								enemy_tab[i].x_back = k - 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 6:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3; //losowanie 1,3,4
						if (heading == 0) heading = 1;
						if (heading == 1) heading = 3;
						if (heading == 2) heading = 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 1 && check_surroundings(w - 2, k, control_tab) != -1) //góra dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								enemy_tab[i].x_back = k - 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 7:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 1; //losujemy 1,2
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 1 && check_surroundings(w - 2, k, control_tab) != -1) //góra dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								enemy_tab[i].x_back = k + 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 8:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 3; //losujemy 3,4
						switch (heading)
						{
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 2;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								enemy_tab[i].x_back = k - 2;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				}
				//break; //DEBUG ONLY
			}
			break;
		case 4:
			place_success = false;
			while (!place_success)
			{
				int w = rand() % 10;
				int k = rand() % 10;

				/*int w = 0;
				int k = 9*/; //DEBUG ONLY
				switch (check_surroundings(w, k, control_tab))
				{
				case -2:
					exit(100); //error handling
					break;
				case -1:
					break;
				case 0:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 4 + 1; //[1;4]
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 2 && check_surroundings(w - 2, k, control_tab) != -1 && check_surroundings(w - 3, k, control_tab) != -1) //góra dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								control_tab[w - 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								enemy_tab[i].x_back = k + 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								enemy_tab[i].x_back = k - 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 1: //losujemy tylko 2 lub trójke czyli prawo i dó³
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 2;
						switch (heading)
						{
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								enemy_tab[i].x_back = k + 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 2: //losujemy wszystko oprócz góry czyli 2,3,4
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3 + 2;
						switch (heading)
						{
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								enemy_tab[i].x_back = k + 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								enemy_tab[i].x_back = k - 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 3: //wszystko oprócz lewo czyli 1,2,3
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3 + 1;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 2 && check_surroundings(w - 2, k, control_tab) != -1 && check_surroundings(w - 3, k, control_tab) != -1) //góra dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								control_tab[w - 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								enemy_tab[i].x_back = k + 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 4: //lewo i góra (1 lub 4)
					heading_success = false;
					while (!heading_success)
					{
						heading = (rand() % 2 == 1) ? 1 : 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 2 && check_surroundings(w - 2, k, control_tab) != -1 && check_surroundings(w - 3, k, control_tab) != -1) //góra dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								control_tab[w - 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								enemy_tab[i].x_back = k - 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 5:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3;  //muszê zmeiniæ koncepcje bo losowanie z 1,2,4
						if (heading == 0) heading = 1;
						if (heading == 1) heading = 2;
						if (heading == 2) heading = 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 2 && check_surroundings(w - 2, k, control_tab) != -1 && check_surroundings(w - 3, k, control_tab) != -1) //góra dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								control_tab[w - 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								enemy_tab[i].x_back = k + 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								enemy_tab[i].x_back = k - 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 6:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 3; //losowanie 1,3,4
						if (heading == 0) heading = 1;
						if (heading == 1) heading = 3;
						if (heading == 2) heading = 4;
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 2 && check_surroundings(w - 2, k, control_tab) != -1 && check_surroundings(w - 3, k, control_tab) != -1) //góra dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								control_tab[w - 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								enemy_tab[i].x_back = k - 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 7:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 1; //losujemy 1,2
						switch (heading)
						{
						case 1:
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 2 && check_surroundings(w - 2, k, control_tab) != -1 && check_surroundings(w - 3, k, control_tab) != -1) //góra dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								control_tab[w - 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w - 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								enemy_tab[i].x_back = k + 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				case 8:
					heading_success = false;
					while (!heading_success)
					{
						heading = rand() % 2 + 3; //losujemy 3,4
						switch (heading)
						{
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								enemy_tab[i].x_back = k;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w + 3;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								enemy_tab[i].x_back = k - 3;
								enemy_tab[i].x_front = k;
								enemy_tab[i].y_front = w;
								enemy_tab[i].y_back = w;
								enemy_tab[i].alive = true;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							break;
						}
					}
					break;
				}
				//break; //DEBUG ONLY
			}
			break;
		}
		if (ship_made[ship_type - 1] == 0)
		{
			ship_type++;
			//break;
		}
	}
}
/// <summary>
/// Funkcja sprawdzajaca otoczenie punktu w tablicy control_tab
/// Nie wyjdzie poza granice
/// <para>Zwraca:</para>
/// -1 nie znaleziono wszytkich mozliwych pustych kratek w punkcie (w,k)<para></para>
/// 0 jesli 9 kratek ze srodkowa w punkcie (w,k) jest puste<para></para>
/// 1 jesli 4 kratki w lewym gornym rogu planszy sa puste<para></para>
/// 2 jesli 6 kratek jest wolne w pierwszym wierszu ale kolumnie innej niz 0 i 9<para></para>
/// 3 jesli 6 kratek jest wolne w pierwszej kolumnie ale w wierszu innym niz 0 i 9<para></para>
/// 4 jesli 4 kratki w prawym dolnym rogu sa puste<para></para>
/// 5 jesli 6 kratek jest wolne w ostatnim wierszu ale kolumnie innej niz 0 i 9<para></para>
/// 6 jesli 6 kratek jest wolne w ostatniej kolumnie ale wierszu innym niz 0 i 9<para></para>
/// 7 jesli 4 kratki w lewym dolnym sa puste<para></para>
/// 8 jesli 4 kratki w prawym gornym rogu sa puste<para></para>
/// </summary>
/// <param name="w"> = Numer wiersza do sprawdzenia</param>
/// <param name="k"> = Numer kolumny do sprawdzenia</param>
/// <param name="control_tab"> = Tablica pozycji</param>
int check_surroundings(int w, int k, int control_tab[10][10])
{
	if (w > 0 && k > 0 && w<9 && k<9)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w - 1][k] == 0 &&
			control_tab[w - 1][k + 1] == 0 &&
			control_tab[w][k + 1] == 0 && //x=k;y=w
			control_tab[w + 1][k + 1] == 0 &&
			control_tab[w + 1][k] == 0 &&
			control_tab[w + 1][k - 1] == 0 &&
			control_tab[w][k - 1] == 0 &&
			control_tab[w - 1][k - 1] == 0) return 0;
		else return -1;

	}
	if (w == 0 && k == 0)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w][k + 1] == 0 &&
			control_tab[w + 1][k] == 0 &&
			control_tab[w + 1][k + 1] == 0) return 1;
		else return -1;
	}
	if (w == 0 && k != 0 && k!=9)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w][k - 1] == 0 &&
			control_tab[w][k + 1] == 0 &&
			control_tab[w + 1][k] == 0 &&
			control_tab[w + 1][k - 1] == 0 &&
			control_tab[w + 1][k + 1] == 0) return 2;
		else return -1;
	}
	if (k == 0 && w != 0 && w!=9) //
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w - 1][k] == 0 &&
			control_tab[w + 1][k] == 0 &&
			control_tab[w + 1][k + 1] == 0 &&
			control_tab[w][k + 1] == 0 &&
			control_tab[w - 1][k + 1] == 0) return 3;
		else return -1;
	}
	if (w == 9 && k == 9)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w][k - 1] == 0 &&
			control_tab[w - 1][k - 1] == 0 &&
			control_tab[w - 1][k] == 0) return 4;
		else return -1;
	}
	if (w == 9 && k != 9 && k != 0)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w][k - 1] == 0 &&
			control_tab[w - 1][k - 1] == 0 &&
			control_tab[w - 1][k] == 0 &&
			control_tab[w - 1][k + 1] == 0 &&
			control_tab[w][k + 1] == 0) return 5;
		else return -1;
	}
	if (k == 9 && w != 9 && w != 0)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w + 1][k] == 0 &&
			control_tab[w + 1][k - 1] == 0 &&
			control_tab[w][k - 1] == 0 &&
			control_tab[w - 1][k - 1] == 0 &&
			control_tab[w - 1][k] == 0) return 6;
		else return -1;

	}
	if (w == 9 && k == 0)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w - 1][k] == 0 &&
			control_tab[w - 1][k + 1] == 0 &&
			control_tab[w][k + 1] == 0) return 7;
		else return -1;
	}
	if (k == 9 && w == 0)
	{
		if (control_tab[w][k] == 0 &&
			control_tab[w][k - 1] == 0 &&
			control_tab[w + 1][k - 1] == 0 &&
			control_tab[w + 1][k] == 0) return 8;
		else return -1;
	}
	if (w > 9 || k > 9 || w < 0 || k < 0)
	{
		printf("Error: in func %s\n",__func__); //error handling
		return -2;
	}
	return -1;
}