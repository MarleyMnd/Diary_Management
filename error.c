//
// Created by Marley on 26/10/2023.
//

#include "error.h"
#include <windows.h>

/*
 * 0 : Black
 * 1 : Dark blue
 * 2 : Dark green
 * 3 : Turquoise
 * 4 : Dark red
 * 5 : Violet
 * 6 : Yucky yellow
 * 7 : Light grey
 * 8 : Dark grey
 * 9 : Neon blue
 * 10 : Neon green
 * 11 : Turquoise
 * 12 : Neon red
 * 13 : Violet n°2
 * 14 : Yellow
 * 15 : White
*/

void Color(int TextColor,int BGColor)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,BGColor*16+TextColor);
}