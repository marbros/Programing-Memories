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

int main() {
	Posibles p;
	p.elimina(3);
	cout << p.str() << endl;
	cout << p.activo(2) << endl;
	cout << p.num_activos() << endl;
}