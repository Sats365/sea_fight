#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

#ifndef MODULE_GraphLip_H
#define MODULE_GraphLip_H

string St_In(int cis);
void OutLin(RenderWindow& window, int x, int y, int p, int razmer);
void OutTextXY(RenderWindow& window, int x, int y, string st);
void OutText1XY(RenderWindow& window, int x, int y, string st, int razmer);
void OutText2XY(RenderWindow& window, int x, int y, string st, int razmer);
void ClearBar(RenderWindow& window, int Left, int Top, int Right, int Bottom);
void OutKor4(RenderWindow& window, int x, int y, int a, int b);
void OutKor3(RenderWindow& window, int x, int y, int a, int b);
void OutKor2(RenderWindow& window, int x, int y, int a, int b);
void OutKor1(RenderWindow& window, int x, int y);
void VivEror(RenderWindow& window);


#endif
