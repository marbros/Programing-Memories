#include <iostream>
#include <string>
using namespace std;

const string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); ++i) {
            char letter = s[i];
            int where = -1;
            for (int k = 0; k < keys.size(); ++k) {
                if (letter == keys[k]) {
                    where = k;
                }
            }
            if (where == -1) {
                cout << letter;
            } else {
                cout << keys[where - 1];
            }
        }
        cout << endl;
    }
    return 0;
}
