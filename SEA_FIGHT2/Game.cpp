#include <SFML/Graphics.hpp>
#include "InOut.h"
#include "GraphLib.h"

extern enum TPl { Pl1, Pl2, Start };
extern enum TPl Pl;
extern int SaveArrPl1[15][15];
extern int SaveArrPl2[15][15];
bool buuul = false;
int n, j;
extern int BombArr[15][15]; 
extern int BombArr2[15][15];

void SaveArr(int Ship, int x, int y, int a, int b, int razmer) {
	x = (x - 14) / 30;
	y = (y + 6) / 30;
	a = (a + 5) / 30;
	b = (b + 5) / 30;
	SaveArrPl1[y-1][x-1] = 1;

	if (a > b) {
		if (Ship != 1) { SaveArrPl1[y - 1][x + a - 2] = 1; }
		switch (Ship) {
			case 3:
				SaveArrPl1[y - 1][x + a - 3] = 1;
			break;
			case 4: 
				SaveArrPl1[y - 1][x + a - 3] = 1;
				SaveArrPl1[y - 1][x + a - 4] = 1;
			break;
		}
		
	}
	if (a < b) {
		if (Ship != 1) { SaveArrPl1[y + b - 2][x - 1] = 1; }
		switch (Ship) {
		case 3:
			SaveArrPl1[y + b - 3][x - 1] = 1;
			break;
		case 4:
			SaveArrPl1[y + b - 3][x - 1] = 1;
			SaveArrPl1[y + b - 4][x - 1] = 1;
			break;
		}
	}

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if (SaveArrPl1[n][j] == 1) {
				if (((n - 1) >= 0) & (j >= 0) & ((n - 1) < 12) & (j < 12)) { if (SaveArrPl1[n - 1][j] != 1) { SaveArrPl1[n - 1][j] = 2; } }
				if ((n >= 0) & ((j - 1) >= 0) & (n < 12) & ((j - 1) < 12)) { if (SaveArrPl1[n][j - 1] != 1) { SaveArrPl1[n][j - 1] = 2; } }
				if (((n + 1) >= 0) & (j >= 0) & ((n + 1) < 12) & (j < 12)) { if (SaveArrPl1[n + 1][j] != 1) { SaveArrPl1[n + 1][j] = 2; } }
				if ((n >= 0) & ((j + 1) >= 0) & (n < 12) & ((j + 1) < 12)) { if (SaveArrPl1[n][j + 1] != 1) { SaveArrPl1[n][j + 1] = 2; } }
				if (((n + 1) >= 0) & ((j + 1) >= 0) & ((n + 1) < 12) & ((j + 1) < 12)) { if (SaveArrPl1[n + 1][j + 1] != 1) { SaveArrPl1[n + 1][j + 1] = 2; } }
				if (((n - 1) >= 0) & ((j - 1) >= 0) & ((n - 1) < 12) & ((j - 1) < 12)) { if (SaveArrPl1[n - 1][j - 1] != 1) { SaveArrPl1[n - 1][j - 1] = 2; } }
				if (((n + 1) >= 0) & ((j - 1) >= 0) & ((n + 1) < 12) & ((j - 1) < 12)) { if (SaveArrPl1[n + 1][j - 1] != 1) { SaveArrPl1[n + 1][j - 1] = 2; } }
				if (((n - 1) >= 0) & ((j + 1) >= 0) & ((n - 1) < 12) & ((j + 1) < 12)) { if (SaveArrPl1[n - 1][j + 1] != 1) { SaveArrPl1[n - 1][j + 1] = 2; } }
			}
		}
	}
}
void SaveArr2(int Ship, int x, int y, int a, int b, int razmer) {
	x = (x - 534) / 30;
	y = (y + 6) / 30;
	a = (a + 5) / 30;
	b = (b + 5) / 30;
	SaveArrPl2[y - 1][x - 1] = 1;

	if (a > b) {
		if (Ship != 1) { SaveArrPl2[y - 1][x + a - 2] = 1; }
		switch (Ship) {
		case 3:
			SaveArrPl2[y - 1][x + a - 3] = 1;
			break;
		case 4:
			SaveArrPl2[y - 1][x + a - 3] = 1;
			SaveArrPl2[y - 1][x + a - 4] = 1;
			break;
		}

	}
	if (a < b) {
		if (Ship != 1) { SaveArrPl2[y + b - 2][x - 1] = 1; }
		switch (Ship) {
		case 3:
			SaveArrPl2[y + b - 3][x - 1] = 1;
			break;
		case 4:
			SaveArrPl2[y + b - 3][x - 1] = 1;
			SaveArrPl2[y + b - 4][x - 1] = 1;
			break;
		}
	}

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if (SaveArrPl2[n][j] == 1) {
				if (((n - 1) >= 0) & (j >= 0) & ((n - 1) < 12) & (j < 12)) { if (SaveArrPl2[n - 1][j] != 1) { SaveArrPl2[n - 1][j] = 2; } }
				if ((n >= 0) & ((j - 1) >= 0) & (n < 12) & ((j - 1) < 12)) { if (SaveArrPl2[n][j - 1] != 1) { SaveArrPl2[n][j - 1] = 2; } }
				if (((n + 1) >= 0) & (j >= 0) & ((n + 1) < 12) & (j < 12)) { if (SaveArrPl2[n + 1][j] != 1) { SaveArrPl2[n + 1][j] = 2; } }
				if ((n >= 0) & ((j + 1) >= 0) & (n < 12) & ((j + 1) < 12)) { if (SaveArrPl2[n][j + 1] != 1) { SaveArrPl2[n][j + 1] = 2; } }
				if (((n + 1) >= 0) & ((j + 1) >= 0) & ((n + 1) < 12) & ((j + 1) < 12)) { if (SaveArrPl2[n + 1][j + 1] != 1) { SaveArrPl2[n + 1][j + 1] = 2; } }
				if (((n - 1) >= 0) & ((j - 1) >= 0) & ((n - 1) < 12) & ((j - 1) < 12)) { if (SaveArrPl2[n - 1][j - 1] != 1) { SaveArrPl2[n - 1][j - 1] = 2; } }
				if (((n + 1) >= 0) & ((j - 1) >= 0) & ((n + 1) < 12) & ((j - 1) < 12)) { if (SaveArrPl2[n + 1][j - 1] != 1) { SaveArrPl2[n + 1][j - 1] = 2; } }
				if (((n - 1) >= 0) & ((j + 1) >= 0) & ((n - 1) < 12) & ((j + 1) < 12)) { if (SaveArrPl2[n - 1][j + 1] != 1) { SaveArrPl2[n - 1][j + 1] = 2; } }
			}
		}
	}
}

bool ReconShip(int Ship, int x, int y, int a, int b, int razmer) {

	bool Rec = false;
	int Arr[15][15];

	x = (x - 14) / 30;
	y = (y + 6) / 30;
	a = (a + 5) / 30;
	b = (b + 5) / 30;
	Arr[y - 1][x - 1] = 1;

	if (a > b) {
		if (Ship != 1) { Arr[y - 1][x + a - 2] = 1; }
		switch (Ship) {
		case 3:
			Arr[y - 1][x + a - 3] = 1;
			break;
		case 4:
			Arr[y - 1][x + a - 3] = 1;
			Arr[y - 1][x + a - 4] = 1;
			break;
		}

	}
	if (a < b) {
		if (Ship != 1) { Arr[y + b - 2][x - 1] = 1; }
		switch (Ship) {
		case 3:
			Arr[y + b - 3][x - 1] = 1;
			break;
		case 4:
			Arr[y + b - 3][x - 1] = 1;
			Arr[y + b - 4][x - 1] = 1;
			break;
		}
	}

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if ((Arr[n][j] == 1) & (SaveArrPl1[n][j] == 1)) {
				Rec = true;
			}
			if ((Arr[n][j] == 1) & (SaveArrPl1[n][j] == 2)) {
				Rec = true;
			}
		}
	}

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) { 
			Arr[n][j] = 0; 
		}
	}

	return(Rec);
};
bool ReconShip2 (int Ship, int x, int y, int a, int b, int razmer) {

	bool Rec = false;
	int Arr[15][15];

	x = (x - 534) / 30;
	y = (y + 6) / 30;
	a = (a + 5) / 30;
	b = (b + 5) / 30;
	Arr[y - 1][x - 1] = 1;

	if (a > b) {
		if (Ship != 1) { Arr[y - 1][x + a - 2] = 1; }
		switch (Ship) {
		case 3:
			Arr[y - 1][x + a - 3] = 1;
			break;
		case 4:
			Arr[y - 1][x + a - 3] = 1;
			Arr[y - 1][x + a - 4] = 1;
			break;
		}

	}
	if (a < b) {
		if (Ship != 1) { Arr[y + b - 2][x - 1] = 1; }
		switch (Ship) {
		case 3:
			Arr[y + b - 3][x - 1] = 1;
			break;
		case 4:
			Arr[y + b - 3][x - 1] = 1;
			Arr[y + b - 4][x - 1] = 1;
			break;
		}
	}

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if ((Arr[n][j] == 1) & (SaveArrPl2[n][j] == 1)) {
				Rec = true;
			}
			if ((Arr[n][j] == 1) & (SaveArrPl2[n][j] == 2)) {
				Rec = true;
			}
		}
	}

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			Arr[n][j] = 0;
		}
	}


	return(Rec);
};

void VivBomb(RenderWindow& window, int x, int y) {
	RectangleShape Bomb(Vector2f(25, 25));
	Bomb.setFillColor(Color::Red);
	Bomb.setPosition(x, y);
	window.draw(Bomb);

	/*sf::Vertex lol[4] =
	{
		sf::Vertex(sf::Vector2f(10,10), sf::Color::Red , sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red , sf::Vector2f(0, 0)),
		sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red , sf::Vector2f(0, 0)),
		sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red , sf::Vector2f(0, 0))
	};
	window.draw(lol, 4, Quads); */
}

void SaveBomb(int x, int y) {
	x = (x - 14) / 30;
	y = (y + 6) / 30;
	BombArr[y - 1][x - 1] = 1;
}
void SaveBomb2(int x, int y) {
	x = (x - 534) / 30;
	y = (y + 6) / 30;
	BombArr2[y - 1][x - 1] = 1;
}

bool ReconBomb(int razmer) {

	bool Rec = false;

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if ((BombArr[n][j] == 1) & (SaveArrPl1[n][j] == 1)) {
				Rec = true;
			}
		}
	}


	return(Rec);
}
bool ReconBomb2(int razmer) {

	bool Rec = false;

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if ((BombArr2[n][j] == 1) & (SaveArrPl2[n][j] == 1)) {
				Rec = true;
			}
		}
	}


	return(Rec);
}

bool PrKill(int razmer) {
	bool b[8] = {false, false, false, false, false, false, false}, by = false;

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if (SaveArrPl1[n][j] == 3) {
				SaveArrPl1[n][j] = 4;
				if (((n - 1) >= 0) & (j >= 0) & ((n - 1) < razmer) & (j < razmer)) { if (SaveArrPl1[n - 1][j] != 1) { b[0] = true; } }
				else { b[0] = true; }
				if ((n >= 0) & ((j - 1) >= 0) & (n < razmer) & ((j - 1) < razmer)) { if (SaveArrPl1[n][j - 1] != 1) { b[1] = true; } }
				else { b[1] = true; }
				if (((n + 1) >= 0) & (j >= 0) & ((n + 1) < razmer) & (j < razmer)) { if (SaveArrPl1[n + 1][j] != 1) { b[2] = true; } }
				else { b[2] = true; }
				if ((n >= 0) & ((j + 1) >= 0) & (n < razmer) & ((j + 1) < razmer)) { if (SaveArrPl1[n][j + 1] != 1) { b[3] = true; } }
				else { b[3] = true; }
				if (((n + 1) >= 0) & ((j + 1) >= 0) & ((n + 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl1[n + 1][j + 1] != 1) { b[4] = true; } }
				else { b[4] = true; }
				if (((n - 1) >= 0) & ((j - 1) >= 0) & ((n - 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl1[n - 1][j - 1] != 1) { b[5] = true; } }
				else { b[5] = true; }
				if (((n + 1) >= 0) & ((j - 1) >= 0) & ((n + 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl1[n + 1][j - 1] != 1) { b[6] = true; } }
				else { b[6] = true; }
				if (((n - 1) >= 0) & ((j + 1) >= 0) & ((n - 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl1[n - 1][j + 1] != 1) { b[7] = true; } }
				else { b[7] = true; }
			}
		}
	}

	if (b[0] == true and b[1] == true and b[2] == true and b[3] == true) {
		by = true;
	}

	if (by == true) {
		for (n = 0; n < razmer; n++) {
			for (j = 0; j < razmer; j++) {
				if (SaveArrPl1[n][j] == 4) {
					if (((n - 1) >= 0) & (j >= 0) & ((n - 1) < razmer) & (j < razmer)) { if (SaveArrPl1[n - 1][j] != 4) { SaveArrPl1[n - 1][j] = 5; } }
					if ((n >= 0) & ((j - 1) >= 0) & (n < razmer) & ((j - 1) < razmer)) { if (SaveArrPl1[n][j - 1] != 4) { SaveArrPl1[n][j - 1] = 5; } }
					if (((n + 1) >= 0) & (j >= 0) & ((n + 1) < razmer) & (j < razmer)) { if (SaveArrPl1[n + 1][j] != 4) { SaveArrPl1[n + 1][j] = 5; } }
					if ((n >= 0) & ((j + 1) >= 0) & (n < razmer) & ((j + 1) < razmer)) { if (SaveArrPl1[n][j + 1] != 4) { SaveArrPl1[n][j + 1] = 5; } }
					if (((n + 1) >= 0) & ((j + 1) >= 0) & ((n + 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl1[n + 1][j + 1] != 4) { SaveArrPl1[n + 1][j + 1] = 5; } }
					if (((n - 1) >= 0) & ((j - 1) >= 0) & ((n - 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl1[n - 1][j - 1] != 4) { SaveArrPl1[n - 1][j - 1] = 5; } }
					if (((n + 1) >= 0) & ((j - 1) >= 0) & ((n + 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl1[n + 1][j - 1] != 4) { SaveArrPl1[n + 1][j - 1] = 5; } }
					if (((n - 1) >= 0) & ((j + 1) >= 0) & ((n - 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl1[n - 1][j + 1] != 4) { SaveArrPl1[n - 1][j + 1] = 5; } }
				}
			}
		}
	}

	return by;
}
bool PrKill2(int razmer) {
	bool b[8] = { false, false, false, false, false, false, false }, by = false;

	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if (SaveArrPl2[n][j] == 3) {
				SaveArrPl2[n][j] = 4;
				if (((n - 1) >= 0) & (j >= 0) & ((n - 1) < razmer) & (j < razmer)) { if (SaveArrPl2[n - 1][j] != 1) { b[0] = true; } }
				else { b[0] = true; }
				if ((n >= 0) & ((j - 1) >= 0) & (n < razmer) & ((j - 1) < razmer)) { if (SaveArrPl2[n][j - 1] != 1) { b[1] = true; } }
				else { b[1] = true; }
				if (((n + 1) >= 0) & (j >= 0) & ((n + 1) < razmer) & (j < razmer)) { if (SaveArrPl2[n + 1][j] != 1) { b[2] = true; } }
				else { b[2] = true; }
				if ((n >= 0) & ((j + 1) >= 0) & (n < razmer) & ((j + 1) < razmer)) { if (SaveArrPl2[n][j + 1] != 1) { b[3] = true; } }
				else { b[3] = true; }
				if (((n + 1) >= 0) & ((j + 1) >= 0) & ((n + 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl2[n + 1][j + 1] != 1) { b[4] = true; } }
				else { b[4] = true; }
				if (((n - 1) >= 0) & ((j - 1) >= 0) & ((n - 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl2[n - 1][j - 1] != 1) { b[5] = true; } }
				else { b[5] = true; }
				if (((n + 1) >= 0) & ((j - 1) >= 0) & ((n + 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl2[n + 1][j - 1] != 1) { b[6] = true; } }
				else { b[6] = true; }
				if (((n - 1) >= 0) & ((j + 1) >= 0) & ((n - 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl2[n - 1][j + 1] != 1) { b[7] = true; } }
				else { b[7] = true; }
			}
		}
	}

	if (b[0] == true and b[1] == true and b[2] == true and b[3] == true) {
		by = true;
	}

	if (by == true) {
		for (n = 0; n < razmer; n++) {
			for (j = 0; j < razmer; j++) {
				if (SaveArrPl2[n][j] == 4) {
					if (((n - 1) >= 0) & (j >= 0) & ((n - 1) < razmer) & (j < razmer)) { if (SaveArrPl2[n - 1][j] != 4) { SaveArrPl2[n - 1][j] = 5; } }
					if ((n >= 0) & ((j - 1) >= 0) & (n < razmer) & ((j - 1) < razmer)) { if (SaveArrPl2[n][j - 1] != 4) { SaveArrPl2[n][j - 1] = 5; } }
					if (((n + 1) >= 0) & (j >= 0) & ((n + 1) < razmer) & (j < razmer)) { if (SaveArrPl2[n + 1][j] != 4) { SaveArrPl2[n + 1][j] = 5; } }
					if ((n >= 0) & ((j + 1) >= 0) & (n < razmer) & ((j + 1) < razmer)) { if (SaveArrPl2[n][j + 1] != 4) { SaveArrPl2[n][j + 1] = 5; } }
					if (((n + 1) >= 0) & ((j + 1) >= 0) & ((n + 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl2[n + 1][j + 1] != 4) { SaveArrPl2[n + 1][j + 1] = 5; } }
					if (((n - 1) >= 0) & ((j - 1) >= 0) & ((n - 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl2[n - 1][j - 1] != 4) { SaveArrPl2[n - 1][j - 1] = 5; } }
					if (((n + 1) >= 0) & ((j - 1) >= 0) & ((n + 1) < razmer) & ((j - 1) < razmer)) { if (SaveArrPl2[n + 1][j - 1] != 4) { SaveArrPl2[n + 1][j - 1] = 5; } }
					if (((n - 1) >= 0) & ((j + 1) >= 0) & ((n - 1) < razmer) & ((j + 1) < razmer)) { if (SaveArrPl2[n - 1][j + 1] != 4) { SaveArrPl2[n - 1][j + 1] = 5; } }
				}
			}
		}
	}

	return by;
}

bool WinP1(int razmer) {
	bool b = true;
	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if (SaveArrPl1[n][j] == 1) {
				b = false;
			}
		}
	}
	return b;
}
bool WinP2(int razmer) {
	bool b = true;
	for (n = 0; n < razmer; n++) {
		for (j = 0; j < razmer; j++) {
			if (SaveArrPl2[n][j] == 1) {
				b = false;
			}
		}
	}
	return b;
}