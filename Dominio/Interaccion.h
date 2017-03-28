#ifndef _INTERACCION_H
#define _INTERACCION_H

#include "../../lib/glut.h"
#include "Rana.h"
#include "Plataforma.h"
#include "Coche.h"
#include "Tronco.h"

class Interaccion
{
	bool uno = false;
	bool dos = false;
	bool tres = false;
	bool cuatro = false;
	bool cinco = false;
public:
	Interaccion();
	virtual ~Interaccion();
	static bool Rebote(Rana &h, Plataforma p, Tronco tronco);
	static bool Destruccion_Vel_Pos(Coche &c, Plataforma caja);
	static bool Destruccion_Vel_Neg(Coche &c, Plataforma caja);
	static bool Destruccion_Vel_Pos(Tronco &c, Plataforma caja);
	static bool Destruccion_Vel_Neg(Tronco &c, Plataforma caja);
	static bool Rebote(Rana &r, Coche c);
	static bool Rebote(Rana &h, Plataforma p, bool &izq, bool &dch, bool &atr, bool &rec);
	static bool Llegada(Rana &h, Plataforma p, bool &rec);
	//void LlegadaDibuja(Rana &a);
};

#endif
