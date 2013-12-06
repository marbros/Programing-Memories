#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int WallPatterns(int n) {
   if(n <= 2) {
     return n;     
   }
   return WallPatterns(n -1)+ WallPatterns(n -2);    
}

int main() {
    
    int n;
    while(cin >> n) {   
      if(n == 0) break;        
      cout << WallPatterns(n) << endl;
    } 
    return 0;
}
