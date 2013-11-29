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

int main() {
	Numero N;
	leer_numero(N);
	escribir_numero(N);
	cout << endl;
}