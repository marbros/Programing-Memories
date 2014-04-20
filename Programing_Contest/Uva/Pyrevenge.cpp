#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        long long a;
        fin >> a;
        if (a == 0) break;

        long long count(0);
        for (long long x=1; x <= a/2; x++) {
            if (a*a % x == 0) {
                long long y = a*a / x;
                if ((y-x)%2 == 0) {
                    long long b = (y-x)/2;
                    if (b > a) {
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
}