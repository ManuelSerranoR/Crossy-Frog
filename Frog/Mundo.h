#ifndef _MUNDO_H
#define _MUNDO_H

#include "../../lib/glut.h"
 #include "../dominio/Plataforma.h"
 #include "../dominio/Rana.h"
 #include "../dominio/Coche.h"
 #include "../Dominio/Interaccion.h"
 #include "../Dominio/Tronco.h"
 #include "../Dominio/ListaCoches.h"
 #include "../Dominio/ListaTroncos.h"
 #include "../Dominio/Bicicleta.h"
 #include "../Dominio/Nenufar.h"
 #include <math.h>

class Mundo
{
	private: //Atributos
		float x_ojo;
		float y_ojo;
		float z_ojo;
		float x_vista;
		float y_vista;
		float z_vista;
		
			float theta = atan2(z_vista, x_vista);
		
				//Declarar los objetos de la clase Esfera que se vayan a utilizar en el programa. 
				//Esto es debido a que la clase Mundo es quien debe saber que cosas se van a pintar y que cosas no.
				//Por lo tanto, lo l€gico es que las esferas pertenezcan a la clase Mundo.
		Plataforma plataforma;
		Rana rana;
		ListaTroncos troncos;
		ListaCoches coches;
		
			public: //M»todos
				Mundo(); //Constructor
				
						//Getters
					float GetPos_x_ojo();
				float GetPos_y_ojo();
				float GetPos_z_ojo();
				
						//Setters
					void SetPos_ojo(Mundo* m);
				
						//Otros
					void Inicializa();
				void Dibuja();
				void Mover();
				void Tecla(unsigned char key);
				void TeclaEspecial(unsigned char key);
				void Vista(Mundo* mundo);
				bool Perder();
				bool Ganar();
				bool camara;
				bool vista_izq;
				bool vista_dch;
				bool CargarTexturas();
				
					};

#endif