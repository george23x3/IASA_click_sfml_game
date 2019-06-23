#include <SFML/Graphics.hpp>

using namespace sf;
int menu(sf::RenderWindow & window) {
	sf::Image iStart, iTutorial, iExit, iInfo, iBackground, ibgg1, ibgg2, ibgg3;
	sf::Texture tStart, tTutorial, tExit, tInfo, tBackground, tbgg1, tbgg2, tbgg3;
	iStart.loadFromFile("Start.png");
	iTutorial.loadFromFile("T.png");
	iExit.loadFromFile("Exit.png");
	iInfo.loadFromFile("Tutorial.png");
	iBackground.loadFromFile("Menu.png");
	ibgg1.loadFromFile("bgg1.png");
	ibgg2.loadFromFile("bgg2.png");
	ibgg3.loadFromFile("bgg3.png");
	iStart.createMaskFromColor(sf::Color::White);
	iTutorial.createMaskFromColor(sf::Color::White);
	iExit.createMaskFromColor(sf::Color::White);
	tStart.loadFromImage(iStart);
	tTutorial.loadFromImage(iTutorial);
	tExit.loadFromImage(iExit);
	tInfo.loadFromImage(iInfo);
	tBackground.loadFromImage(iBackground);
	tbgg1.loadFromImage(ibgg1);
	tbgg2.loadFromImage(ibgg2);
	tbgg3.loadFromImage(ibgg3);
	sf::Sprite sStart(tStart), sTutorial(tTutorial), sExit(tExit), sInfo(tInfo), sBackground(tBackground), sbgg1(tbgg1), sbgg2(tbgg2), sbgg3(tbgg3);
	bool isMenu = 1;
	int menuNum = 0;
	sStart.setPosition(545, 230);
	sTutorial.setPosition(540, 320);
	sExit.setPosition(585, 410);
	sbgg1.setPosition(0, 260);
	sbgg2.setPosition(1080, 260);
	sbgg3.setPosition(540, 500);

	while (isMenu)
	{
		sStart.setColor(sf::Color::Black);
		sTutorial.setColor(sf::Color::Black);
		sExit.setColor(sf::Color::Black);
		menuNum = 0;
		window.clear(sf::Color());
		sbgg1.setTextureRect(IntRect(0, 0, 200, 200));
	    sbgg2.setTextureRect(sf::IntRect(0, 0, 200, 200));
	    sbgg3.setTextureRect(sf::IntRect(0, 0, 200, 200));
		if (sf::IntRect(545, 230, 182, 60).contains(sf::Mouse::getPosition(window))) 
		{ 
			sStart.setColor(sf::Color::Red); menuNum = 1; 
			sbgg1.setTextureRect(IntRect(0, 200, 200, 200));
			sbgg2.setTextureRect(IntRect(0, 200, 200, 200));
			sbgg3.setTextureRect(IntRect(0, 200, 200, 200));
		}
		if (sf::IntRect(540, 320, 192, 60).contains(sf::Mouse::getPosition(window))) 
		{ 
			sTutorial.setColor(sf::Color::Red); menuNum = 2; 
			sbgg1.setTextureRect(IntRect(0, 400, 200, 200));
			sbgg2.setTextureRect(IntRect(0, 400, 200, 200));
			sbgg3.setTextureRect(IntRect(0, 400, 200, 200));
		}
		if (sf::IntRect(585, 410, 110, 60).contains(sf::Mouse::getPosition(window))) 
		{ 
			sExit.setColor(sf::Color::Red); menuNum = 3; 
			sbgg1.setTextureRect(IntRect(0, 600, 200, 200));
			sbgg2.setTextureRect(IntRect(0, 600, 200, 200));
			sbgg3.setTextureRect(IntRect(0, 600, 200, 200));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) {
				isMenu = false; return 0;
			}
			if (menuNum == 2) { window.draw(sInfo); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)); }
			if (menuNum == 3) { isMenu = false; return 1; }

		}

		window.draw(sBackground);
		window.draw(sStart);
		window.draw(sTutorial);
		window.draw(sExit);
		window.draw(sbgg1);
		window.draw(sbgg2);
		window.draw(sbgg3);
		window.display();
	}
}