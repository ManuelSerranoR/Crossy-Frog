// OpenGL.h: interface for the OpenGL class.
//
//////////////////////////////////////////////////////////////////////
#pragma warning (disable: 4786)

#include <string>
#include <vector>

using namespace std;

#if !defined(AFX_OPENGL_H__2B1AF605_BAA9_4751_9D16_B7310454F0B6__INCLUDED_)
#define AFX_OPENGL_H__2B1AF605_BAA9_4751_9D16_B7310454F0B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class OpenGL  
{
public:
	OpenGL();
	virtual ~OpenGL();
	static void Print(char *mensaje, int x, int y, unsigned char r=255, unsigned char g=255, unsigned char b=255);
	static unsigned int CargaTextura(char* nombre);
	static void BorraTexturas();
	
protected:
	static vector<string> nombre_texturas;
	static vector<unsigned int> id_texturas;
};

#endif // !defined(AFX_OPENGL_H__2B1AF605_BAA9_4751_9D16_B7310454F0B6__INCLUDED_)
