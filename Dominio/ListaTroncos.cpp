#include "ListaTroncos.h"

ListaTroncos::ListaTroncos()
{
	// Inicializamos todo a cero (tanto el contador como cada elemento del vector)
	numero = 0;
	for (int i = 0; i < MAX_TRONCOS; i++)
		lista[i] = 0;
}

ListaTroncos::~ListaTroncos()
{
}

// Definimos ahora la funcion Agregar, que lo que hace es devolver true si se agrega el coche, o false si no.
// Esta función, tambien se encarga de se almacene la direccion en el ultimo puesto del vector sin rellenar, 
// verificando que no se ha superado su capacidad maxima.
bool ListaTroncos::Agregar(Tronco *c)
{
	if (numero < MAX_TRONCOS)
		lista[numero++] = c;
	else
		return false;
	return true;
}

// Esta funcion agrupa todas las funciones Dibuja de todos los troncos, de forma que queda mas compacto
void ListaTroncos::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

// Esta funcion agrupa todas las funciones Mueve de todos los troncos, de forma que queda mas compacto
void ListaTroncos::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

Tronco *ListaTroncos::Rebote(Plataforma caja, Rana h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::Rebote(h, caja, *(lista[i])))
			return lista[i];
	}
	return 0;
}


void ListaTroncos::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaTroncos::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaTroncos::Eliminar(Tronco *c)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == c)
		{
			Eliminar(i);
			return;
		}
}


Tronco *ListaTroncos::Destruccion(Plataforma caja)
{
	for (int i = 0; i < numero; i++)
	{
		Tronco *aux = lista[i];
		if (aux->GetVel().x > 0)
		{
			if (Interaccion::Destruccion_Vel_Pos(*(lista[i]), caja))
			{
				return lista[i];
			}
		}
		else if (aux->GetVel().x<0)
			if (Interaccion::Destruccion_Vel_Neg(*(lista[i]), caja))
			{
				return lista[i];
			}
	}
	return 0;
}

