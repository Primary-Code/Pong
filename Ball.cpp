#include "Ball.h"

// This the constructor function
Ball::Ball(float startX, float startY)
{
	mPosition.x = startX;
	mPosition.y = startY;

	mShape.setSize(sf::Vector2f(mShapeX, mShapeY));
	mShape.setPosition(mPosition);
	mShape.setFillColor(sf::Color::White);
}

int Ball::getmShapeX()
{
	return mShapeX;
}

void Ball::setShapeX(int shapeX)
{
	mShapeX = shapeX;
}

int Ball::getmShapeY()
{
	return mShapeY;
}

void Ball::setShapeY(int shapeY)
{
	mShapeY = shapeY;
}

FloatRect Ball::getPosition()
{
	return mShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return mShape;
}

int Ball::getLives()
{
	return lives;
}

void Ball::setLives(int num)
{
	lives = num;
}

float Ball::getXVelocity()
{
	return mSpeedX;
}

void Ball::setXVelocity(float speedX)
{
	mSpeedX = speedX;
}

float Ball::getYVelocity()
{
	return mSpeedY;
}

void Ball::setYVelocity(float speedY)
{
	mSpeedY = speedY;
}

void setYVelocity(float speedY);

void Ball::reboundLeftSides()
{
	mDirectionX = 1;
	mShape.setFillColor(sf::Color::Red);
}

void Ball::reboundRightSides()
{
	mDirectionX = -1;
	mShape.setFillColor(sf::Color::Red);
}

void Ball::reboundBat()
{
	mDirectionY = -1;
	mShape.setFillColor(sf::Color::White);
}

void Ball::reboundTop()
{
	mDirectionY = 1;
	mShape.setFillColor(sf::Color::Blue);
}

void Ball::updatePosotion(sf::Time dt)
{
	if (getLives() < 0)
		return;
	
	mPosition.x += mDirectionX * mSpeedX * dt.asSeconds();
	mPosition.y += mDirectionY * mSpeedY * dt.asSeconds();
	
	mShape.setPosition(mPosition);
}