#include namespace "miniwin.h"
using namespace miniwin;

//Curve Level 0 -
//Curve Level 1 -^-

struct Punto 
{
	float x,  y;
};

void intermedio(const Punto& a, const Punto& b, float t) {
	Punto p = { a.x * (1-t) + b.x * t, a.y * (1-t) + b.y };
}

void Vonkoch(const Punto& p0, const Punto& p4, int nivel) {
	Punto p[5] = { p0, p0, p0, p0, p4};
	p[1] = intermedio(p[0], p[4], 1.0/3.0);
	p[3] = intermedio(p[0], p[4], 2.0/3.0);
}

