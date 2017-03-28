#include "Interaccion.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion::Rebote(Rana &h, Plataforma p, Tronco tronco)
{
	float Posicion_x_tronco_min = tronco.posicion.x - tronco.Get_Longitud() / 2;
	float Posicion_x_tronco_max = tronco.posicion.x + tronco.Get_Longitud() / 2;

	//Interaccion de la rana con el tronco
	if ((h.posicion.y > (tronco.posicion.y - 0.5f)) && (h.posicion.y < (tronco.posicion.y + 0.5f)) && (h.z == 0))
		if ((h.posicion.x >(Posicion_x_tronco_min)) && (h.posicion.x < (Posicion_x_tronco_max)))
		{
			return true;
		}
		else
		{
			return false;
		}
	else
	{
		return false;
	}
}

bool Interaccion::Destruccion_Vel_Pos(Coche &c, Plataforma caja)
{
	// Esto describe los limites de un coche con la caja. DESTRUCCION 
	float x = caja.acera1.limite4.x + 18;
	if (c.posicion.x > x) return true;
	else return false;
}

bool Interaccion::Destruccion_Vel_Neg(Coche &c, Plataforma caja)
{
	// Esto describe los limites de un coche con la caja. DESTRUCCION 
	float x = caja.acera1.limite1.x - 18;
	if (c.posicion.x < x) return true;
	else return false;
}

bool Interaccion::Destruccion_Vel_Pos(Tronco &c, Plataforma caja)
{
	// Esto describe los limites de un coche con la caja. DESTRUCCION 
	float x = caja.acera1.limite4.x + 18;
	if (c.posicion.x > x) return true;
	else return false;
}

bool Interaccion::Destruccion_Vel_Neg(Tronco &c, Plataforma caja)
{
	// Esto describe los limites de un coche con la caja. DESTRUCCION 
	float x = caja.acera1.limite1.x - 18;
	if (c.posicion.x < x) return true;
	else return false;
}

bool Interaccion::Rebote(Rana &r, Coche c)
{
	float Posicion_x_coche_min = c.posicion.x - c.Get_Longitud() / 2;
	float Posicion_x_coche_max = c.posicion.x + c.Get_Longitud() / 2;

	// Esto describe la colision de la rana con el coche. 
	if ((r.posicion.x > Posicion_x_coche_min - r.altura / 2) && (r.posicion.x < Posicion_x_coche_max + r.altura / 2))
	{
		if (r.posicion.y == c.posicion.y)
			return true;
		else return false;
	}
	else return false;
}

bool Interaccion::Rebote(Rana &h, Plataforma p, bool &izq, bool &dch, bool &atr, bool &rec)
{
	// Esto describe los limites de la rana con la caja. 
	float xmin = p.acera1.limite1.x;
	float xmax = p.acera1.limite3.x;
	float ymin = 0.0f;
	float ymax = p.piedra1.limite2.y;
	if (h.posicion.x > xmax - 0.5)
	{
		h.posicion.x = xmax - 0.5;
		h.z = 0;
		dch = false;
	}
	if (h.posicion.x < xmin + 0.5)
	{
		h.posicion.x = xmin + 0.5;
		h.z = 0;
		izq = false;
	}
	if (h.posicion.y > ymax - 0.5)
	{
		h.posicion.y = ymax - 0.5;
		h.z = 0;
		rec = false;
	}
	if (h.posicion.y < ymin + 0.5)
	{
		h.posicion.y = ymin + 0.5;
		h.z = 0;
		atr = false;
	}

	// Esto describe los limites de la rana con el rio y devuelve un booleano para ser tratado.
	float ymax_rio = p.rio.limite2.y;
	float ymin_rio = p.rio.limite1.y;
	if ((h.posicion.y < ymax_rio) && (h.posicion.y > ymin_rio) && (h.z == 0))
		return true;
	else return false;
}

bool Interaccion::Llegada(Rana &h, Plataforma p, bool &rec)
{
	//Esto describe los limites de la rana con los huecos y las piedras
	float ymin_hueco1 = p.hueco1.limite1.y;
	float xmin_hueco1 = p.hueco1.limite1.x;
	float xmax_hueco1 = p.hueco1.limite3.x;
	float xmin_hueco2 = p.hueco2.limite1.x;
	float xmax_hueco2 = p.hueco2.limite3.x;
	float xmin_hueco3 = p.hueco3.limite1.x;
	float xmax_hueco3 = p.hueco3.limite3.x;
	float xmin_hueco4 = p.hueco4.limite1.x;
	float xmax_hueco4 = p.hueco4.limite3.x;
	float xmin_hueco5 = p.hueco5.limite1.x;
	float xmax_hueco5 = p.hueco5.limite3.x;

	float xmin_piedra1 = p.piedra1.limite1.x;
	float xmax_piedra1 = p.piedra1.limite3.x;
	float xmin_piedra2 = p.piedra2.limite1.x;
	float xmax_piedra2 = p.piedra2.limite3.x;
	float xmin_piedra3 = p.piedra3.limite1.x;
	float xmax_piedra3 = p.piedra3.limite3.x;
	float xmin_piedra4 = p.piedra4.limite1.x;
	float xmax_piedra4 = p.piedra4.limite3.x;
	float xmin_piedra5 = p.piedra5.limite1.x;
	float xmax_piedra5 = p.piedra5.limite3.x;
	float xmin_piedra6 = p.piedra6.limite1.x;
	float xmax_piedra6 = p.piedra6.limite3.x;

	if (h.posicion.y == (ymin_hueco1 - 0.5f))
		//HUECOS
		if ((h.posicion.x > xmin_hueco1) && (h.posicion.x < xmax_hueco1))
			return true;
		else if ((h.posicion.x > xmin_hueco2) && (h.posicion.x < xmax_hueco2))
			return true;
		else if ((h.posicion.x > xmin_hueco3) && (h.posicion.x < xmax_hueco3))
			return true;
		else if ((h.posicion.x > xmin_hueco4) && (h.posicion.x < xmax_hueco4))
			return true;
		else if ((h.posicion.x > xmin_hueco5) && (h.posicion.x < xmax_hueco5))
			return true;
		else return false; 
		//PIEDRAS
		/*else if ((h.posicion.x > xmin_piedra1 - 0.5) && (h.posicion.x < xmax_piedra1))
		{
			h.SetPos(h.GetPos().x, p.hueco1.limite1.y - 0.5f);
			return false;
		}
		else if ((h.posicion.x > xmin_piedra2 - 0.5) && (h.posicion.x < xmax_piedra2))
		{
			h.SetPos(h.GetPos().x, p.hueco1.limite1.y - 0.5f);
			return false;
		}
		else if ((h.posicion.x > xmin_piedra3 - 0.5) && (h.posicion.x < xmax_piedra3))
		{
			h.SetPos(h.GetPos().x, p.hueco1.limite1.y - 0.5f);
			return false;
		}
		else if ((h.posicion.x > xmin_piedra4 - 0.5) && (h.posicion.x < xmax_piedra4))
		{
			h.SetPos(h.GetPos().x, p.hueco1.limite1.y - 0.5f);
			return false;
		}
		else if ((h.posicion.x > xmin_piedra5 - 0.5) && (h.posicion.x < xmax_piedra5))
		{
			h.SetPos(h.GetPos().x, p.hueco1.limite1.y - 0.5f);
			return false;
		}
		else if ((h.posicion.x > xmin_piedra6 - 0.5) && (h.posicion.x < xmax_piedra6))
		{
			h.SetPos(h.GetPos().x, p.hueco1.limite1.y - 0.5f);
			return false;
		}*/
}

//Dibuja una bola donde llega la rana para marcarlo como ocupado.
/*void Interaccion::LlegadaDibuja(Rana &a)
{
	Vector2D vel0;
	vel0.x = 0;
	vel0.y = 0;

	if ((a.GetPos().y > 9.4) && (a.GetPos().x > 0.8) && (a.GetPos().x < 2.2))  {
		uno = true;
		a.SetPos(a.origen.x, a.origen.y);
		a.SetVel(vel0);
	}
	if (uno == true) {
		glPushMatrix();
		glTranslatef(1.5, 9.5, 0.5);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.34, 20, 20);
		glPopMatrix();
	}

	if ((a.GetPos().y > 9.4) && (a.GetPos().x > 3.8) && (a.GetPos().x < 5.2))  {
		dos = true;
		a.SetPos(a.origen.x, a.origen.y);
		a.SetVel(vel0);
	}
	if (dos == true){
		glPushMatrix();
		glTranslatef(4.5, 9.5, 0.5);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.34, 20, 20);
		glPopMatrix();
	}

	if ((a.GetPos().y > 9.4) && (a.GetPos().x > 6.8) && (a.GetPos().x < 8.2))  {
		tres = true;
		a.SetPos(a.origen.x, a.origen.y);
		a.SetVel(vel0);
	}
	if (tres == true){
		glPushMatrix();
		glTranslatef(7.5, 9.5, 0.5);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.34, 20, 20);
		glPopMatrix();
	}

	if ((a.GetPos().y > 9.4) && (a.GetPos().x > 9.8) && (a.GetPos().x < 11.2))  {
		cuatro = true;
		a.SetPos(a.origen.x, a.origen.y);
		a.SetVel(vel0);
	}
	if (cuatro == true){
		glPushMatrix();
		glTranslatef(10.5, 9.5, 0.5);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.34, 20, 20);
		glPopMatrix();
	}

	if ((a.GetPos().y > 9.4) && (a.GetPos().x > 12.8) && (a.GetPos().x < 14.2))  {
		cinco = true;
		a.SetPos(a.origen.x, a.origen.y);
		a.SetVel(vel0);
	}
	if (cinco == true){
		glPushMatrix();
		glTranslatef(13.5, 9.5, 0.5);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.34, 20, 20);
		glPopMatrix();
	}
}*/

