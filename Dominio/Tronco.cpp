#include "Tronco.h"

Tronco::Tronco(float x, float y, Vector2D vector_vel, unsigned char roj, unsigned char ver, unsigned char azu)
{
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vector_vel.x;
	velocidad.y = vector_vel.y;
	rojo = roj;
	verde = ver;
	azul = azu;
}

Tronco::~Tronco()
{
}

void Tronco::Dibuja()
{
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, -0.5f);
	//PARA DIBUJAR UN RECT¡NGULO
	glScalef(longitud, 0.8, 1);//longitud, ancho y altura
	glutSolidCube(1);
	glPopMatrix();
	glEnd();

}

void Tronco::Mueve(float t)
{
	// Ecuacion de movimiento NO acelerado para los coches
	// Se podrÌa hacer que las motos si tengan aceleracion y los coches no, por ejemplo
	posicion = posicion + velocidad*t;
}

bool Tronco::SentidoVel(Tronco *tronco)
{
	if (velocidad.x > 0)
		return true;
	return false;
}

Tronco& Tronco::operator=(const Tronco& t)
{
	posicion.x = t.posicion.x;
	posicion.y = t.posicion.y;
	velocidad = t.velocidad;
	rojo = t.rojo;
	verde = t.verde;
	azul = t.azul;
	return *this;
}


float Tronco::Get_Longitud(){
	return longitud;
}