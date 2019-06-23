#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include "Menu.h"

using namespace sf;
class Stuff {
private:
	float x, y;
	std::string file;
public:
	Image istuff;
	Texture tstuff;
	Sprite sstuff;
	Stuff(float X, float Y, std::string f)
	{
		x = X;
		y = Y;
		istuff.loadFromFile("" + f);
		istuff.createMaskFromColor(sf::Color::White);
		tstuff.loadFromImage(istuff);
		sstuff.setTexture(tstuff);
		sstuff.setPosition(x, y);
	}
	~Stuff() {}
};

class Target : public Stuff {
private: 
	float x, y, radius;
	std::string file;
public:
	Image imtarget;
	Texture tetarget;
	Sprite sptarget;
	Target (float X, float Y,  std::string f, float Radius): Stuff(X, Y, f)
	{
		imtarget = istuff;
		tetarget = tstuff;
		sptarget = sstuff;
		sptarget.setOrigin(Radius, Radius);
		
	}
	~Target() {}
	int Game1(int sx, int sy, int bg) {
		if (bg == 1) {
		   sptarget.setPosition(sy * 256, sx * 180);
		   return 1;
		}
		else {
			sptarget.setPosition(1400, 800);
			return 0;
		}

	}
};

class Photo: Stuff{
public:
	Image iPH;
	Texture tPH;
	Sprite sPH;
	Photo(float x, float y, std::string l):Stuff(x, y, l)
	{
		iPH = istuff;
		tPH = tstuff;
		sPH = sstuff;
	}
	~Photo(){}
	void Setbg (int x, int y){
		sPH.setTextureRect(IntRect(0, 0, x, y));
	}

};



bool game() {
		srand(time(0));
		RenderWindow window;
		window.create(VideoMode(1280, 720), "Test");
		int rrr = menu(window);
		if (rrr == 1) {
			return false;
		}
		Target T1(1024, 360, "target1.png", 50);
		Target T2(512, 360, "target2.png", 50);
		Target T3(256, 180, "target3.png", 50);
		Target T4(512, 540, "target4.png", 50);
		Target T5(256, 540, "target5.png", 50);
		Target T6(1024, 540, "target6.png", 50);
		Image imBG, iF;
		Texture txBG, tF;
		Sprite spBG, sF;
		imBG.loadFromFile("field.png");
		txBG.loadFromImage(imBG);
		spBG.setTexture(txBG);
		Photo BUV(0, 280, "BUV1.png");
		Photo KIU(1130, 280, "KIU1.png");
		Photo DMM(565, 570, "DMM1.png");
		Photo Final(320, 180, "final.png");
		BUV.Setbg(150, 150);
		KIU.Setbg(150, 150);
		DMM.Setbg(150, 150);
		Clock clock;
		int t1 = 0;
		int u1 = 0;
		int t2 = 0;
		int u2 = 0;
		int t3 = 0;
		int u3 = 0;
		int t4 = 0;
		int u4 = 0;
		int t5 = 0;
		int u5 = 0;
		int t6 = 0;
		int u6 = 0;
		int sdal1 = 0;
		int sdal2 = 0;
		int sdal3 = 0;
		float timer = 0;
		float timer2 = 0;
		int timer3 = 0;
		int r = 1;
		int count = 0;
		bool l = true;
		Font font;
		font.loadFromFile("arial.ttf");
		Text timeg;
		Text points;
		Text text1;
		timeg.setFont(font);
		points.setFont(font);
		text1.setFont(font);
		char buffer1[20];
		char buffer2[20];
		std::string outime = "";
		std::string oupoints = "";
		std::string ouex = "Points:        Time:";
		text1.setString(ouex);
		timeg.setCharacterSize(100);
		points.setCharacterSize(100);
		text1.setCharacterSize(70);
		timeg.setPosition(800, 0);
		points.setPosition(480, 0);
		text1.setPosition(250, 20);
		timeg.setColor(Color::Black);
		points.setColor(Color::Black);
		text1.setColor(Color::Black);

		while (window.isOpen())
		{
			int time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;
			Event event;
			Vector2i pos = Mouse::getPosition(window);
			while (window.pollEvent(event))
			{
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.key.code == Mouse::Left)
						if (T1.sptarget.getGlobalBounds().contains(pos.x, pos.y))
						{
							count++;
							sdal1++;
							T1.sptarget.setPosition(1500, 1500);
						}
					if (T2.sptarget.getGlobalBounds().contains(pos.x, pos.y))
					{
						count += 2;
						sdal2++;
						T2.sptarget.setPosition(1500, 1500);
					}
					if (T3.sptarget.getGlobalBounds().contains(pos.x, pos.y))
					{
						count++;
						sdal3++;
						T3.sptarget.setPosition(1500, 1500);
					}
					if (T4.sptarget.getGlobalBounds().contains(pos.x, pos.y))
					{
						count -= 2;
						T4.sptarget.setPosition(1500, 1500);
					}
					if (T5.sptarget.getGlobalBounds().contains(pos.x, pos.y))
					{
						count -= 2;
						T5.sptarget.setPosition(1500, 1500);
					}
					if (T6.sptarget.getGlobalBounds().contains(pos.x, pos.y))
					{
						count -= 2;
						T6.sptarget.setPosition(1500, 1500);
						
					}
				}
				if (event.type == Event::Closed)
					window.close();
			}
			if (l) {
		    	timer += time;
				timer3 += time;
				timer2 = timer3 / 1000;
			}

			if (timer > 3000) {
				t1 = 1 + rand() % 3;
				u1 = 1 + rand() % 4;
				do {
					t2 = 1 + rand() % 3;
					u2 = 1 + rand() % 4;
				} while (t1 == t2&&u1 == u2);
				do {
					t3 = 1 + rand() % 3;
					u3 = 1 + rand() % 4;
				} while ((t1 == t3&&u1 == u3) || (t3 == t2&&u3 == u2));
				t4 = 1 + rand() % 3;
				u4 = 1 + rand() % 4;
				t5 = 1 + rand() % 3;
				u5 = 1 + rand() % 4;
				t6 = 1 + rand() % 3;
				u6 = 1 + rand() % 4;
				T1.Game1(t1, u1, r);
				T2.Game1(t2, u2, r);
				T3.Game1(t2, u3, r);
				T4.Game1(t4, u4, r);
				T5.Game1(t5, u5, r);
				T6.Game1(t6, u6, r);
				if (r == 1) {
					r = 0;
				}
				else { r = 1; }
				timer = 0;
			}
			if (sdal1 > 3) {
				KIU.sPH.setTextureRect(IntRect(0, 150, 150, 150));
			}
			if (sdal2 > 3) {
				BUV.sPH.setTextureRect(IntRect(0, 150, 150, 150));
			}
			if (sdal3 > 3) {
				DMM.sPH.setTextureRect(IntRect(0, 150, 150, 150));
			}
			_itoa(timer2, buffer1, 10);
			_itoa(count, buffer2, 10);
			outime = buffer1;
			oupoints = buffer2;
			timeg.setString(outime);
			points.setString(oupoints);
			T1.sptarget.rotate(0.5);
			T2.sptarget.rotate(0.5);
			T3.sptarget.rotate(0.5);
			T4.sptarget.rotate(0.5);
			T5.sptarget.rotate(0.5);
			T6.sptarget.rotate(0.5);
			window.clear();
			window.draw(spBG);
			window.draw(T1.sptarget);
			window.draw(T2.sptarget);
			window.draw(T3.sptarget);
			window.draw(T4.sptarget);
			window.draw(T5.sptarget);
			window.draw(T6.sptarget);
			window.draw(DMM.sPH);
			window.draw(KIU.sPH);
			window.draw(BUV.sPH);
			window.draw(timeg);
			window.draw(points);
			window.draw(text1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { timer2 = 35; count = 0;}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { timer2 = 35; count = 21;}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { timer2 = 35; count = 19;}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { timer2 = 35; count = 14;}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { timer2 = 35; count = 9;}
			if (timer2 == 35) {
				l = false;
				if (count <= 5) {
					Final.sPH.setTextureRect(IntRect(0, 1460, 640, 340));
					window.draw(Final.sPH);
				}
						else if (count >20) {
							Final.sPH.setTextureRect(IntRect(0, 0, 640, 360));
							window.draw(Final.sPH);
						}
						else if (count > 15) {
							Final.sPH.setTextureRect(IntRect(0, 360, 640, 360));
							window.draw(Final.sPH);
						}
						else if (count >10) {
							Final.sPH.setTextureRect(IntRect(0, 720, 640, 360));
							window.draw(Final.sPH);
						}
						else {
							Final.sPH.setTextureRect(IntRect(0, 1080, 640, 360));
							window.draw(Final.sPH);
						}
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) { return true; }
			window.display();
		}
	
	}
	void gameRunning() {
		if (game()) { gameRunning();}
	}
	int main() {
		gameRunning();
		return 0;
	}