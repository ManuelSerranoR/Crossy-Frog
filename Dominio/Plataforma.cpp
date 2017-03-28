#include "Plataforma.h"

Plataforma::Plataforma()
{
	//El constructor inicializa todos los colores y posiciones iniciales de todos los planos
	// SetPos toma como atributos las coordenadas x e y de los 4 puntos que conforman un plano,
	// en el primer caso, la acera
	acera1.SetPos(0, -20, 0, 1, 15, 1, 15, -20);
	acera1.SetColor(0, 255, 0);

	acera2.SetPos(0, 5, 0, 6, 15, 6, 15, 5);
	acera2.SetColor(15, 100, 25);

	carretera1.SetPos(0, 1, 0, 5, 15, 5, 15, 1);
	carretera1.SetColor(152, 152, 152);

	rio.SetPos(0, 6, -0.5, 0, 9, -0.5, 15, 9, -0.5, 15, 6, -0.5);
	rio.SetColor(0, 0, 255);

	pared_rio.SetPos(0, 9, -0.5, 0, 9, 0, 15, 9, 0, 15, 9, -0.5);
	pared_rio.SetColor(0, 150, 0);

	//Todo esto de abajo son las posiciones de los cuadrados del final del mapa
	piedra1.SetPos(0, 9, 0, 10, 1, 10, 1, 9);
	piedra1.SetColor(100, 100, 100);

	piedra2.SetPos(2, 9, 2, 10, 4, 10, 4, 9);
	piedra2.SetColor(100, 100, 100);

	piedra3.SetPos(5, 9, 5, 10, 7, 10, 7, 9);
	piedra3.SetColor(100, 100, 100);

	piedra4.SetPos(8, 9, 8, 10, 10, 10, 10, 9);
	piedra4.SetColor(100, 100, 100);

	piedra5.SetPos(11, 9, 11, 10, 13, 10, 13, 9);
	piedra5.SetColor(100, 100, 100);

	piedra6.SetPos(14, 9, 14, 10, 15, 10, 15, 9);
	piedra6.SetColor(100, 100, 100);

	hueco1.SetPos(1, 9, 1, 10, 2, 10, 2, 9);
	hueco1.SetColor(30, 200, 30);

	hueco2.SetPos(4, 9, 4, 10, 5, 10, 5, 9);
	hueco2.SetColor(30, 200, 30);

	hueco3.SetPos(7, 9, 7, 10, 8, 10, 8, 9);
	hueco3.SetColor(30, 200, 30);

	hueco4.SetPos(10, 9, 10, 10, 11, 10, 11, 9);
	hueco4.SetColor(30, 200, 30);

	hueco5.SetPos(13, 9, 13, 10, 14, 10, 14, 9);
	hueco5.SetColor(30, 200, 30);

	cielo_izquierda.SetPos(0, -20, -5, 0, -20, 50, 0, 10, 50, 0, 10, -5);
	cielo_izquierda.SetColor(0, 255, 255);

	cielo_derecha.SetPos(15, -20, -5, 15, -20, 50, 15, 10, 50, 15, 10, -5);
	cielo_derecha.SetColor(0, 255, 255);

	cielo_fondo.SetPos(0, 10, -5, 0, 10, 50, 30, 10, 50, 30, 10, -5);
	cielo_fondo.SetColor(0, 180, 255);
}


Plataforma::~Plataforma()
{
}


void Plataforma::Dibuja()
{
	acera1.Dibuja();
	acera2.Dibuja();
	carretera1.Dibuja();
	rio.Dibuja();
	piedra1.Dibuja();
	piedra2.Dibuja();
	piedra3.Dibuja();
	piedra4.Dibuja();
	piedra5.Dibuja();
	piedra6.Dibuja();
	hueco1.Dibuja();
	hueco2.Dibuja();
	hueco3.Dibuja();
	hueco4.Dibuja();
	hueco5.Dibuja();
	cielo_derecha.Dibuja();
	cielo_izquierda.Dibuja();
	cielo_fondo.Dibuja();
	pared_rio.Dibuja();
}
