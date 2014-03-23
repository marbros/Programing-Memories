#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int cuentaLetras[26];
	for(int i = 0; i < 26; i++) cuentaLetras[i] = 0;

	for(int i = 0; i < N; i++) {
		string actual;
		cin >> actual;
		cuentaLetras[actual[0]- 'a']++;
	}
	bool alguno = false;
	for (int i = 0; i < 26; i++)
	{
		if(cuentaLetras[i] >= 5) {
			cout << ((char) (i + 'a'));
			alguno = true;
		}
	}
	if(!alguno)
		cout << "PREDAJA";
	cout << endl;
	return 0;
}