/*
Autor: Antoni Wiœniewski
Nr indeksu : 333516
Gra w Statki

utworzy³em ten rozdzia³ na dwa pliki aby oddzieliæ funkcje gry które s¹ spore
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
//---------------------------------------------------
//---------------funkcje dla gry---------------------
void displayBoard();//wyœwietlanie pustych plansz
void displayInstrucions();
int welcomeScreen();//wyœwietlanie ekranu powitalnego i obs³uga jego przycisków
int cords_to_matrix(int x, int y, int* w, int* k, int tab[10][10], int mode); // mode = 0, lewa plansza, czyli gracz; mode = 1, prawa plansza, czyli, komputer
void matrix_to_cords(double* x, double* y, int m_x, int m_y,int mode); // mode = 0, lewa plansza, czyli gracz; mode = 1, prawa plansza, czyli, komputer
void drawShips(int control_tab[10][10], int enemy_control_tab[10][10], int mode); // player_type = 0, analogicznie jak wyzej; rysuje istniej¹ce statki
void random_CPU_ships(int control_tab[10][10]);//losowanie statków komputera
void place_PLAYER_ships(int player_control_tab[10][10], int enemy_control_tab[10][10]);//gracz uk³ada sobie statki
int check_surroundings(int w, int k, int control_tab[10][10]);//funkcja do sprawdzania otoczenia podczs losowania pozycji statku
void CPU_shoot(int* w, int* k, int control_tab[10][10], int last_CPU_hit[2], bool* did_CPU_hit);//funkcja losowania punktu strza³u dla komputera i logika jego "inteligentnych trafieñ"
int PLAYER_shoot(int* w, int* k, int control_tab[10][10]);//funkcja strza³u dla gracza
int PLAY(int player_control_tab[10][10], int enemy_control_tab[10][10], int player_ships[4], int enemy_ships[4], int last_CPU_hit[2], bool* did_CPU_hit); //funkcja gry
void drawScore(int player_ships[4], int enemy_ships[4]);//funkcja wypisuje ilosc statków graca i przeciwnika
//---------------------------------------------------



#endif /* zabezpieczenie aby nie "wkleiæ" pliku .h dwukrotnie*/
