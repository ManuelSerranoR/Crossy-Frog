#include "Terreno.h"
#include "../../lib/glut.h"
#include <iostream>
#include "../Comun/OpenGL.h"

Terreno::Terreno()
{
	tex[0] = 0;
}

Terreno::~Terreno()
{
}

void Terreno::Dibuja()
{
	if (tex[0] == 0)
	{
		glDisable(GL_LIGHTING);
		glColor3ub(rojo, verde, azul);
		glBegin(GL_POLYGON);
		glVertex3d(limite1.x, limite1.y, limite1.z);
		glVertex3d(limite2.x, limite2.y, limite2.z);
		glVertex3d(limite3.x, limite3.y, limite3.z);
		glVertex3d(limite4.x, limite4.y, limite4.z);
		glEnd();
		glEnable(GL_LIGHTING);
	}
	else
	{
		unsigned int textura = OpenGL::CargaTextura(tex);

		if (textura != -1)
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textura);

			glDisable(GL_LIGHTING);

			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
				glTexCoord2d(0, 0);
				glVertex3d(limite1.x, limite1.y, limite1.z);
				glTexCoord2d(1, 0);
				glVertex3d(limite2.x, limite2.y, limite2.z);
				glTexCoord2d(1, 2);
				glVertex3d(limite3.x, limite3.y, limite3.z);
				glTexCoord2d(0, 2);
				glVertex3d(limite4.x, limite4.y, limite4.z);
			glEnd();

			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

		}
	}
}

void Terreno::SetColor(unsigned char R, unsigned char G, unsigned char B)
{
	rojo = R;
	verde = G;
	azul = B;
}

void Terreno::SetPos(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
	limite3.x = x3;
	limite3.y = y3;
	limite4.x = x4;
	limite4.y = y4;
}


void Terreno::SetPos(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4)
{
	limite1.x = x1;
	limite1.y = y1;
	limite1.z = z1;
	limite2.x = x2;
	limite2.y = y2;
	limite2.z = z2;
	limite3.x = x3;
	limite3.y = y3;
	limite3.z = z3;
	limite4.x = x4;
	limite4.y = y4;
	limite4.z = z4;
}

void Terreno::SetTextura(char *f){
	strcpy(tex, f);
}