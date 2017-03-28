#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include "Terreno.h"

class Plataforma
{
public:
	Plataforma();
	~Plataforma();

	friend class Interaccion;

	Terreno acera1, acera2;
	Terreno carretera1;
	Terreno rio;
	Terreno cielo_derecha, cielo_izquierda, cielo_fondo;
	Terreno pared_rio; //Pared que se ve al fondo al haber bajado el rio.

	// Terreno que hay al final del mapa, siendo piedras donde la 
	// rana no puede pisar, y siendo huecos donde tiene que conseguir llegar	
	Terreno piedra1, piedra2, piedra3, piedra4, piedra5, piedra6;
	Terreno hueco1, hueco2, hueco3, hueco4, hueco5;

	void Dibuja();
};

#endif
