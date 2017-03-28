#include "Rana.h"
using namespace std;
#include <iostream>

Rana:: ~Rana()
{
}

Rana::Rana()
{
	altura = 0.34;
	posicion.x = 7.5f;
	posicion.y = 0.5;
	origen = posicion;
	vidas = 4;
}

void Rana::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, altura/2+z);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();

}

void Rana::Mueve(float t)
{
	//Movimiento uniforme rectilíneo
	posicion = posicion + velocidad*t;
	if (salto == true) //MOVIMIENTO PARABÓLICO PARA EL SALTO DE LA RANA
	{
		//Movimiento uniformemente acelerado en el eje z
		z = velocidad_z_inicial*t - 1/2*gravedad*t*t;
		//Velocidades. Componente z 
		velocidad_z_inicial = velocidad_inicial*sin(alpha);
		//La componente z tiene aceleracion ya que sufre la fuerza de la gravedad
		velocidad_z = velocidad_z_inicial - gravedad*t;
	}
}

void Rana::SetPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}

Vector2D Rana::GetPos()
{
	return posicion;
}

void Rana::SetVel(Vector2D vel)
{
	velocidad = vel;
}

Vector2D Rana::mov_izq(Vector2D pos)
{
	Vector2D Posicion_Rana = pos;
	velocidad_inicial = 8;
	velocidad.x = -velocidad_inicial*cos(alpha);
	salto = true;
	return Posicion_Rana;
}

Vector2D Rana::mov_dch(Vector2D pos)
{
	Vector2D Posicion_Rana = pos;
	velocidad_inicial = 8;
	velocidad.x = velocidad_inicial*cos(alpha);
	salto = true;
	return Posicion_Rana;
}

Vector2D Rana::mov_rec(Vector2D pos)
{
	Vector2D Posicion_Rana = pos;
	velocidad_inicial = 8;
	velocidad.y = velocidad_inicial*cos(alpha);
	salto = true;
	return Posicion_Rana;
}

Vector2D Rana::mov_atr(Vector2D pos)
{
	Vector2D Posicion_Rana = pos;
	velocidad_inicial = 8;
	velocidad.y = -velocidad_inicial*cos(alpha);
	salto = true;
	return Posicion_Rana;
}


void Rana::DibujaVida()
{
	for (int i = 0; i<vidas; i++)
	{
		glPushMatrix();
		glTranslatef(6+0.5*i, 10, 1);
		glColor3f(1.0f, 0.0f, 0.0f);//color de hombre
		glutSolidSphere(altura / 2, 20, 20);
		glPopMatrix();
	}
}

void Rana::DecrementoVida(int vida){
	vidas -= vida;
}