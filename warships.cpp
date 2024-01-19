/*
Autor: Antoni Wiœniewski
Nr indeksu: 333516
Gra w Statki

utworzylem ten rozdzial na dwa pliki aby oddzielic funkcje gry od logiki gry*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "warships.h"
#include "winbgi2.h"
//czysci ekran i wyswietla plansze
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
// Funkcja obslugjaca ekran powitalny
// 0 jesli urzytkownik kliknal QUIT 1 jesli kliknal PLAY
int welcomeScreen()
{
	int option = 0;
	const char* welcome_msg = "WARSHIPS v1.0";
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
// Funkcja z instrukcjami jak grac
void displayInstrucions()
{
	clear();
	bool status = true;
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(980/2.,40,"Witaj w grze w statki\n");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(1000 / 2., 70, "Bedziesz rozgrywal rundy na zmiane z przeciwnikiem sterowanym przez komputer");
	outtextxy(1000 / 2., 100, "Musisz ustawic swoje statki.Zaczniesz od statkow jednomasztowych i");
	outtextxy(1000 / 2., 130,"potem przejdziemy do wiekszych.");
	outtextxy(1000 / 2., 160, "PAMIETAJ STATKI NIE MOGA STYKAC SIE ROGAMI ANI BOKAMI\n");
	outtextxy(1000 / 2., 190,"Wieksze statki stawiaj klikajac w kratke poczatkowa i po kolei w nastêpne NIE ROB SKOSOW");
	outtextxy(1000 / 2., 210, "Gdy bedziesz gotowy gra rozpocznie twoja runde strzalu.");
	outtextxy(1000 / 2., 240,"Kliknij na prawej szachownicy tam gdzie chcesz poslac pocisk.");
	outtextxy(1000 / 2., 270, "Czerwony oznacza trafienie, bialy pudlo");
	outtextxy(1000 / 2., 300,"Na dole bedzie wypisana liczba statkow przeciwnika oraz twoich");
	outtextxy(1000 / 2., 330,"Powodzenia");
	outtextxy(1000 / 2., 360,"Nacisnij sx2 aby zamknac ten ekran, a zeby wyjsc z gry nacisnij q");
	while (status)
	{
		if (kbhit() != 0)
		{
			if (getch() == 'S') status = false;
			if (getch() == 'Q') exit(0);
		}
	}
}
// Funkcja do tlumaczenia wspolrzednych na ekranie, na indeksy tablicy 2d
// Zwraca wartosc ktora znalazl w tablicy jesli mode !=1 lub 200 jesli nie znalazl oraz indeksy tablicy odpowiadajace planszy komputera poprzez wskaznik
// jesli mode = 1 to zwraca tylko indeksy odpowiadajace planszy gracza
// zwrocenie 200 oznacza nie znalezienie odpowiednich wspolrzednych
int cords_to_matrix(int x, int y,int* w,int* k, int tab[10][10], int mode)
{
	if (mode == 1)
	{
		double x_origin = left_screenOffset + left_plane_leftOffset;
		double y_origin = upper_screenOffset + left_plane_leftOffset;
		bool y_found = false;
		bool x_found = false;
		for (int i = 0; i < 10; i++)
		{
			if (x > x_origin + ((i / 10.) * left_plane_lenght) && x<x_origin + (i / 10.) * left_plane_lenght + left_plane_lenght / 10.)
			{
				*k = i;
				x_found = true;
			}
			if (y>y_origin + ((i / 10.) * left_plane_height) && y<y_origin + (i / 10.) * left_plane_height + left_plane_height/10.)
			{
				*w = i;
				y_found = true;
			}
			if (x_found && y_found) break;
		}
		if (x_found && y_found)
		{
			return 0;
		}
		else return 200;
	}
	else
	{
		double x_origin = (screenOffset_width / 2.0) + right_plane_leftOffset;
		double y_origin = right_plane_upperOffset + upper_screenOffset;
		bool y_found = false;
		bool x_found = false;
		for (int i = 0; i < 10; i++)
		{
			if (x > x_origin + ((i / 10.) * right_plane_lenght) && x < x_origin + (i / 10.) * right_plane_lenght + right_plane_lenght / 10.)
			{
				*k = i;
				x_found = true;
			}
			if (y > y_origin + ((i / 10.) * right_plane_height) && y < y_origin + (i / 10.) * right_plane_height + right_plane_height / 10.)
			{
				*w = i;
				y_found = true;
			}
			if (x_found && y_found) break;
		}
		if (x_found && y_found) return tab[*w][*k];
		else return 200;
		
	}
}
//funkcja do tlumaczenia indeksow tablicy 2d na wspolrzedne
//mode=1 wspolrzedne na planszy gracza;mode = 0 wspolrzendne na planszy komputera
void matrix_to_cords(double* x, double* y, int m_w, int m_k, int mode)
{
	if (mode == 1)
	{
		*y = upper_screenOffset + left_plane_upperOffset + (left_plane_height / 10.) * m_w + 1;
		*x = left_screenOffset + left_plane_leftOffset + (left_plane_lenght / 10.) * m_k + 1;
	}
	else
	{
		*y = right_plane_upperOffset + upper_screenOffset + (right_plane_height / 10.) * m_w + 1;
		*x = (screenOffset_width / 2.0) + right_plane_leftOffset + (right_plane_height / 10.) * m_k + 1;
	}
}
void drawShips(int control_tab[10][10],int enemy_control_tab[10][10], int mode)
{
	double x = 0;
	double y = 0;
	if (mode == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				setfillstyle(INTERLEAVE_FILL, GREEN);
				if (control_tab[i][j] > 0)
				{
					matrix_to_cords(&x, &y, i, j, 1);
					floodfill(x, y, WHITE);
				}
				if (control_tab[i][j] == -1)
				{
					setfillstyle(INTERLEAVE_FILL, RED);
					matrix_to_cords(&x, &y, i, j, 1);
					floodfill(x, y, WHITE);
				}
				if (control_tab[i][j] == -2)
				{
					setfillstyle(BKSLASH_FILL, WHITE);
					matrix_to_cords(&x, &y, i, j, 1);
					floodfill(x, y, WHITE);
				}

			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (enemy_control_tab[i][j] == -1)
				{
					setfillstyle(INTERLEAVE_FILL, RED);
					matrix_to_cords(&x, &y, i, j, 2);
					floodfill(x, y, WHITE);
				}
				if (enemy_control_tab[i][j] == -2)
				{
					setfillstyle(BKSLASH_FILL, WHITE);
					matrix_to_cords(&x, &y, i, j, 2);
					floodfill(x, y, WHITE);
				}

			}
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (control_tab[i][j] <0)
				{
					setfillstyle(INTERLEAVE_FILL, RED);
					matrix_to_cords(&x, &y, i, j, 2);
					floodfill(x, y, WHITE);
				}
			}
		}
	}
		
}
// Funkcja generowania statkow przeciwnika
//control_tab toTablica pozycji przeciwnika w tym przypadku
void random_CPU_ships(int control_tab[10][10])
{
	int ship_type = 4;
	int ship_made[4] = { 4,3,2,1 };
	bool place_success = false, heading_success = false;
	int heading = 0; // 1 = góra; 2 = prawo; 3 = dó³ 4 = lewo
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		if (ship_made[ship_type - 1] <= 0)
		{
			ship_type--;
			//break;
		}
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true; break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k<8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w<8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k>1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 8 && check_surroundings(w + 2, k, control_tab) != -1) //dó³ dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 8 && check_surroundings(w, k + 2, control_tab) != -1) //prawo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 1 && check_surroundings(w, k - 2, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
							if (check_surroundings(w - 1, k, control_tab) != -1 && w > 2 && check_surroundings(w - 2, k, control_tab) != -1 && check_surroundings(w - 3, k, control_tab) != -1) //góra dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w - 1][k] = ship_type;
								control_tab[w - 2][k] = ship_type;
								control_tab[w - 3][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 3
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 3:
							if (check_surroundings(w + 1, k, control_tab) != -1 && w < 7 && check_surroundings(w + 2, k, control_tab) != -1 && check_surroundings(w + 3, k, control_tab) != -1) //dó³ dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w + 1][k] = ship_type;
								control_tab[w + 2][k] = ship_type;
								control_tab[w + 3][k] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 2:
							if (check_surroundings(w, k + 1, control_tab) != -1 && k < 7 && check_surroundings(w, k + 2, control_tab) != -1 && check_surroundings(w, k + 3, control_tab) != -1) //prawo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k + 1] = ship_type;
								control_tab[w][k + 2] = ship_type;
								control_tab[w][k + 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
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
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						case 4:
							if (check_surroundings(w, k - 1, control_tab) != -1 && k > 2 && check_surroundings(w, k - 2, control_tab) != -1 && check_surroundings(w, k - 3, control_tab) != -1) // lewo dla 4
							{
								control_tab[w][k] = ship_type;
								control_tab[w][k - 1] = ship_type;
								control_tab[w][k - 2] = ship_type;
								control_tab[w][k - 3] = ship_type;
								ship_made[ship_type - 1]--;
								place_success = true;
								heading_success = true;
							}
							else heading_success = true;break;
						}
					}
					break;
				}
				//break; //DEBUG ONLY
			}
			break;
		}
		
	}
}
//funkcja do ukladania statkow na planszy gracza
//przjmuje tablice kontrolna gracza oraz tablice komputera ale tylko bo wywolujemy funcje drawShips
void place_PLAYER_ships(int player_control_tab[10][10], int enemy_control_tab[10][10])
{
	int ships_to_place[4] = { 4,3,2,1 };
	bool all_ship_place = true;
	bool ship_0 = true;
	bool ship_1 = true;
	bool ship_2 = true;
	int ship_type = 1;
	double x = 0;
	double y = 0;
	int w = 0;
	int k = 0;
	int w_1 = 0;
	int k_1 = 0;
	int w_2 = 0;
	int k_2 = 0;
	int w_3 = 0;
	int k_3 = 0;
	while (all_ship_place)
	{
		ship_0 = true;
		ship_1 = true;
		if (mousedown())
		{
			x = mouseclickx();
			y = mouseclicky();
			cords_to_matrix(x, y, &w, &k, player_control_tab, 1);
			if (check_surroundings(w, k, player_control_tab) != -1)
			{
				setfillstyle(INTERLEAVE_FILL, GREEN);
				floodfill(x, y, WHITE);
				switch (ship_type)
				{
				case 1:
					ships_to_place[ship_type - 1]--;
					player_control_tab[w][k] = ship_type;
					drawShips(player_control_tab, enemy_control_tab, 1);
					if (ships_to_place[ship_type - 1] == 0)
					{
						ship_type++;
					}
					break;
				case 2:
					while (ship_0)
					{
						if (mousedown())
						{
							x = mouseclickx();
							y = mouseclicky();
							cords_to_matrix(x, y, &w_1, &k_1, player_control_tab, 1);
							if (check_surroundings(w_1, k_1, player_control_tab) != -1 && ((w == w_1 + 1 && k == k_1) || (w == w_1 - 1 && k == k_1) || (w == w_1 && k == k_1+1) || (w == w_1 && k == k_1-1)))
							{
								ships_to_place[ship_type - 1]--;
								player_control_tab[w][k] = ship_type;
								player_control_tab[w_1][k_1] = ship_type;
								drawShips(player_control_tab, enemy_control_tab,1);
								ship_0 = false;
								if (ships_to_place[ship_type - 1] == 0)
								{
									ship_type++;
								}
							}
							else
							{
								setfillstyle(SOLID_FILL, BLACK);
								matrix_to_cords(&x, &y, w, k, 1);
								floodfill(x, y, WHITE);
								ship_0 = false;
							}
						}
					}
					break;
				case 3:
					while (ship_0)
					{
						if (mousedown())
						{
							x = mouseclickx();
							y = mouseclicky();
							cords_to_matrix(x, y, &w_1, &k_1, player_control_tab, 1);
							if (check_surroundings(w_1, k_1, player_control_tab) != -1 && ((w == w_1 + 1 && k == k_1) || (w == w_1 - 1 && k == k_1) || (w == w_1 && k == k_1 + 1) || (w == w_1 && k == k_1 - 1)))
							{
								setfillstyle(INTERLEAVE_FILL, GREEN);
								floodfill(x, y, WHITE);
								while (ship_1)
								{
									if (mousedown())
									{
										x = mouseclickx();
										y = mouseclicky();
										cords_to_matrix(x, y, &w_2, &k_2, player_control_tab, 1);
										if (check_surroundings(w_2, k_2, player_control_tab) != -1 && ((w_1 == w_2 + 1 && k_1 == k_2) || (w_1 == w_2 - 1 && k_1 == k_2) || (w_1 == w_2 && k_1 == k_2 + 1) || (w_1 == w_2 && k_1 == k_2 - 1)))
										{
											ships_to_place[ship_type - 1]--;
											player_control_tab[w][k] = ship_type;
											player_control_tab[w_1][k_1] = ship_type;
											player_control_tab[w_2][k_2] = ship_type;
											ship_0 = false;
											ship_1 = false;
											drawShips(player_control_tab, enemy_control_tab,1);
											if (ships_to_place[ship_type - 1] == 0)
											{
												ship_type++;
											}
										}
										else
										{
											setfillstyle(SOLID_FILL, BLACK);
											matrix_to_cords(&x, &y, w_1, k_1, 1);
											floodfill(x, y, WHITE);
											matrix_to_cords(&x, &y, w, k, 1);
											floodfill(x, y, WHITE);
											ship_1 = false;
											ship_0 = false;
										}
									}
								}
							}
							else
							{
								setfillstyle(SOLID_FILL, BLACK);
								matrix_to_cords(&x, &y, w, k, 1);
								floodfill(x, y, WHITE);
								ship_0 = false;

							}
						}
					}
					break;
				case 4:
					while (ship_0)
					{
						if (mousedown())
						{
							x = mouseclickx();
							y = mouseclicky();
							cords_to_matrix(x, y, &w_1, &k_1, player_control_tab, 1);
							if (check_surroundings(w_1, k_1, player_control_tab) != -1 && ((w == w_1 + 1 && k == k_1) || (w == w_1 - 1 && k == k_1) || (w == w_1 && k == k_1 + 1) || (w == w_1 && k == k_1 - 1)))
							{
								setfillstyle(INTERLEAVE_FILL, GREEN);
								floodfill(x, y, WHITE);
								while (ship_1)
								{
									if (mousedown())
									{
										x = mouseclickx();
										y = mouseclicky();
										cords_to_matrix(x, y, &w_2, &k_2, player_control_tab, 1);
										if (check_surroundings(w_2, k_2, player_control_tab) != -1 && ((w_1 == w_2 + 1 && k_1 == k_2) || (w_1 == w_2 - 1 && k_1 == k_2) || (w_1 == w_2 && k_1 == k_2 + 1) || (w_1 == w_2 && k_1 == k_2 - 1)))
										{
											setfillstyle(INTERLEAVE_FILL, GREEN);
											floodfill(x, y, WHITE);
											while(ship_2)
											{
												if(mousedown())
												{
													x = mouseclickx();
													y = mouseclicky();
													cords_to_matrix(x, y, &w_3, &k_3, player_control_tab, 1);
													if (check_surroundings(w_3, k_3, player_control_tab) != -1 && ((w_2 == w_3 + 1 && k_2 == k_3) || (w_2 == w_3 - 1 && k_2 == k_3) || (w_2 == w_3 && k_2 == k_3 + 1) || (w_2 == w_3 && k_2 == k_3 - 1)))
													{
														setfillstyle(INTERLEAVE_FILL, GREEN);
														floodfill(x, y, WHITE);
														ships_to_place[ship_type - 1]--;
														player_control_tab[w][k] = ship_type;
														player_control_tab[w_1][k_1] = ship_type;
														player_control_tab[w_2][k_2] = ship_type;
														player_control_tab[w_3][k_3] = ship_type;
														ship_0 = false;
														ship_1 = false;
														ship_2 = false;
														all_ship_place = false;
														drawShips(player_control_tab, enemy_control_tab,1);
														if (ships_to_place[ship_type - 1] == 0)
														{
															ship_type++;
														}
													}
													else
													{
														setfillstyle(SOLID_FILL, BLACK);
														matrix_to_cords(&x, &y, w_2, k_2, 1);
														floodfill(x, y, WHITE);
														matrix_to_cords(&x, &y, w_1, k_1, 1);
														floodfill(x, y, WHITE);
														matrix_to_cords(&x, &y, w, k, 1);
														floodfill(x, y, WHITE);
														ship_2 = false;
														ship_1 = false;
														ship_0 = false;
													}
												}
											}
										}
										else
										{
											setfillstyle(SOLID_FILL, BLACK);
											matrix_to_cords(&x, &y, w_1, k_1, 1);
											floodfill(x, y, WHITE);
											matrix_to_cords(&x, &y, w, k, 1);
											floodfill(x, y, WHITE);
											ship_1 = false;
											ship_0 = false;
										}
									}
								}
							}
							else
							{
								setfillstyle(SOLID_FILL, BLACK);
								matrix_to_cords(&x, &y, w, k, 1);
								floodfill(x, y, WHITE);
								ship_0 = false;
							}
						}
					}
					break;
				}
			}
		}
	}
}
// Funkcja sprawdzajaca otoczenie punktu w tablicy control_tab
// Nie wyjdzie poza granice
// Zwraca:
// -1 nie znaleziono wszytkich mozliwych pustych kratek w punkcie (w,k)
// 0 jesli 9 kratek ze srodkowa w punkcie (w,k) jest puste
// 1 jesli 4 kratki w lewym gornym rogu planszy sa puste
// 2 jesli 6 kratek jest wolne w pierwszym wierszu ale kolumnie innej niz 0 i 9
// 3 jesli 6 kratek jest wolne w pierwszej kolumnie ale w wierszu innym niz 0 i 9
// 4 jesli 4 kratki w prawym dolnym rogu sa puste
// 5 jesli 6 kratek jest wolne w ostatnim wierszu ale kolumnie innej niz 0 i 9
// 6 jesli 6 kratek jest wolne w ostatniej kolumnie ale wierszu innym niz 0 i 9
// 7 jesli 4 kratki w lewym dolnym sa puste
// 8 jesli 4 kratki w prawym gornym rogu sa puste
// w = Numer wiersza do sprawdzenia
// k = Numer kolumny do sprawdzenia
// control_tab = Tablica pozycji
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
//zwraca poprzez wskaznik pole w ktore strzela komputer,przyjmuje jako argumenty czy komputer trafil
//  wczesniejszy strzal aby szukac w jego okolicy statku oraz wspolrzedne ostatniego trafienia
void CPU_shoot(int* w, int* k, int control_tab[10][10], int last_CPU_hit[2],bool* did_CPU_hit)
{
	bool heading_found = true;
	srand(time(NULL));
	if (*did_CPU_hit)
	{
		while(heading_found)
		{
			int heading = rand() % 4 + 1; // kalsycznie 1-góra; 2-prawo; 3-dó³; 4-lewo
			switch (heading)
			{
			case 1:
				*k = last_CPU_hit[0];
				*w = last_CPU_hit[1] - 1;
				if (*w >= 0) heading_found = false;
				break;
			case 2:
				*k = last_CPU_hit[0] + 1;
				*w = last_CPU_hit[1];
				if (*k <= 9) heading_found = false;
				break;
			case 3:
				*k = last_CPU_hit[0];
				*w = last_CPU_hit[1] + 1;
				if (*w <= 9) heading_found = false;
				break;
			case 4:
				*k = last_CPU_hit[0] - 1;
				*w = last_CPU_hit[1];
				if (*k >= 0) heading_found = false;
				break;
			}
		}
	}
	else
	{
		while(heading_found)
		{
			*w = rand() % 10;
			*k = rand() % 10;
			if (control_tab[*w][*k] >= 0) heading_found = false;
		}
	}
}
//zwraca 0 jeśli trafimy; -1 jesli nie
int PLAYER_shoot(int* w, int* k,int control_tab[10][10])
{
	bool shoot = true;
	while (shoot)
	{
		if (kbhit() != 0)
		{
			if (getch() == 'S') exit(0);
		}
		if (mousedown())
		{
			if (cords_to_matrix(mouseclickx(), mouseclicky(), w, k, control_tab, 0) > 0)
			{
				printf("HIT!!!\n");
				setfillstyle(INTERLEAVE_FILL, RED);
				floodfill(mouseclickx(), mouseclicky(), WHITE);
				return 0;
			}
			else
			{
				printf("MISS :(\n");
				setfillstyle(BKSLASH_FILL, WHITE);
				floodfill(mouseclickx(), mouseclicky(), WHITE);
				return -1;
			}
		}
	}
}
//funkcja przyjmuje tablice kontrolne obu graczy i tablice ilosci segnmentow danych statkow oraz wartosci ostaniego trafienia komputera oraz czy trafil
//zwraca 0 jesli wygra komputer;1 jesli wygra gracz;-1 jesli jest nie rozsztygniete
int PLAY(int player_control_tab[10][10], int enemy_control_tab[10][10], int player_ships[4], int enemy_ships[4], int last_CPU_hit[2], bool* did_CPU_hit)
{
	bool win = false;
	int w = 0;
	int k = 0;
	double x = 0;
	double y = 0;
	int player_win_cond = 4;
	int CPU_win_cond = 4;
	if (PLAYER_shoot(&w, &k, enemy_control_tab) == 0)
	{
		enemy_ships[enemy_control_tab[w][k]-1]--;
		enemy_control_tab[w][k] = -1;
	}
	else enemy_control_tab[w][k] = -2;
	CPU_shoot(&w, &k, player_control_tab,last_CPU_hit, did_CPU_hit);
	if (player_control_tab[w][k] > 0)
	{
		player_ships[player_control_tab[w][k] - 1]--;
		player_control_tab[w][k] = -1;
		*did_CPU_hit = true;
		last_CPU_hit[0] = k;
		last_CPU_hit[1] = w;
		matrix_to_cords(&x, &y, w, k, 1);
		setfillstyle(INTERLEAVE_FILL, RED);
		floodfill(x, y, WHITE);

	}
	else
	{
		player_control_tab[w][k] = -2;
		*did_CPU_hit = false;
		matrix_to_cords(&x, &y, w, k, 1);
		setfillstyle(BKSLASH_FILL, WHITE);
		floodfill(x,y, WHITE);
	}
	if (player_ships[0] == 0 && player_ships[1] ==0 && player_ships[2] ==0 && player_ships[3] == 0) return 0;
	if (enemy_ships[0] == 0 && enemy_ships[1] ==0 && enemy_ships[2] == 0 && enemy_ships[3] == 0) return 1;
	return -1;
}
//przyjmuje tablice segmentow statkow gracza i komputera oraz wypisuje je na ekran
void drawScore(int player_ships[4], int enemy_ships[4])
{
	char ship_4[50] = "Lotniskowiec (4x[]) x ";
	char ship_3[50] = "Niszczyciel (3x[]) x ";
	char ship_2[50] = "Lodz patrolowa (2x[]) x ";
	char ship_1[50] = "Ponton bojowy (1x[]) x ";
	char buffer[50] = "";
	sprintf(buffer, "%d", player_ships[3]/4);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	outtextxy(15, 2 * screenOffset_height / 3.0 + 15, strncat(ship_4, buffer, 20));

	sprintf(buffer, "%s", "");
	sprintf(buffer, "%d", player_ships[2]/3);
	outtextxy(15, 2 * screenOffset_height / 3.0 + 30, strncat(ship_3, buffer, 20));

	sprintf(buffer, "%s", "");
	sprintf(buffer, "%d", player_ships[1]/2);
	outtextxy(15, 2 * screenOffset_height / 3.0 + 45, strncat(ship_2, buffer, 20));

	sprintf(buffer, "%s", "");
	sprintf(buffer, "%d", player_ships[0]);
	outtextxy(15, 2 * screenOffset_height / 3.0 + 60, strncat(ship_1, buffer, 20));

	char ship_4_1[50] = "Lotniskowiec (4x[]) x ";
	char ship_3_1[50] = "Niszczyciel (3x[]) x ";
	char ship_2_1[50] = "Lodz patrolowa (2x[]) x ";
	char ship_1_1[50] = "Ponton bojowy (1x[]) x ";
	char buffer_1[50] = "";
	sprintf(buffer_1, "%d", enemy_ships[3]/4);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	outtextxy((screenOffset_width / 2.0) + right_plane_leftOffset -5, 2 * screenOffset_height / 3.0 + 15, strncat(ship_4_1, buffer_1, 20));

	sprintf(buffer_1, "%s", "");
	sprintf(buffer_1, "%d", enemy_ships[2]/3);
	outtextxy((screenOffset_width / 2.0) + right_plane_leftOffset -5, 2 * screenOffset_height / 3.0 + 30, strncat(ship_3_1, buffer_1, 20));

	sprintf(buffer_1, "%s", "");
	sprintf(buffer_1, "%d", enemy_ships[1]/2);
	outtextxy((screenOffset_width / 2.0) + right_plane_leftOffset -5, 2 * screenOffset_height / 3.0 + 45, strncat(ship_2_1, buffer_1, 20));

	sprintf(buffer_1, "%s", "");
	sprintf(buffer_1, "%d", enemy_ships[0]);
	outtextxy((screenOffset_width / 2.0) + right_plane_leftOffset -5, 2 * screenOffset_height / 3.0 + 60, strncat(ship_1_1, buffer_1, 20));
}
