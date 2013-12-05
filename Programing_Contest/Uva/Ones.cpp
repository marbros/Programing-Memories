#include <iostream>

using namespace std;

int main() {
  
  int n;
  while(cin >> n) {
    int one = 1;
    int acum = 1;
    while(one % n != 0){
       one = (10 * one + 1) % n;
       acum++;     
    }
    cout << acum << endl;
  }  
  return 0;   
}
