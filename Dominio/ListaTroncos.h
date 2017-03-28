#ifndef _LISTATRONCOS_H
#define _LISTATRONCOS_H

#define MAX_TRONCOS 100

#include "Tronco.h"
#include "Interaccion.h"

class ListaTroncos
{
public:
	ListaTroncos();
	~ListaTroncos();

	bool Agregar(Tronco *t);
	void Dibuja();
	void Mueve(float t);
	Tronco *Rebote(Plataforma caja, Rana rana);

	//Para eliminar los coches al llegar al final de la carretera
	void Eliminar(int index);
	void Eliminar(Tronco *c);
	void DestruirContenido();
	Tronco *Destruccion(Plataforma caja);
private:
	// Vector de punteros a objeto tipo Coche, capaz de almacenar 100 punteros
	Tronco * lista[MAX_TRONCOS];
	// Atributo que lleva la cuenta de las esferas que llevamos almacenadas
	int numero;
};

#endif
