// OpenGL.cpp: implementation of the OpenGL class.
//
//////////////////////////////////////////////////////////////////////

#include "OpenGL.h"
#include <string.h>
#include "../../lib/glut.h"
#include "C:\Users\Windows 8\Desktop\Ultimo\Frog 2-6-15\Frog\src\Comun\GLAUX.H"
#pragma comment (lib, "glaux.lib")
vector<string> OpenGL::nombre_texturas;
vector<unsigned int> OpenGL::id_texturas;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OpenGL::OpenGL()
{

}

OpenGL::~OpenGL()
{

}
void OpenGL::Print(char *mensaje, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	glDisable (GL_LIGHTING);

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT) );

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	glColor3ub(r,g,b);
	glRasterPos3f(x, glutGet(GLUT_WINDOW_HEIGHT)-18-y, 0);
	int len = strlen (mensaje );
	for (int i = 0; i < len; i++) 
		glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, mensaje[i] );
	
	
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable( GL_DEPTH_TEST );
}

unsigned int OpenGL::CargaTextura(char* nombre){
	for (int i = 0; i < id_texturas.size(); i++)
	{
		if (0 == nombre_texturas[i].compare(nombre))
			return id_texturas[i];
	}
	unsigned int textura = -1;
	glGenTextures(1, &textura);
	glBindTexture(GL_TEXTURE_2D, textura);
	//codigo de texturas..?
	
	//OJO CON ESTO, BORRAR SI ALGO VA MAL
	int wrap = 1;
	// select modulate to mix texture with color for shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	// when texture area is small, bilinear filter the closest mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	// when texture area is large, bilinear filter the first mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// if wrap is true, the texture wraps over at the edges (repeat)
	//       ... false, the texture ends at the edges (clamp)
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);

	

	AUX_RGBImageRec * mitex = auxDIBImageLoadA(nombre);
	if (mitex != NULL)
	{
		int ret = gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
			mitex->sizeX, mitex->sizeY, GL_RGB, GL_UNSIGNED_BYTE,
			mitex->data);
		delete mitex->data;
		delete mitex;
		id_texturas.push_back(textura);
		std::string cad(nombre);
		nombre_texturas.push_back(cad);
	}

	return textura;
}

void OpenGL::BorraTexturas()
{
	for (int i = 0; i<id_texturas.size(); i++)
	{
		glDeleteTextures(1, &id_texturas[i]);
	}
	id_texturas.clear();
	nombre_texturas.clear();
	glBindTexture(GL_TEXTURE_2D, NULL);
}