#ifndef _OBJETOMOVIL_H
#define _OBJETOMOVIL_H

#include "../comun/Vector2D.h"

class ObjetoMovil
{
	friend class Interaccion;
public:
	ObjetoMovil();
	~ObjetoMovil();
	virtual void SetColor(unsigned char R, unsigned char G, unsigned char B);
	virtual void SetPos(float x1, float y1);
	virtual void SetVel(Vector2D vel);
	virtual Vector2D GetVel();
	virtual Vector2D GetPos();
	virtual int GetRed();
	virtual int GetVer();
	virtual int GetAzu();
	virtual float Get_Longitud() = 0;

	//Estos serian unos parametros que definirian a un coche como un prisma simple.
	//Habra que cambiarlo cuando se quiera hacer el coche mejor.
	float alto, ancho, largo;
protected:

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	//Parámetros intrínsecos del objeto movil
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};

#endif