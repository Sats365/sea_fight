#include <SFML/Graphics.hpp>
#include "InOut.h"
#include "Game.h"
#include "GraphLib.h"
#include "Menu.h"
#include <windows.h>

using namespace std;
using namespace sf;

struct bomb {
	void SaveVivB(RenderWindow &window, int x, int y) {
		RectangleShape b(Vector2f(25,25));
		b.setFillColor(Color::Yellow);
		b.setPosition(x, y);
		window.draw(b);	
	}
	void SaveVivBy(RenderWindow &window, int x, int y) {
		RectangleShape b(Vector2f(25, 25));
		b.setFillColor(Color::Green);
		b.setPosition(x, y);
		window.draw(b);
	}
};

extern bool bmenu;

enum TPl { Nach, Pl1, Pl2, Start, Pl1S, Pl2S, Finish1, Finish2 };
enum TPl Pl = Nach;
char Ch;
bool bul = false, bN6 = false, bViv = false, BKor = false, BVivEror = false, BRandomK1 = false, BRandomK2 = false;
int Ship = 0; 
int Ogran, OgranN6 = 360, i = 0;
int arr[4], arr2[4];
int x = 224, y = 294;
int a, b, h, razmer = 8;
int SaveArrPl1[15][15];
int SaveArrPl2[15][15];
int BombArr[15][15];
int BombArr2[15][15];

bomb byr1[15][15];
bomb byr2[15][15];

RenderWindow window(VideoMode(2000, 1200), "Sea_fight", Style::Fullscreen);

int main()
{
	bmenu = false;
	FreeConsole();
	int j = 0, n = 0;

	setlocale(LC_CTYPE, "Russian");
	window.setActive();

	arr[3] = 1;
	arr[2] = 2;
	arr[1] = 3;
	arr[0] = 4;
	arr2[3] = 1;
	arr2[2] = 2;
	arr2[1] = 3;
	arr2[0] = 4;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		
		if (Pl == Nach) {
			if (Keyboard::isKeyPressed(Keyboard::Num2)) {
				if (razmer < 15) {
					razmer++;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Num1)) {
				if (razmer > 8) {
					razmer--;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Num7)) {
				Pl = Pl1;
			}
		}
		
		if (Pl == Pl2) {

			if (bul == false) {
				x = 564; y = 24;
				if (Keyboard::isKeyPressed(Keyboard::Num4)) {
					if (arr2[3] > 0) {
						Ship = 4; bul = true; a = 25; b = 115;
						bN6 = false;
						bViv = true;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3)) {
					if (arr2[2] > 0) {
						Ship = 3; bul = true; a = 25; b = 85;
						bN6 = false;
						bViv = true;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2)) {
					if (arr2[1] > 0) {
						Ship = 2; bul = true; a = 25; b = 55;
						bN6 = false;
						bViv = true;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num1)) {
					if (arr2[0] > 0) {
						Ship = 1; bul = true; a = 25; b = 25;
						bN6 = false;
						bViv = true;
					}
				}
			}

			if (bul == true) {
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					if (x >= 590) {
						x = x - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					if (x <= OgranN6) {
						x = x + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					if (y >= 40) {
						y = y - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					if (y <= Ogran) {
						y = y + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num6)) {
					i++;
					switch (Ship) {
					case 4:
						if (((x - 594 + ((razmer - 7) * 30)) / 30) > (razmer - 3)) { x = x - 90; }
						if (((y + 6) / 30) > (razmer - 3)) { y = y - 90; }
						break;
					case 3:
						if (((x - 564 + ((razmer - 7) * 30)) / 30) > (razmer - 2)) { x = x - 60; }
						if (((y + 6) / 30) > (razmer - 2)) { y = y - 60; }
						break;
					case 2:
						if (((x - 534 + ((razmer - 7) * 30)) / 30) > (razmer - 1)) { x = x - 30; }
						if (((y + 6) / 30) > (razmer - 1)) { y = y - 30; }
						break;
					case 1:
						break;
					}
					h = a;
					a = b;
					b = h;
					if (i == 1) {
						if (bN6 == false) {
							bN6 = true;
						}
					}
					if (i == 2) {
						if (bN6 == true) {
							bN6 = false;
						}
					}
					if (i == 2) { i = 0; }
				}
				if (Keyboard::isKeyPressed(Keyboard::Num5)) {

					if (ReconShip2(Ship, x, y, a, b, razmer) == false) {
						SaveArr2(Ship, x, y, a, b, razmer);
						BVivEror = false;
						bul = false;
						bViv = false;
						bN6 = false;
						i = 0;
						switch (Ship) {
						case 4:
							if (arr2[3] > 0) {
								arr2[3] = arr2[3] - 1;
							}
							break;
						case 3:
							if (arr2[2] > 0) {
								arr2[2] = arr2[2] - 1;
							}
							break;
						case 2:
							if (arr2[1] > 0) {
								arr2[1] = arr2[1] - 1;
							}
							break;
						case 1:
							if (arr2[0] > 0) {
								arr2[0] = arr2[0] - 1;
							}
							break;
						}
					}
					else { BVivEror = true; }
				}
			}

			switch (Ship) {
			case 4:
				Ogran = 110 + ((razmer - 7) * 30);
				OgranN6 = 730 + ((razmer - 7) * 30);
				break;
			case 3:
				Ogran = 140 + ((razmer - 7) * 30);
				OgranN6 = 730 + ((razmer - 7) * 30);
				break;
			case 2:
				Ogran = 170 + ((razmer - 7) * 30);
				OgranN6 = 730 + ((razmer - 7) * 30);
				break;
			case 1:
				Ogran = 200 + ((razmer - 7) * 30);
				OgranN6 = 730 + ((razmer - 7) * 30);
				break;
			}
			if (bN6 == true) {
				switch (Ship) {
				case 4:
					OgranN6 = 640 + ((razmer-7)*30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				case 3:
					OgranN6 = 670 + ((razmer - 7) * 30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				case 2:
					OgranN6 = 700 + ((razmer - 7) * 30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				case 1:
					OgranN6 = 730 + ((razmer - 7) * 30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				}
			}

			if (arr2[0] == 0 & arr2[1] == 0 & arr2[2] == 0 & arr2[3] == 0) { Pl = Start; }
		}
		if (Pl == Pl1) {
			if (bul == false) {
				x = 44; y = 24;
				if (Keyboard::isKeyPressed(Keyboard::Num4)) {
						if (arr[3] > 0) {
							Ship = 4; bul = true; a = 25; b = 115;
							bN6 = false;
							bViv = true;
						}
					}
				if (Keyboard::isKeyPressed(Keyboard::Num3)) {
						if (arr[2] > 0) {
							Ship = 3; bul = true; a = 25; b = 85;
							bN6 = false;
							bViv = true;
						}
					}
				if (Keyboard::isKeyPressed(Keyboard::Num2)) {
						if (arr[1] > 0) {
							Ship = 2; bul = true; a = 25; b = 55;
							bN6 = false;
							bViv = true;
						}
					}
				if (Keyboard::isKeyPressed(Keyboard::Num1)) {
						if (arr[0] > 0) {
							Ship = 1; bul = true; a = 25; b = 25;
							bN6 = false;
							bViv = true;
						}
					}
			}
		

			if (bul == true) {
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					if (x >= 70) {
						x = x - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					if (x <= OgranN6) {
						x = x + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					if (y >= 40) {
						y = y - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					if (y <= Ogran) {
						y = y + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num6)) {
					i++;
					switch (Ship) {
					case 4:
						if ((x - 14) / 30 > + (razmer - 3)) { x = x - 90; }
						if ((y + 6) / 30 > (razmer - 3)) { y = y - 90; }
						break;
					case 3:
						if ((x - 14) / 30 > (razmer - 2)) { x = x - 60; }
						if ((y + 6) / 30 > (razmer - 2)) { y = y - 60; }
						break;
					case 2:
						if ((x - 14) / 30 > (razmer - 1)) { x = x - 30; }
						if ((y + 6) / 30 > (razmer - 1)) { y = y - 30; }
						break;
					case 1:
						break;
					}
					h = a;
					a = b;
					b = h;
					if (i == 1) {
						if (bN6 == false) {
							bN6 = true;
						}
					}
					if (i == 2) {
						if (bN6 == true) {
							bN6 = false;
						}
					}
					if (i == 2) { i = 0; }
				}
				if (Keyboard::isKeyPressed(Keyboard::Num5)) {

					if (ReconShip(Ship, x, y, a, b, razmer) == false) {
						SaveArr(Ship, x, y, a, b, razmer);
						BVivEror = false;
						bul = false;
						bViv = false;
						bN6 = false;
						i = 0;
						switch (Ship) {
						case 4:
							if (arr[3] > 0) {
								arr[3] = arr[3] - 1;
							}
							break;
						case 3:
							if (arr[2] > 0) {
								arr[2] = arr[2] - 1;
							}
							break;
						case 2:
							if (arr[1] > 0) {
								arr[1] = arr[1] - 1;
							}
							break;
						case 1:
							if (arr[0] > 0) {
								arr[0] = arr[0] - 1;
							}
							break;
						}
					}
					else { BVivEror = true; }
				}
			}

			switch (Ship) {
			case 4:
				Ogran = 110 + ((razmer-7)*30);
				OgranN6 = 210 + ((razmer - 7) * 30);
				break;
			case 3:
				Ogran = 140 + ((razmer - 7) * 30);
				OgranN6 = 210 + ((razmer - 7) * 30);
				break;
			case 2:
				Ogran = 170 + ((razmer - 7) * 30);
				OgranN6 = 210 + ((razmer - 7) * 30);
				break;
			case 1:
				Ogran = 200 + ((razmer - 7) * 30);
				OgranN6 = 210 + ((razmer - 7) * 30);
				break;
			}
			if (bN6 == true) {
				switch (Ship) {
				case 4:
					OgranN6 = 120 + ((razmer - 7) * 30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				case 3:
					OgranN6 = 150 + ((razmer - 7) * 30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				case 2:
					OgranN6 = 180 + ((razmer - 7) * 30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				case 1:
					OgranN6 = 210 + ((razmer - 7) * 30);
					Ogran = 200 + ((razmer - 7) * 30);
					break;
				}
			}

			if (arr[0] == 0 & arr[1] == 0 & arr[2] == 0 & arr[3] == 0) { Pl = Pl2; }
		}

		if (Pl == Start) {
			if (Keyboard::isKeyPressed(Keyboard::Num7)) {
				BKor = true;
				Pl = Pl1S;
			}
		}

		if (Pl == Pl1S) {
			if (PrKill(razmer) == true) {
				if (WinP1(razmer) == true) {
					Pl = Finish1;
				}
			}
			if (bul == false) {
				x = 44; y = 204;
				bul = true;
				OgranN6 = 210 + ((razmer-7)*30);
			}
			if (bul == true) {
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					if (x >= 70) {
						x = x - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					if (x <= OgranN6) {
						x = x + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					if (y >= 40) {
						y = y - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					if (y <= (174 + ((razmer - 7) * 30))) {
						y = y + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num8)) {
					SaveBomb(x, y);
					n = (x - 44) / 30;
					j = (y - 24) / 30;
					bul = false;
					if (SaveArrPl1[j][n] == 1) {
						Pl = Pl1S;
						SaveArrPl1[j][n] = 3;
						Sleep(150);
					}
					else { Pl = Pl2S; }
				}
			}
		}
		if (Pl == Pl2S) {
			if (PrKill2(razmer) == true) {
				if (WinP2(razmer) == true) {
					Pl = Finish2;
				}
			}
			if (bul == false) {
				x = 564; y = 204;
				bul = true;
			}
			if (bul == true) {
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					if (x >= 594) {
						x = x - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					if (x <= (724 + ((razmer - 7) * 30))) {
						x = x + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					if (y >= 40) {
						y = y - 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					if (y <= (174 + ((razmer - 7) * 30))) {
						y = y + 30;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Num9)) {
					SaveBomb2(x, y);
					n = (x - 564) / 30;
					j = (y - 24) / 30;
					bul = false;
					if (SaveArrPl2[j][n] == 1) {
						Pl = Pl2S;
						SaveArrPl2[j][n] = 3;
						Sleep(150);
					}
					else { Pl = Pl1S; }
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			bmenu = false;
		}

		window.clear();

		if (bmenu == false) { 
			Menu(window); 
		}
		else {
			if (BKor == false) {
				SaveKor(window, x, y, Ship, a, b);
				OutKor(window);
			}
			if (bViv == true) {
				Viv(window, x, y, Ship, a, b);
			}
			if (BVivEror == true) {
				VivEror(window);
			}
			if (Pl == Pl2) {
				ClearBar(window, 0, 0, 550, 700);
			}
			if (BKor == true) {


				for (n = 0; n < razmer; n++) {
					for (j = 0; j < razmer; j++) {
						if ((BombArr2[j][n] == 1)) byr2[j][n].SaveVivB(window, n * 30 + 564, j * 30 + 24);
						if ((BombArr[j][n] == 1)) byr1[j][n].SaveVivB(window, n * 30 + 44, j * 30 + 24);

						if ((SaveArrPl2[j][n] == 4) and (BombArr2[j][n] == 1)) { byr2[j][n].SaveVivBy(window, n * 30 + 564, j * 30 + 24); }
						if (SaveArrPl2[j][n] == 5) { byr2[j][n].SaveVivB(window, n * 30 + 564, j * 30 + 24); }

						if ((SaveArrPl1[j][n] == 4) and (BombArr[j][n] == 1)) { byr1[j][n].SaveVivBy(window, n * 30 + 44, j * 30 + 24); }
						if (SaveArrPl1[j][n] == 5) { byr1[j][n].SaveVivB(window, n * 30 + 44, j * 30 + 24); }
					}
				}
				VivBomb(window, x, y);
			}
			if (Pl == Start) {
				ClearBar(window, 0, 0, 1200, 700);
				OutTextXY(window, 450, 580, "N7 - Start");
			}
			OutStructure(window, razmer);
			if (Pl == Finish1) {
				Font font;
				if (!font.loadFromFile("arial.ttf")) {}
				Text text;
				text.setFont(font);
				text.setString("P2!!!");
				text.setCharacterSize(15);
				text.setPosition(400, 500);
				window.draw(text);
				window.setActive();
			}
			if (Pl == Finish2) {
				Font font;
				if (!font.loadFromFile("arial.ttf")) {}
				Text text;
				text.setFont(font);
				text.setString("P1!!!");
				text.setCharacterSize(15);
				text.setPosition(400, 500);
				window.draw(text);
				window.setActive();
			}
		}

		window.display();
	};
	return 0;
}