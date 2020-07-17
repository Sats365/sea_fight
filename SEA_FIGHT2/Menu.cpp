#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

extern bool bmenu = false;


void Menu(RenderWindow &window) {
	Texture TFonMen, TKnopStart, TKnopOptions, TKnopExit, aboutTexture;
	TFonMen.loadFromFile("Resurse\\menu.jpg");
	TKnopOptions.loadFromFile("Resurse\\Options.jpg");
	TKnopStart.loadFromFile("Resurse\\start.jpg");
	TKnopExit.loadFromFile("Resurse\\exit.jpg");
	aboutTexture.loadFromFile("images/about.png");

	Sprite SFonMen, SKnopStart, SKnopOptions, SKnopExit, about(aboutTexture);
	SKnopStart.setTexture(TKnopStart);
	SKnopOptions.setTexture(TKnopOptions);
	SKnopExit.setTexture(TKnopExit);
	SFonMen.setTexture(TFonMen);

	SKnopStart.setPosition(50, 100);
	SKnopOptions.setPosition(50, 300);
	SKnopExit.setPosition(50, 500);
	SFonMen.setPosition(0, 0);

	bool isMenu = 1;
	int menuNum = 0;
	while (isMenu)
	{

		SKnopStart.setColor(Color::White);
		SKnopOptions.setColor(Color::White);
		SKnopExit.setColor(Color::White);
		menuNum = 0;

		window.clear(Color(129, 181, 221));

		if (IntRect(50, 100, 355, 100).contains(Mouse::getPosition(window))) { SKnopStart.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(50, 300, 518, 100).contains(Mouse::getPosition(window))) { SKnopOptions.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(50, 500, 278, 100).contains(Mouse::getPosition(window))) { SKnopExit.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				isMenu = false;//если нажали первую кнопку, то выходим из меню
				bmenu = true;
			}
			if (menuNum == 2) {
				window.draw(about);
				window.display();
				while (!Keyboard::isKeyPressed(Keyboard::Escape)) {

				};
				bmenu = false;
			}
			if (menuNum == 3) {
				window.close(); 
				isMenu = false; 
				bmenu = false;
			}
		}
		else {
			bmenu = false;
		}

		window.draw(SFonMen);
		window.draw(SKnopExit);
		window.draw(SKnopOptions);
		window.draw(SKnopStart);

		window.display();
	}

}