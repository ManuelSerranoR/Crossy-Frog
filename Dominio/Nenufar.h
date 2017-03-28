#ifndef _NENUFAR_H
#define _NENUFAR_H

#include "Tronco.h"

class Nenufar : public Tronco
{
public:
	~Nenufar();
	Nenufar(float x, float y, Vector2D vector_vel, unsigned char roj, unsigned char ver, unsigned char azu, float l) :Tronco(x, y, vector_vel, roj, ver, azu)
	{
		longitud = l;
	}
	Nenufar& operator=(const Nenufar& n);
	virtual void Dibuja();
};

#endif