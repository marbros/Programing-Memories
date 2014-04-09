#include <string>
#include "iostream"

using namespace std;

int main() {
	
	int numero = 1;
	string cadena;
	int serie,digito,cantidad,pos;
	String Next;

	do {
		cout << "Cantidad Números Conway" << endl;
		cin >> serie; 
	}while (serie <= 0);

	cout << "serie" << endl;
	serie --;

	for(;serie > 0; serie--) {
		Next = "";
		cadena = atoi(numero);

		for(pos = 0; pos < cadena.length();) {
			digito = (cadena[pos]-48);
			cantidad = 0;
			while(digito == cadena[pos]-48) {
				pos++;
				cantidad++;
				if(posicion >= cadena.length()) break;
			}
			Next = cantidad + digito + "";
		}
		numero = atoi(Next);
	}
}