#include "ObjetoMovil.h"
#include "../../lib/glut.h"

ObjetoMovil::ObjetoMovil()
{
}


ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::SetColor(unsigned char R, unsigned char G, unsigned char B)
{
	rojo = R;
	verde = G;
	azul = B;
}

void ObjetoMovil::SetPos(float x1, float y1)
{
	posicion.x = x1;
	posicion.y = y1;
}

void ObjetoMovil::SetVel(Vector2D vel)
{
	velocidad.x = vel.x;
	velocidad.y = vel.y;
}

Vector2D ObjetoMovil::GetPos()
{
	return posicion;
}

Vector2D ObjetoMovil::GetVel()
{
	return velocidad;
}

int ObjetoMovil::GetRed()
{
	return rojo;
}

int ObjetoMovil::GetVer()
{
	return verde;
}

int ObjetoMovil::GetAzu()
{
	return azul;
}
