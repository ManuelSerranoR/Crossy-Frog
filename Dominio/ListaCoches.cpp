#include "ListaCoches.h"


ListaCoches::ListaCoches()
{
	// Inicializamos todo a cero (tanto el contador como cada elemento del vector)
	numero = 0;
	for (int i = 0; i < MAX_COCHES; i++)
		lista[i] = 0;
}


ListaCoches::~ListaCoches()
{
}

// Definimos ahora la funcion Agregar, que lo que hace es devolver true si se agrega el coche, o false si no.
// Esta función, tambien se encarga de se almacene la direccion en el ultimo puesto del vector sin rellenar, 
// verificando que no se ha superado su capacidad maxima.
bool ListaCoches::Agregar(Coche *c)
{
	if (numero < MAX_COCHES)
		lista[numero++] = c;
	else
		return false;
	return true;
}

// Esta funcion agrupa todas las funciones Dibuja de todos los coches, de forma que queda mas compacto
void ListaCoches::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

// Esta funcion agrupa todas las funciones Mueve de todos los coches, de forma que queda mas compacto
void ListaCoches::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaCoches::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaCoches::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaCoches::Eliminar(Coche *c)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == c)
		{
			Eliminar(i);
			return;
		}
}

Coche *ListaCoches::Destruccion(Plataforma caja)
{
	for (int i = 0; i < numero; i++)
	{
		Coche *aux = lista[i];
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

Coche *ListaCoches::Colision(Rana rana)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::Rebote(rana, *(lista[i])))
			return lista[i];
	}
	return 0;
}