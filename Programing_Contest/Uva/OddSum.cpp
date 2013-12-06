#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int j=1; j <= T; ++j) {
      int a, b;
      cin >> a >> b;
      int sum = 0;
            
      for(int i=a; i <= b; ++i) {  
         if(i/2*2 != i){
             sum += i;    
         }    
      }
      cout << "Case " << j << ": " << sum << endl; 
    }
    
    return 0;   
}
