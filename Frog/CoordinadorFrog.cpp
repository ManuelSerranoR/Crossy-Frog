#include "CoordinadorFrog.h"
#include<stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>          /* Open GL Util    APPLE */
#else
#include "../../lib/glut.h"
#include "../Comun/OpenGL.h"

#endif


CoordinadorFrog::CoordinadorFrog()
{
	estado = INICIO;
	PlaySound(TEXT("Inicio.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}


CoordinadorFrog::~CoordinadorFrog()
{
	OpenGL::BorraTexturas();
}

void CoordinadorFrog::Dibuja()
{
	if (estado == INICIO){
		OpenGL::Print("****** FROG ******", 320, 10, 255, 0, 0);
		OpenGL::Print("by MANUEL & IGNACIO", 300, 40, 155, 0, 255);
		OpenGL::Print("Pulse E para empezar o S para salir...", 250, 70, 5, 255, 255);

		OpenGL::Print("Pulse I para las instrucciones...", 270, 100, 5, 0, 255);
		// Todo este código de abajo dibuja las letras iniciales de la pantalla inicial
		glLoadIdentity();
		glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 500.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glScalef(.005, .005, .005);
		glRotatef(20, 0, 1, 0);
		glRotatef(30, 0, 0, 1);
		glRotatef(5, 1, 0, 0);
		glTranslatef(-300, 0, 0);

		glColor3f(0, 255, 0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '-');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'F');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'R');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'O');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'G');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '-');

		glutSwapBuffers();
	}
	else if (estado == JUEGO)
		mundo.Dibuja();

	else if (estado == GAME_OVER){
		OpenGL::Print("MAYBE NEXT TIME", 320, 10, 255, 0, 0);
		OpenGL::Print("Pulse E para volver a jugar o S para salir...", 250, 40, 155, 0, 255);

		// Todo este código de abajo dibuja las letras iniciales de la pantalla inicial
		glLoadIdentity();
		glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 500.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glScalef(.005, .004, .001);
		glRotatef(20, 0, 1, 0);
		glRotatef(30, 0, 0, 1);
		glRotatef(5, 1, 0, 0);
		glTranslatef(-300, 0, 0);

		glColor3f(0, 255, 0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'G');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'A');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'M');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');

		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'O');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'V');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'R');

	}

	else if (estado == YOU_WIN){
		OpenGL::Print("YOU MADE IT!", 320, 10, 255, 0, 0);
		OpenGL::Print("Pulse E para volver a jugar o S para salir...", 250, 40, 155, 0, 255);
		// Todo este código de abajo dibuja las letras iniciales de la pantalla inicial

		glLoadIdentity();
		glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 500.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glScalef(.005, .004, .001);
		glRotatef(20, 0, 1, 0);
		glRotatef(30, 0, 0, 1);
		glRotatef(5, 1, 0, 0);
		glTranslatef(-300, 0, 0);

		glColor3f(0, 255, 0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'Y');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'O');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'U');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, ' ');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'W');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'i');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'N');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '!');

	}

	else if (estado == INSTRUCCIONES){
		OpenGL::Print("INSTRUCCIONES", 320, 10, 255, 0, 0);
		OpenGL::Print("Pulse 1 para vista 3D", 220, 80, 155, 0, 255);
		OpenGL::Print("Pulse 2 para vista 2D", 220, 110, 155, 0, 255);
		OpenGL::Print("Pusle 3 para vista en tercera persona", 220, 140, 155, 0, 255);
		OpenGL::Print("Utilice las flechas del teclado para el movimiento de la rana", 220, 170, 155, 0, 255);
		OpenGL::Print("Pulse E para volver a jugar o S para salir...", 220, 300, 155, 255, 255);
	}
}

void CoordinadorFrog::Mueve(){
	if (estado == JUEGO){
		mundo.Mover();
		if (mundo.Perder()){
			PlaySound(TEXT("GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			estado = GAME_OVER;
		}
		if (mundo.Ganar()){
			PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			estado = YOU_WIN;
		}
	}
}

void CoordinadorFrog::Tecla(unsigned char key){
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			mundo.Inicializa();
			PlaySound(TEXT("Juego.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);

		if (key == 'i')
			estado = INSTRUCCIONES;
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		if (key == 's')
			exit(0);
	}
	else if (estado == GAME_OVER)
	{
		if (key == 'e') estado = INICIO;
		if (key == 's')
			exit(0);
	}
	else if (estado == YOU_WIN)
	{
		if (key == 'e') { estado = INICIO; }
		if (key == 's')
			exit(0);
	}
	else if (estado == INSTRUCCIONES)
	{
		if (key == 'e') { estado = INICIO; }
		if (key == 's')
			exit(0);
	}
}


void CoordinadorFrog::TeclaEspecial(unsigned char key){
	if (estado == JUEGO)
		mundo.TeclaEspecial(key);
}


