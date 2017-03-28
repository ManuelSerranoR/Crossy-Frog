#ifndef _TERRENO_H
#define _TERRENO_H

#include "../comun/Vector2D.h"
class Terreno
{
public:
	Terreno(void);
	virtual ~Terreno(void);
	void SetColor(unsigned char R, unsigned char G, unsigned char B);
	void SetPos(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void SetPos(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
	void Dibuja();
	friend class Interaccion;
	void SetTextura(char* f);

private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;
	Vector2D limite3;
	Vector2D limite4;
	char tex[255];
};

#endif
