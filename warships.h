/*
Autor: Antoni Wiœniewski
Nr indeksu : 333516
Gra w Statki

utworzy³em ten rozdzia³ na dwa pliki aby oddzieliæ funkcje gry od logiki gry
*/

#ifndef WARSHIPS_H_
#define WARSHIPS_H_
//dodane aby zwiêkszyæ czytelnoœæ kodu rysowania palnszy oraz szybkie zmienianie offsetów
//-----------------------define----------------------
#define sheight 800
#define swidth 1000
#define right_screenOffset 10
#define left_screenOffset 5
#define upper_screenOffset 5
#define lower_screenOffset 20

#define x_end (swidth - right_screenOffset)
#define y_end (sheight - lower_screenOffset)
#define screenOffset_height (y_end - upper_screenOffset)
#define screenOffset_width (x_end - left_screenOffset)

#define left_plane_rightOffset 20
#define left_plane_leftOffset 20
#define left_plane_upperOffset 20
#define left_plane_lowerOffset 20

#define right_plane_rightOffset 15
#define right_plane_leftOffset 20
#define right_plane_upperOffset 20
#define right_plane_lowerOffset 20


#define left_plane_lenght ((screenOffset_width / 2.0) - left_plane_rightOffset - (left_screenOffset+left_plane_leftOffset))
#define left_plane_height ((2 * screenOffset_height / 3.0) - left_plane_lowerOffset - (left_plane_upperOffset+upper_screenOffset))
#define right_plane_lenght ((screenOffset_width - right_plane_rightOffset) - ((screenOffset_width / 2.0) + right_plane_leftOffset))
#define right_plane_height (((2 * screenOffset_height / 3.0) - right_plane_lowerOffset) - (right_plane_upperOffset+upper_screenOffset))
#define title_upperOffset 200
//-----------------include---------------------------
#include <stdbool.h>
//---------------------------------------------------
//---------------------------------------------------
//-----------------struktury------------------------- 

typedef struct
{
	int x_front; //liczone od zera do 9, gdzie y rosnie w dó³
	int x_back;
	int y_front;
	int y_back;
	bool alive;
}Ship;
//---------------------------------------------------
//---------------funkcje dla gry---------------------
void displayBoard();//wyœwietlanie pustych plansz
int welcomeScreen();//wyœwietlanie ekranu powitalnego i obs³uga jego przycisków
void cords_to_matrix(int x, int y, int** tab, int mode); // mode = 0, lewa plansza, czyli gracz; mode = 1, prawa plansza, czyli, komputer
void drawShips(Ship* ship_tab,int player_type); // player_type = 0, analogicznie jak wyzej; rysuje istniej¹ce statki
void random_CPU_ships(Ship* enemy_tab,int control_tab[10][10]);//losowanie statków komputera
int check_surroundings(int w, int k, int control_tab[10][10]);//funkcja do sprawdzania otoczenia podczs losowania pozycji statku
//---------------------------------------------------



#endif /* zabezpieczenie aby nie "wkleiæ" pliku .h dwukrotnie*/
