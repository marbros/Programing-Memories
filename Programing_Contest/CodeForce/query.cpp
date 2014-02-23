#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int query,li,ri;
	cin >> query;

	int list[str.length()];
	list[0] = 0;
	int suma = 0;

	for(int j=1; j < str.length(); j++) {
		if(str[j] == str[j-1]) {
			suma++;
		}
		list[j] = suma;
	}
	for(int i = 0; i < query; i++) {
		cin >> li >> ri;
		cout << list[ri-1]-list[li-1] << endl;
	}
	return 0;
}