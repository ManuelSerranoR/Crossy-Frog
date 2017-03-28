#include "Mundo.h"
#include "../Comun/OpenGL.h"
#pragma once
	

class CoordinadorFrog
{
public:
	Mundo mundo;
	CoordinadorFrog();
	virtual ~CoordinadorFrog();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();

protected:
	enum Estado{INICIO, JUEGO, GAME_OVER, YOU_WIN, INSTRUCCIONES};
	Estado estado;
};

