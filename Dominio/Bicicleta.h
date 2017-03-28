#ifndef _BICICLETA_H
#define _BICICLETA_H

#include "Coche.h"
#include <math.h>
#include <cstdlib>

class Bicicleta : public Coche
{
	friend class Interaccion;

public:
	Bicicleta(float l, float x, float y, Vector2D vector_vel, unsigned char roj, unsigned char ver, unsigned char azu, float anc, float al) :Coche(l, x, y, vector_vel, roj, ver, azu)
	{
		ancho = anc;
		altura = al;
	}

	Bicicleta& operator=(const Bicicleta& b);

	void Dibuja();
	void Mueve(float t);
	bool SentidoVel(Bicicleta *bici);

	~Bicicleta();
};

#endif