#include "Ponto.h"



Ponto::Ponto()
{
}


Ponto::Ponto(int m_x, int m_y)
{
	this->x = m_x;
	this->y = m_y;
}

Ponto::~Ponto()
{
}

bool Ponto::operator==(const Ponto ponto) const
{
	if (x == ponto.x && y == ponto.y)
	{
		return true;
	}
	else
		return false;
}
