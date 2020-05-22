#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f m_Position;
	// A RectangleShape object
	RectangleShape m_Shape;
	int m_shapeX = 200;
	int m_shapeY = 5;
	
	float m_Speed = 1000.0f;
	bool m_MovingRight = false;
	bool m_MovingLeft = false;

	
public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void setShape(int X);

	int getBat_shapeX();
	int getBat_shapeY();
	void setBat_shapeX(int shapeX);
	void setBat_shapeY(int shapeY);
	
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);
};
