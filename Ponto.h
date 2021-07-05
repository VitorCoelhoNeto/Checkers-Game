#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ponto {
private:
	int x, y;

public:
	Ponto();

	Ponto(int m_x, int m_y);
	~Ponto();

	inline void Set_x(int m_x) {
		this->x = m_x;
	}
	inline void Set_y(int m_y) {
		this->y = m_y;
	}
	inline void Set_P(int m_x, int m_y) {
		this->x = m_x;
		this->y = m_y;
	}
	inline void Set_P(Ponto m_P) {
		this->x = m_P.x;
		this->y = m_P.y;
	}
	inline int Get_x(void) const { return x; }
	inline int Get_y(void) const { return y; }

	bool operator == (const Ponto ponto)const;
};