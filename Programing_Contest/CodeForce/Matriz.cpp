#include <algorithm>
#include <array>
#include <iostream>
#include <cstdio>

using namespace std;

// int acumMaxMatriz(int ini, int final) {
// 	int mayor = 0;
// 	for (int i = 0; i < final; ++i)
// 	{	
// 		if( > mayor) {

// 		}
// 	}
// }

int main() {

	int n;
	cin >> n;
	long m[n];

	int resul = 0;

	for(int i=0; i < n; ++i) {
		m[i];
	}
	int len = m.size();
	sort(m.begin(), len -1);

	int m = 1;
	while (m <= n) {
		resul = resul + //acumulador del max por submatriz (inicio + inicio + m)
		m = m * 4;
	}

	cout << resul << endl;

	// system("pause");
	return 0;
}
