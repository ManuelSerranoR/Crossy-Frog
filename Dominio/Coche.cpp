#include "Coche.h"
#include "../../lib/glut.h"


Coche::Coche()
{
}

Coche::Coche(float l, float x, float y, Vector2D vector_vel, unsigned char roj, unsigned char ver, unsigned char azu)
{
	longitud = l;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vector_vel.x;
	velocidad.y = vector_vel.y;
	rojo = roj;
	verde = ver;
	azul = azu;
}

Coche::~Coche()
{
}

void Coche::Dibuja()
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

void Coche::Mueve(float t)
{
	// Ecuacion de movimiento NO acelerado para los coches
	// Se podrÌa hacer que las motos si tengan aceleracion y los coches no, por ejemplo
	posicion = posicion + velocidad*t + aceleracion*(0.5f*t*t);
	velocidad = velocidad + aceleracion*t;
}

bool Coche::SentidoVel(Coche *coche)
{
	if (velocidad.x > 0)
		return true;
	return false;
}

Coche::Coche(const Coche &c)
{
	*this = c;
}

Coche& Coche::operator=(const Coche& c)
{
	longitud = c.longitud;
	posicion.x = c.posicion.x;
	posicion.y = c.posicion.y;
	velocidad = c.velocidad;
	rojo = c.rojo;
	verde = c.verde;
	azul = c.azul;
	return *this;
}

float Coche::Get_Longitud(){
	return longitud;
}