#ifndef _LISTACOCHES_H
#define _LISTACOCHES_H

#define MAX_COCHES 100

#include "Coche.h"
#include "Interaccion.h"

class ListaCoches
{
public:
	ListaCoches();
	~ListaCoches();

	bool Agregar(Coche *c);
	void Dibuja();
	virtual void Mueve(float t);
	//Para eliminar los coches al llegar al final de la carretera
	void Eliminar(int index);
	void Eliminar(Coche *c);
	void DestruirContenido();
	Coche *Destruccion(Plataforma caja);
	Coche *Colision(Rana rana);
private:
	// Vector de punteros a objeto tipo Coche, capaz de almacenar 100 punteros
	Coche * lista[MAX_COCHES];
	// Atributo que lleva la cuenta de las esferas que llevamos almacenadas
	int numero;
};

#endif