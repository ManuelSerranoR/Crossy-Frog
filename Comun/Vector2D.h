#ifndef _VECTOR2D_H
#define _VECTOR2D_H

#include <math.h>
#include "../../lib/glut.h"

class Vector2D
{
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D();
	float x;
	float y;
	float z;
	Vector2D operator + (const Vector2D &)const;
	Vector2D operator - (const Vector2D &)const;
	Vector2D operator * (float)const;
	float operator * (const Vector2D &)const;
	float modulo();
	float argumento();
	Vector2D Unitario();
};

#endif