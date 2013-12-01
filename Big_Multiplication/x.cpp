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

void copia(const Numero& A, Numero& B) {
	B.ncifras = A.ncifras;
	int i;
	for (int i = 0; i < A.ncifras; ++i) {
		B.cifras[i] = A.cifras[i];
	}
}

int main() {
	int n;
	Numero A, B, M, Total;
	//Inicializamos Total a 0 
	Total.ncifras = 1;
	Total.cifras[0] = 0;
	cout << "Numero A?";
	leer_numero(A);
	cout << "Numero B?";
	leer_numero(B);

	escribir_numero(A);
	cout << endl;
	escribir_numero(B);
	cout << endl;

	cout << "------------" << endl;

	for (int i = 0; i < B.ncifras; ++i) {
		multiplica(A, B.cifras[i], M);
		Numero R;
		suma(Total, M, R); // R = Total + M
		copia(R, Total);   // Total = R
		escribir_numero(M);	
		cout << endl;
	}
	//suma(A, B, R);
	cout << "------------" << endl;
	escribir_numero(Total);
}