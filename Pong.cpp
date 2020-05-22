#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


int main()
{
	
	int Difficulty = 15; // you'd better enter a num between 10-20;

	char cheats[4] = { 'k','e','y', '\0' };; // 最后一位要设置为'\0'，否则会出现乱码
	char inputchar[4]; inputchar[3] = '\0';
	int i = 0;
	
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Pong", Style::Fullscreen);
	
	int score = 0;

	// Create a bat
	Bat bat(1920 / 2, 1080 - 20);
	Ball ball(1920 / 2, 0);

	// Create a Text object calle d HUD
	Text hud;
	Font font;
	font.loadFromFile("fonts/DS-DIGI.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);

	// Prepare the sound when the bat hits the ball.
	SoundBuffer BattingBuffer;
	Sound batting;
	BattingBuffer.loadFromFile("sound/ball.wav");
	batting.setBuffer(BattingBuffer);
	
	// Here is our clock for timing everything
	Clock clock;
	bool pause = true;

	while (window.isOpen())
	{
		/*
		Handle the player input
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			if (event.type == Event::Closed)
				window.close();

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					if (i < 3)
					{
						std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
						inputchar[i] = event.text.unicode;
						i++;
					}else
					{
						inputchar[0] = event.text.unicode;
						inputchar[1] = '\0';
						inputchar[2] = '\0';
						i = 1;
					}
				}

				for (int j = 0; j < i; j++)
					std::cout << inputchar[j]; // 测试输入，待删除
				std::cout << std::endl;

				if (strcmp(cheats, inputchar) == 0)
				{
					std::cout << "Hello World!" << std::endl; // 作弊内容
					if(bat.getBat_shapeX() < 300)
						bat.setShape(bat.getBat_shapeX() + 20);
				}
			}
		}

		// 只检查鼠标的位置以及是否按下特定的按钮或键，适合处理玩家的动作。
		/*
		//Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			pause = false;
		}
		*/
		
		// Handle the pressing and releasing of the arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		/*
		Update the bat, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		// Update the delta time
		Time dt = clock.restart(); // 获取游戏帧之间的事件间隔
		bat.update(dt);
		ball.updatePosotion(dt);
		// Update the HUD text
		std::stringstream ss; // 用于维护一个字符串缓冲区并允许修改这个缓冲区的字符串内容
		ss << "Score:" << score << "    Lives:" << ball.getLives() << "    XSpeed:" << ball.getXVelocity();
		hud.setString(ss.str());

		// Handle ball hitting the bottom
		if (ball.getPosition().top > window.getSize().y)
		{
			// reverse the ball direction
			ball.reboundBat();

			// Remove a life
			ball.setLives((ball.getLives()) - 1);

			// Check for zero lives
			if (ball.getLives() < 1) {
				// reset the score
				score = 0;
				// reset the lives
				ball.setLives(3);

				// bat.setBall_shapeX(200);
				bat.setShape(200);
				ball.setXVelocity(300);
				ball.setYVelocity(400);
			}

		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundTop();

			if (bat.getBat_shapeX() > 50)
			{
				if (bat.getBat_shapeX() > 120)
				{ 
					bat.setShape(bat.getBat_shapeX() - Difficulty);
				}
				else if (ball.getXVelocity() < 800)
				{
					ball.setXVelocity(ball.getXVelocity() + Difficulty * 5);
					ball.setYVelocity(ball.getYVelocity() + Difficulty * 5);
				}
				else
				{
					bat.setShape(bat.getBat_shapeX() - Difficulty);
				}
			}

			score++;
		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0)
		{
			ball.reboundLeftSides();
		}

		if (ball.getPosition().left + 10 > window.getSize().x)  // 球的大小为10像素
		{
			ball.reboundRightSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			// Hit detected so reverse the ball and score a point
			ball.reboundBat();
			batting.play();
		}
		/*
		Draw the bat, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}
	
	
	return 0;
}

