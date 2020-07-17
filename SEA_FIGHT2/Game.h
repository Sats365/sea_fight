#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#ifndef MODULE_Game_H
#define MODULE_Game_H

void SaveArr(int Ship, int x, int y, int a, int b, int razmer);
void SaveArr2(int Ship, int x, int y, int a, int b, int razmer);
bool ReconShip(int Ship, int x, int y, int a, int b, int razmer);
bool ReconShip2(int Ship, int x, int y, int a, int b, int razmer);
void VivBomb(RenderWindow& window, int x, int y);
void SaveBomb(int x, int y);
void SaveBomb2(int x, int y);
bool ReconBomb(int razmer);
bool ReconBomb2(int razmer);
bool PrKill(int razmer);
bool PrKill2(int razmer);
bool WinP1(int razmer);
bool WinP2(int razmer);

#endif