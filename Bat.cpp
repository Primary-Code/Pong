 #include "Bat.h"

// This the constructor and it is called when we create an object
Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;
	
	m_Shape.setSize(sf::Vector2f(m_shapeX, m_shapeY));
	m_Shape.setPosition(m_Position);
}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::setShape(int X)
{
	m_Shape.setSize(Vector2f(X, Bat::getBat_shapeY()));
	setBat_shapeX(X);
}

int Bat::getBat_shapeX()
{
	return m_shapeX;
}

int Bat::getBat_shapeY()
{
	return m_shapeY;
}

void Bat::setBat_shapeX(int shapeX)
{
	m_shapeX = shapeX;
}

void Bat::setBat_shapeY(int shapeY)
{
	m_shapeY = shapeY;
}

void Bat::moveLeft()
{
	m_MovingLeft = true;

}

void Bat::moveRight()
{
	m_MovingRight = true;
}

void Bat::stopLeft()
{
	m_MovingLeft = false;

}

void Bat::stopRight()
{
	m_MovingRight = false;
}

void Bat::update(Time dt)
{
	if (m_MovingLeft) 
		if(m_Position.x > 0)
			m_Position.x -= m_Speed * dt.asSeconds();
	
	if (m_MovingRight)
		if (m_Position.x + getBat_shapeX() < 1920) // 默认屏幕长度为1920
			m_Position.x += m_Speed * dt.asSeconds();

	m_Shape.setPosition(m_Position);
}
