/*
Autor: Antoni Wiœniewski
Nr indeksu: 333516
Gra w Statki

utworzy³em ten rozdzia³ na dwa pliki aby oddzieliæ funkcje gry od logiki gry*/

#include "warships.h"
#include "winbgi2.h"
void displayBoard()
{
	//obramowanie
	/*line(5, 5, 990, 5);
	line(5, 5, 5, 780);
	line(990, 5, 990, 780);
	line(5, 780, 990, 780);*/
	//powy¿sze instrukcje zast¹pi³em rectangle'm
	rectangle(5, 5, x_end, y_end);
	//podzia³ka na graczy
	line(screenOffset_width / 2.0, 5, screenOffset_width / 2.0, y_end);
	//podzia³ka pola jednego gracza 1:2
	line(5, 2 * screenOffset_height / 3.0, x_end, 2 * screenOffset_height / 3.0);
	//plansza gracza i komputera
		//gracz


	// WIPIPIPIPIPIPIPIPIPIPIP
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
		line((i / 10.0) * left_plane_lenght + left_plane_leftOffset+left_screenOffset,upper_screenOffset+left_plane_upperOffset , (i / 10.0) * left_plane_lenght + left_plane_leftOffset + left_screenOffset, (2 * screenOffset_height / 3.0) - left_plane_lowerOffset);
		line(left_screenOffset+left_plane_leftOffset, (i / 10.0) * left_plane_height + left_plane_upperOffset+upper_screenOffset, (screenOffset_width / 2.0) - left_plane_rightOffset, (i / 10.0) * left_plane_height + left_plane_rightOffset+ upper_screenOffset);
	}

}