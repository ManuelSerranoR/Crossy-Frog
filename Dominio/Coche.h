#ifndef _COCHE_H
#define _COCHE_H

#include "ObjetoMovil.h"

class Coche :
	public ObjetoMovil
{
	friend class Interaccion;
	//Amiga de Mundo tambien para que mundo pueda acceder al parametro longitud, que no pertenece a ObjetoMovil.
	friend class Mundo;

public:
	Coche();

	// Sobrecarga de Coche. Lo dejo comentado porque aun no tengo claro para que utilizarlo.
	// Antes de utilizarlo, cambiar el metodo SetVel que recoja dos float en vez de un Vector2D.

	Coche(float l, float x, float y, Vector2D vector_vel, unsigned char roj, unsigned char ver, unsigned char azu);
	Coche(const Coche &c);
	//a“ado constructor de copia polim€rfico... p∑gina 151 Hernando / Arroyo
	virtual Coche* Clonar(){ return new Coche(*this); }

	~Coche();
	virtual void Dibuja();
	virtual void Mueve(float t);
	virtual bool SentidoVel(Coche *coche);
	float Get_Longitud();
	Coche& operator=(const Coche& c);

protected:
	float longitud;
	float ancho = 0.8;
	float altura = 1;
};

#endif