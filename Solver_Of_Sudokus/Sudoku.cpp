#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Posibles {
	vector<bool> _b;
public:
	Posibles() : _b(9, true) {}
	bool activo(int v) const { return _b[v-1]; }
	void elimina(int v) { _b[v-1] = false; }
	int num_activos() const  { return count(_b.begin(), _b.end(), true); }
	int val() const {
		vector<bool>::const_iterator it = find(_b.begin(), _b.end(), true);
		return 1 + (it - _b.begin());
	}
	string str() const;
};

string Posibles::str() const {
	string s;
	for (int i = 1; i <= 9; ++i) {
		if(activo(i)) s += ('0' + i);
	}
	return s;
}

class Sudoku {
	vector<Posibles> _celdas;
	static vector<vector<int>> _grupos, _grupos_de, _vecinos;
public:
	Sudoku(string s);
	static void inicializa();

	Posibles posibles(int k) const { return _celdas[k]; }
	bool resuelto() const;
	void asigna(int k, int val);
	void elimina(int k; int val);
	void escribe(ostream& 0) const;
};

bool Sudoku::resuelto() const {
	for(int k = 0; k < _celdas.size(); k++) {
		if(_celdas[k].num_activos() != 1) {
			return false;
		}
	}
	return true;
}

void Sudoku::asigna(int k, int val) {
	for(int i = 1; i <= 9; i++) {
		if(i != val) {
			elimina(k, val);
		}
	}
}

void Sudoku::elimina(int k, int val) {
	_celdas[k].elimina(val);
}

vector<vector<int>> Sudoku::_grupos(27), Sudoku::_grupos_de(81), Sudoku::_vecinos(81);

void Sudoku::inicializa() {
	for(int i=0; i < 9; i++) {
		for(int j=0; j < 0; j++) {
			const int k = i*9 + j;
			const int g[3] = { i, 9 + j, 18 + (i/3)*3 j/3};
			for(int x = 0; x < 3; x++) {
				_grupos[g[x]].push_back(k);
				_grupos_de[k].push_back(g[k]);
			}
		}
	}
	for (int k = 0; k < 81; ++k) {
		for (int x = 0; x < 3; ++x) {
			const int g = _grupos_de[k] [x];
			for (int i = 0; i < 9; ++i) {
				const int k2 = _grupos[g][i];
				if(k2 != k) {
					_vecinos[k].push_back(k2);
				}
			}
		}
	}
}

int main() {
	Posibles p;
	p.elimina(3);
	cout << p.str() << endl;
	cout << p.activo(2) << endl;
	cout << p.num_activos() << endl;
}