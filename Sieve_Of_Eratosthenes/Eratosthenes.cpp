//Prime Numbers less than N
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	bool prime[N];
	for (int i = 0; i < N; ++i) {
		prime[i] = true;
	}
	for (int i = 2; i < N; ++i) {
		/* Multiples of i: i*2, i*3, i*4, i*5 ... */
		if(prime[i]) {
			for (int j = 2; i * j < N; ++j) {
				prime[i*j] = false;
			}
		}
	}
	for (int i = 2; i < N; ++i) {
		if(prime[i]) cout << i << ' ';
	}
	cout << endl;
	return 0;
}