#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

string St_In(int cis)
{
	string st;
	int ost;
	char ch;
	if (cis == 0) { st = "0"; }
	if (cis >= 0) {
		while (cis != 0)
		{
			ost = cis % 10;
			cis = cis / 10;
			if (ost >= 0 & ost <= 9) { ch = char(ost + 48); }
			else { ch = char(ost + 55); }
			st = ch + st;
		}
	}
	else {
		cis = -1 * cis;
		while (cis != 0)
		{
			ost = cis % 10;
			cis = cis / 10;
			if (ost >= 0 & ost <= 9) { ch = char(ost + 48); }
			else { ch = char(ost + 55); }
			st = ch + st;
		}
		st = "-" + st;
	}
	return(st);
}

void OutLin(RenderWindow& window, int x, int y, int p, int razmer)
{
	
	if (p == 1) {
		RectangleShape line1(Vector2f(210+((razmer-7)*30), 3));
		line1.setPosition(x, y);
		window.draw(line1);	
		RectangleShape line1_2(Vector2f(210 + ((razmer - 7) * 30), 3));
		line1_2.setPosition(x+520, y);
		window.draw(line1_2);
	}
	if (p == 2) {
		RectangleShape line2(Vector2f(3, 210 + ((razmer - 7) * 30)));
		line2.setPosition(x+100, y);
		window.draw(line2);
		RectangleShape line2_2(Vector2f(3, 210 + ((razmer - 7) * 30)));
		line2_2.setPosition(x + 620, y);
		window.draw(line2_2);
	}

	RectangleShape lineb(Vector2f(5, 215 + ((razmer-7)*30)));
	lineb.setPosition(40, 20);
	RectangleShape lineb1(Vector2f(215 + ((razmer - 7) * 30), 5));
	lineb1.setPosition(40, 20);
	RectangleShape lineb2(Vector2f(5, 215 + ((razmer - 7) * 30)));
	lineb2.setPosition(250 + ((razmer - 7) * 30), 20);
	RectangleShape lineb3(Vector2f(215 + ((razmer - 7) * 30), 5));
	lineb3.setPosition(40, 230 + ((razmer - 7) * 30));

	RectangleShape linebb(Vector2f(5, 215 + ((razmer - 7) * 30)));
	linebb.setPosition(560, 20);
	RectangleShape linebb1(Vector2f(215 + ((razmer - 7) * 30), 5));
	linebb1.setPosition(560, 20);
	RectangleShape linebb2(Vector2f(5, 215 + ((razmer - 7) * 30)));
	linebb2.setPosition(770 + ((razmer - 7) * 30), 20);
	RectangleShape linebb3(Vector2f(215 + ((razmer - 7) * 30), 5));
	linebb3.setPosition(560, 230 + ((razmer - 7) * 30));
	   
	window.draw(lineb);
	window.draw(lineb1);
	window.draw(lineb2);
	window.draw(lineb3);

	window.draw(linebb);
	window.draw(linebb1);
	window.draw(linebb2);
	window.draw(linebb3);
};

void OutText1XY(RenderWindow& window, int x, int y, string st, int razmer)
{
	Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	Text text;
	Text text1;
	Text text2;
	Text text3;

	text.setFont(font);
	text1.setFont(font);
	text2.setFont(font);
	text3.setFont(font);

	text.setString(st);
	text1.setString(st);
	text2.setString(st);
	text3.setString(st);

	text.setCharacterSize(15);
	text1.setCharacterSize(15);
	text2.setCharacterSize(15);
	text3.setCharacterSize(15);

	text.setPosition(x - 8, y);
	text1.setPosition(x + 240 + ((razmer - 7) * 30), y);
	text2.setPosition(x + 510, y);
	text3.setPosition(x + 760 + ((razmer - 7) * 30), y);

	window.draw(text);
	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
	window.setActive();
};

void OutText2XY(RenderWindow& window, int x, int y, string st, int razmer)
{
	Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	Text text;
	Text text1;
	Text text2;
	Text text3;

	text.setFont(font);
	text1.setFont(font);
	text2.setFont(font);
	text3.setFont(font);

	text.setString(st);
	text1.setString(st);
	text2.setString(st);
	text3.setString(st);

	text.setCharacterSize(15);
	text1.setCharacterSize(15);
	text2.setCharacterSize(15);
	text3.setCharacterSize(15);

	text.setPosition(x, y);
	text1.setPosition(x, y + 235 + ((razmer - 7) * 30));
	text2.setPosition(x + 520, y);
	text3.setPosition(x + 520, y + 235 + ((razmer - 7) * 30));

	window.draw(text);
	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
	window.setActive();
};

void OutTextXY(RenderWindow& window, int x, int y, string st)
{
	Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	Text text;
	text.setFont(font);
	text.setString(st);
	text.setCharacterSize(15);
	text.setPosition(x, y);
	window.draw(text);
	window.setActive();
};

void ClearBar(RenderWindow& window, int Left, int Top, int Right, int Bottom) {
	RectangleShape line(Vector2f(Right, Bottom));
	line.setPosition(Left, Top);
	line.setFillColor(Color::Black);
	window.draw(line);
}

void OutKor4(RenderWindow& window, int x, int y, int a, int b) {
	RectangleShape Kor4(Vector2f(a, b));
	Kor4.setFillColor(Color::Blue);
	Kor4.setPosition(x, y);
	window.draw(Kor4);
}

void OutKor3(RenderWindow& window, int x, int y, int a, int b) {
	RectangleShape Kor3(Vector2f(a, b));
	Kor3.setFillColor(Color::Blue); 
	Kor3.setPosition(x, y);
	window.draw(Kor3);
}

void OutKor2(RenderWindow& window, int x, int y, int a, int b) {
	RectangleShape Kor2(Vector2f(a, b));
	Kor2.setFillColor(Color::Blue);
	Kor2.setPosition(x, y);
	window.draw(Kor2);
}

void OutKor1(RenderWindow& window, int x, int y) {
	RectangleShape Kor1(Vector2f(25, 25));
	Kor1.setFillColor(Color::Blue);
	Kor1.setPosition(x, y);
	window.draw(Kor1);
}

void VivEror(RenderWindow& window) {
	Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	Text text;
	text.setFont(font);
	text.setString(" Eror ");
	text.setCharacterSize(15);
	text.setPosition(213, 510);
	window.draw(text);
	window.setActive();
}