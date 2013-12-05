#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;

int a[55];

int main() {
    int run = 1;
    int n;
    while(cin >> n) {;
       if(n==0) break;
       
       int p = 0;
       for(int i = 0; i < n; ++i) {
         cin >> a[i];
         p += a[i];        
       }
       p /=n;
       int ans = 0;
       for(int i=0; i < n; ++i){
         if(a[i] > p) {
              ans += a[i] - p;   
         }   
       }
       
       cout << "Set #" << run++ << endl << "The minimun number of moves is " << ans << "." <<endl << endl;
          
    }
    return 0;
}
