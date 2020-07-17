#include <SFML/Graphics.hpp>
#include "GraphLib.h"

using namespace std;
using namespace sf;

int Nul = 0;
extern int arr[4], arr2[4];

int x11, y11, x12, y12, x13, y13, x14, y14;
int a11, b11, a12, b12, a13, b13, a14, b14;
bool bu11 = false, bu12 = false, bu13 = false, bu14 = false;

int x21, y21, x22, y22, x23, y23;
int a21, b21, a22, b22, a23, b23;
bool bu21 = false, bu22 = false, bu23 = false;

int x31, y31, x32, y32;
int a31, b31, a32, b32;
bool bu31 = false, bu32 = false;

int x41, y41;
int a41, b41;
bool bu41 = false;

int x211, y211, x212, y212, x213, y213, x214, y214;
int a211, b211, a212, b212, a213, b213, a214, b214;
bool bu211 = false, bu212 = false, bu213 = false, bu214 = false;

int x221, y221, x222, y222, x223, y223;
int a221, b221, a222, b222, a223, b223;
bool bu221 = false, bu222 = false, bu223 = false;

int x231, y231, x232, y232;
int a231, b231, a232, b232;
bool bu231 = false, bu232 = false;

int x241, y241;
int a241, b241;
bool bu241 = false;

struct TRecTV {
	int X, Y, P;
	int *value;
};
const int CountRec = 28;
TRecTV ArrRec[CountRec] = {
	{40, 50, 1, &Nul},
	{-30, 20, 2, &Nul},
	{40, 80, 1, &Nul},
	{0, 20, 2, &Nul},
	{40, 110, 1, &Nul},
	{30, 20, 2, &Nul},
	{40, 140, 1, &Nul},
	{60, 20, 2, &Nul},
	{40, 170, 1, &Nul},
	{90, 20, 2, &Nul},
	{40, 200, 1, &Nul},
	{120, 20, 2, &Nul},
	{40, 230, 1, &Nul},
	{150, 20, 2, &Nul},
	{40, 260, 1, &Nul},
	{180, 20, 2, &Nul},
	{40, 290, 1, &Nul},
	{210, 20, 2, &Nul},
	{40, 320, 1, &Nul},
	{240, 20, 2, &Nul},
	{40, 350, 1, &Nul},
	{270, 20, 2, &Nul},
	{40, 380, 1, &Nul},
	{300, 20, 2, &Nul},
	{40, 410, 1, &Nul},
	{330, 20, 2, &Nul},
	{40, 440, 1, &Nul},
	{360, 20, 2, &Nul}
};

struct TTextTV {
	int X, Y;
	string st;
};
const int CountText = 15;
TTextTV ArrText[CountText] = {
	{30, 30,"1"},
	{30, 60, "2"},
	{30, 90, "3"},
	{30, 120, "4"},
	{30, 150, "5"},
	{30, 180, "6"},
	{30, 210, "7"},
	{30, 240, "8"},
	{30, 270, "9"},
	{23, 300, "10"},
	{23, 330, "11"},
	{23, 360, "12"},
	{23, 390, "13"},
	{23, 420, "14"},
	{23, 450, "15"}

};
TTextTV ArrText2[CountText] = {
	{50, 0,"a"},
	{80, 0, "b"},
	{110, 0, "c"},
	{140, 0, "d"},
	{170, 0, "e"},
	{200, 0, "f"},
	{230, 0, "g"},
	{260, 0, "h"},
	{290, 0, "i"},
	{320, 0, "j"},
	{350, 0, "k"},
	{380, 0, "l"},
	{410, 0, "m"},
	{440, 0, "n"},
	{470, 0, "o"}
};

void OutStructure(RenderWindow& window, int razmer)
{
	int i;

	for (i = 0; i < (12 + (razmer-7)*2); i++) {
		OutLin(window, ArrRec[i].X, ArrRec[i].Y, ArrRec[i].P, razmer);
	}
	for (i = 0; i < razmer; i++) {
		OutText1XY(window, ArrText[i].X, ArrText[i].Y, ArrText[i].st, razmer);
		OutText2XY(window, ArrText2[i].X, ArrText2[i].Y, ArrText2[i].st, razmer);
	}
};

void Viv(RenderWindow& window, int x, int y, int Ship, int a, int b) {
	if (Ship == 4) { OutKor4(window, x, y, a, b); }
	if (Ship == 3) { OutKor3(window, x, y, a, b); }
	if (Ship == 2) { OutKor2(window, x, y, a, b); }
	if (Ship == 1) { OutKor1(window, x, y); }
}

void OutKor(RenderWindow& window) {

	RectangleShape Kor1(Vector2f(25, 25));
	Kor1.setFillColor(Color::Blue);
	Kor1.setPosition(160, 430+80);
	window.draw(Kor1);
	OutTextXY(window, 160, 415 + 80, St_In(arr[0]));
	OutTextXY(window, 160, 555 + 80, "N1");

	RectangleShape Kor2(Vector2f(25, 56));
	Kor2.setFillColor(Color::Blue);
	Kor2.setPosition(120, 430 + 80);
	window.draw(Kor2);
	OutTextXY(window, 120, 415 + 80, St_In(arr[1]));
	OutTextXY(window, 120, 555 + 80, "N2");

	RectangleShape Kor3(Vector2f(25, 85));
	Kor3.setFillColor(Color::Blue);
	Kor3.setPosition(80, 430 + 80);
	window.draw(Kor3);
	OutTextXY(window, 80, 415 + 80, St_In(arr[2]));
	OutTextXY(window, 80, 555 + 80, "N3");

	RectangleShape Kor4(Vector2f(25, 116));
	Kor4.setFillColor(Color::Blue);
	Kor4.setPosition(40, 430 + 80);
	window.draw(Kor4);
	OutTextXY(window, 40, 415 + 80, St_In(arr[3]));
	OutTextXY(window, 40, 555 + 80, "N4");

	OutTextXY(window, 220, 555 + 80, "N5 - Save");
	OutTextXY(window, 220, 585 + 80, "N6 - Povorot");

	RectangleShape Kor21(Vector2f(25, 25));
	Kor1.setFillColor(Color::Blue);
	Kor1.setPosition(590 + 90, 430 + 80);
	window.draw(Kor1);
	OutTextXY(window, 590 + 90, 415 + 80, St_In(arr2[0]));
	OutTextXY(window, 590 + 90, 555 + 80, "N1");

	RectangleShape Kor22(Vector2f(25, 56));
	Kor2.setFillColor(Color::Blue);
	Kor2.setPosition(550 + 90, 430 + 80);
	window.draw(Kor2);
	OutTextXY(window, 550 + 90, 415 + 80, St_In(arr2[1]));
	OutTextXY(window, 550 + 90, 555 + 80, "N2");

	RectangleShape Kor23(Vector2f(25, 85));
	Kor3.setFillColor(Color::Blue);
	Kor3.setPosition(510 + 90, 430 + 80);
	window.draw(Kor3);
	OutTextXY(window, 510 + 90, 415 + 80, St_In(arr2[2]));
	OutTextXY(window, 510 + 90, 555 + 80, "N3");

	RectangleShape Kor24(Vector2f(25, 116));
	Kor4.setFillColor(Color::Blue);
	Kor4.setPosition(470 + 90, 430 + 80);
	window.draw(Kor4);
	OutTextXY(window, 470 + 90, 415 + 80, St_In(arr2[3]));
	OutTextXY(window, 470 + 90, 555 + 80, "N4");

	OutTextXY(window, 650 + 90, 555 + 80, "N5 - Save");
	OutTextXY(window, 650 + 90, 585 + 80, "N6 - Povorot");
}

void SaveKor(RenderWindow& window, int x, int y, int Ship, int a, int b) {

		if (arr[0] <= 3) {
			if (bu11 == false) {
				x11 = x;
				y11 = y;
				a11 = a;
				b11 = b;
				bu11 = true;
			}
			RectangleShape Kor1(Vector2f(a11, b11));//, Kor2(Vector2f(a11, b11));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x11, y11);
			window.draw(Kor1);			
		}
		if (arr[0] <= 2) {
			if (bu12 == false) {
				x12 = x;
				y12 = y;
				a12 = a;
				b12 = b;
				bu12 = true;
			}
			RectangleShape Kor1(Vector2f(a12, b12));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x12, y12);
			window.draw(Kor1);
		}
		if (arr[0] <= 1) {
			if (bu13 == false) {
				x13 = x;
				y13 = y;
				a13 = a;
				b13 = b;
				bu13 = true;
			}
			RectangleShape Kor1(Vector2f(a13, b13));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x13, y13);
			window.draw(Kor1);
		}
		if (arr[0] <= 0) {
			if (bu14 == false) {
				x14 = x;
				y14 = y;
				a14 = a;
				b14 = b;
				bu14 = true;
			}
			RectangleShape Kor1(Vector2f(a14, b14));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x14, y14);
			window.draw(Kor1);
		}

		if (arr[1] <= 2) {
			if (bu21 == false) {
				x21 = x;
				y21 = y;
				a21 = a;
				b21 = b;
				bu21 = true;
			}
			RectangleShape Kor2(Vector2f(a21, b21));
			Kor2.setFillColor(Color::Blue);
			Kor2.setPosition(x21, y21);
			window.draw(Kor2);
		}
		if (arr[1] <= 1) {
			if (bu22 == false) {
				x22 = x;
				y22 = y;
				a22 = a;
				b22 = b;
				bu22 = true;
			}
			RectangleShape Kor2(Vector2f(a22, b22));
			Kor2.setFillColor(Color::Blue);
			Kor2.setPosition(x22, y22);
			window.draw(Kor2);
		}
		if (arr[1] <= 0) {
			if (bu23 == false) {
				x23 = x;
				y23 = y;
				a23 = a;
				b23 = b;
				bu23 = true;
			}
			RectangleShape Kor2(Vector2f(a23, b23));
			Kor2.setFillColor(Color::Blue);
			Kor2.setPosition(x23, y23);
			window.draw(Kor2);
		}

		if (arr[2] <= 1) { 
			if (bu31 == false) {
				x31 = x;
				y31 = y;
				a31 = a;
				b31 = b;
				bu31 = true;
			}
			RectangleShape Kor3(Vector2f(a31, b31));
			Kor3.setFillColor(Color::Blue);
			Kor3.setPosition(x31, y31);
			window.draw(Kor3);
		}
		if (arr[2] <= 0) {
			if (bu32 == false) {
				x32 = x;
				y32 = y;
				a32 = a;
				b32 = b;
				bu32 = true;
			}
			RectangleShape Kor3(Vector2f(a32, b32));
			Kor3.setFillColor(Color::Blue);
			Kor3.setPosition(x32, y32);
			window.draw(Kor3);
		}
		
		if (arr[3] <= 0) {
			if (bu41 == false) {
				x41 = x;
				y41 = y;
				a41 = a;
				b41 = b;
				bu41 = true;
			}
			RectangleShape Kor4(Vector2f(a41, b41));
			Kor4.setFillColor(Color::Blue);
			Kor4.setPosition(x41, y41);
			window.draw(Kor4);
		}

		if (arr2[0] <= 3) {
			if (bu211 == false) {
				x211 = x;
				y211 = y;
				a211 = a;
				b211 = b;
				bu211 = true;
			}
			RectangleShape Kor1(Vector2f(a211, b211));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x211, y211);
			window.draw(Kor1);
		}
		if (arr2[0] <= 2) {
			if (bu212 == false) {
				x212 = x;
				y212 = y;
				a212 = a;
				b212 = b;
				bu212 = true;
			}
			RectangleShape Kor1(Vector2f(a212, b212));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x212, y212);
			window.draw(Kor1);
		}
		if (arr2[0] <= 1) {
			if (bu213 == false) {
				x213 = x;
				y213 = y;
				a213 = a;
				b213 = b;
				bu213 = true;
			}
			RectangleShape Kor1(Vector2f(a213, b213));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x213, y213);
			window.draw(Kor1);
		}
		if (arr2[0] <= 0) {
			if (bu214 == false) {
				x214 = x;
				y214 = y;
				a214 = a;
				b214 = b;
				bu214 = true;
			}
			RectangleShape Kor1(Vector2f(a214, b214));
			Kor1.setFillColor(Color::Blue);
			Kor1.setPosition(x214, y214);
			window.draw(Kor1);
		}

		if (arr2[1] <= 2) {
			if (bu221 == false) {
				x221 = x;
				y221 = y;
				a221 = a;
				b221 = b;
				bu221 = true;
			}
			RectangleShape Kor2(Vector2f(a221, b221));
			Kor2.setFillColor(Color::Blue);
			Kor2.setPosition(x221, y221);
			window.draw(Kor2);
		}
		if (arr2[1] <= 1) {
			if (bu222 == false) {
				x222 = x;
				y222 = y;
				a222 = a;
				b222 = b;
				bu222 = true;
			}
			RectangleShape Kor2(Vector2f(a222, b222));
			Kor2.setFillColor(Color::Blue);
			Kor2.setPosition(x222, y222);
			window.draw(Kor2);
		}
		if (arr2[1] <= 0) {
			if (bu223 == false) {
				x223 = x;
				y223 = y;
				a223 = a;
				b223 = b;
				bu223 = true;
			}
			RectangleShape Kor2(Vector2f(a223, b223));
			Kor2.setFillColor(Color::Blue);
			Kor2.setPosition(x223, y223);
			window.draw(Kor2);
		}

		if (arr2[2] <= 1) {
			if (bu231 == false) {
				x231 = x;
				y231 = y;
				a231 = a;
				b231 = b;
				bu231 = true;
			}
			RectangleShape Kor3(Vector2f(a231, b231));
			Kor3.setFillColor(Color::Blue);
			Kor3.setPosition(x231, y231);
			window.draw(Kor3);
		}
		if (arr2[2] <= 0) {
			if (bu232 == false) {
				x232 = x;
				y232 = y;
				a232 = a;
				b232 = b;
				bu232 = true;
			}
			RectangleShape Kor3(Vector2f(a232, b232));
			Kor3.setFillColor(Color::Blue);
			Kor3.setPosition(x232, y232);
			window.draw(Kor3);
		}

		if (arr2[3] <= 0) {
			if (bu241 == false) {
				x241 = x;
				y241 = y;
				a241 = a;
				b241 = b;
				bu241 = true;
			}
			RectangleShape Kor4(Vector2f(a241, b241));
			Kor4.setFillColor(Color::Blue);
			Kor4.setPosition(x241, y241);
			window.draw(Kor4);
		}

}