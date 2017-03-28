#ifndef _RANA_H
#define _RANA_H

#include "../../lib/glut.h"
#include "../comun/Vector2D.h"
# define M_PI           3.14159265358979323846  /* pi */

class Rana
{
	friend class Interaccion;
private:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Vector2D origen;
	float altura;
	float velocidad_z;
	float velocidad_z_inicial;
	float alpha = 60*M_PI/ 180;
	float gravedad = 10;
	int vidas;

public:
	Rana();
	virtual ~Rana();
	void Dibuja();
	void Mueve(float t);
	void SetPos(float px, float py);
	void SetVel(Vector2D vel);
	float GetAltura(){ return altura; }
	int GetVidas(){ return vidas; }
	void SetVidas(){ vidas = 4; }
	void DecrementoVida(int vida);
	void DibujaVida();
	Vector2D GetPos();
	Vector2D mov_izq(Vector2D posicion);
	Vector2D mov_dch(Vector2D posicion);
	Vector2D mov_rec(Vector2D posicion);
	Vector2D mov_atr(Vector2D posicion);

	float velocidad_inicial=0;
	float z = 0;
	bool salto;
};

#endif