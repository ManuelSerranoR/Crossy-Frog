#ifndef _TRONCO_H
#define _TRONCO_H

#include "../../lib/glut.h"
#include "ObjetoMovil.h"
class Tronco :
	public ObjetoMovil
{
public:
	friend class Mundo;
	Tronco(float x, float y, Vector2D vector_vel, unsigned char roj, unsigned char ver, unsigned char azu);
	//a“ado constructor de copia polim€rfico... p∑gina 151 Hernando / Arroyo
	virtual Tronco* Clonar(){ return new Tronco(*this); }

	~Tronco();
	virtual void Dibuja();
	void Mueve(float t);
	bool SentidoVel(Tronco *tronco);
	Tronco& operator=(const Tronco& c);
	float Get_Longitud();

protected:
	float longitud = 1.7;
};

#endif