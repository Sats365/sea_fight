#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#ifndef MODULE_InOut_H
#define MODULE_InOut_H

void OutStructure(RenderWindow& window, int razmer);
void Viv(RenderWindow& window, int x, int y, int Ship, int a, int b);
void OutKor(RenderWindow&window);
void SaveKor(RenderWindow& window, int x, int y, int Ship, int a, int b);

#endif
