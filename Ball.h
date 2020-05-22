#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f mPosition;	
	RectangleShape mShape;

	int mShapeX = 10;
	int mShapeY = 10;

	float mSpeed = 500.0f; // �ٶ�
	float mSpeedX = 300.2f; // x�����ٶ�
	float mSpeedY = 400.2f; // y�����ٶ�

	int mDirectionX = 1; // x���򴥱ڷ���ָʾ����
	int mDirectionY = 1; // y���򴥱ڷ���ָʾ����

	int lives = 3;


public:
	Ball(float startX, float startY);

	FloatRect getPosition();
	RectangleShape getShape();

	int getmShapeX();
	int getmShapeY();
	void setShapeX(int shapeX);
	void setShapeY(int shapeY);
	
	int getLives();
	void setLives(int num);

	float getXVelocity();
	float getYVelocity();
	void setXVelocity(float speedX);
	void setYVelocity(float speedY);

	void reboundLeftSides();
	void reboundRightSides();
	void reboundBat();
	void reboundTop();

	void updatePosotion(sf::Time dt);

};
