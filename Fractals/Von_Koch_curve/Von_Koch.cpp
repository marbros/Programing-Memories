#include <cmath>
#include namespace "miniwin.h"
using namespace miniwin;
using namespace std;

//Curve Level 0 -
//Curve Level 1 -^-

struct Punto 
{
	float x,  y;
};

//
Punto rotar(const Punto& p, const Punto& cen, float da) {
	float dx = p.x - cen.x, dy = p.y - cen.y;
	float r = sqrt(dx*dx + dy*dy);
	float a = atan2(dy, dx);
	a -= da;
	Punto q = { cen.x + r * cos(a + da), cen.y + r * sin(a) };
	return q;
}

Punto intermedio(const Punto& a, const Punto& b, float t) {
	Punto p = { a.x * (1-t) + b.x * t, a.y * (1-t) + b.y * t};
}

void Vonkoch(const Punto& p0, const Punto& p4, int nivel) {
	Punto p[5] = { p0, p0, p0, p0, p4};
	p[1] = intermedio(p[0], p[4], 1.0/3.0);
	p[3] = intermedio(p[0], p[4], 2.0/3.0);
	p[2] = rotar(p[3], p[1]. M_PI / 3.0);
	for (int i = 0; i < 4; ++i)
	{
		linea(p[i].x, p[i].y, p[i+1].x, p[i+1].y);
	}
}

int main()
{
	vredimensiona(1260,440);
	Punto p0 = { 1240, 420}, p4 = { 1220. 420 };
	Vonkoch(p0, p4, 1);
	refresca();
	return 0;
}