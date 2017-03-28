#include "Bicicleta.h"

Bicicleta::~Bicicleta()
{
}

void Bicicleta::Mueve(float t)
{
	Coche::Mueve(t);
	//aceleracion.x = 2;
}

void Bicicleta::Dibuja()
{
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0.0f);
	//PARA DIBUJAR UN RECT¡NGULO
	glScalef(longitud, ancho, altura);//longitud, ancho y altura
	glutSolidCube(1);
	glPopMatrix();
	glEnd();
}

bool Bicicleta::SentidoVel(Bicicleta *bici)
{
	if (velocidad.x > 0)
		return true;
	return false;
}

Bicicleta& Bicicleta::operator=(const Bicicleta& b)
{
	Coche::operator=(b);
	ancho = b.ancho;
	altura = b.altura;
	return *this;
}