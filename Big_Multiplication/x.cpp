#include <iostream>

using namespace std;

struct Numero {
	int cifras[30];
	int ncifras;
};

void escribir_numero(const Numero& N) {
	for (int i = N.ncifras - 1; i >= 0; --i) {
		cout << N.cifras[i];
	}	
}

void leer_numero(Numero& N) {
	int tam;	
	string s;
	cin >> s;
	int tam = s.size();
	for (int i = 0; i < tam; ++i) {
		char digito = s[i];
		N.cifras[tam - 1 - i] = int(digito) - int('0');
	}
	N.ncifras = tam;
}

int max(int a, int b) {
	int res = a;
	if (res < b) res = b;
	return res;
}

void suma(const Numero&A, const Numero& B, Numero& R) {
	int me_llevo = 0, ncifras = max(A.ncifras, B.ncifras);
	for (int i = 0; i < ncifras; ++i) {
		int cifra_A = cifra_B = 0;
		if(i < A.ncifras)cifra_A = A.cifras[i];
		if(i < B.ncifras)cifra_B = B.cifras[i];
		int suma = A.cifras[i] + B.cifras[i] + me_llevo;
		R.cifras[i] = suma % 10;
		me_llevo = suma / 10;
	}
	if(me_llevo > 0) {
		R.cifras[i] = me_llevo;
	}
	R.ncifras = ncifras + me_llevo;
}

void multiplica(const Numero& A, int cifra, Numero& R) {
	int me_llevo = 0, ncifras = A.ncifras;
	for (int i = 0; i < ncifras; ++i) {
		int mult = (A.cifras[i] * cifra) + me_llevo;
		R.cifras[i] = mult % 10;
		me_llevo = mult / 10;
	}
	R.ncifras = ncifras;	
	if (me_llevo > 0) {
		R.cifras[i] = me_llevo;
		R.ncifras++;
	}
}

int main() {
	Numero A, B, R;
	leer_numero(A);
	leer_numero(B);	
	suma(A, B, R);
	escribir_numero(R);
	cout << endl;
}