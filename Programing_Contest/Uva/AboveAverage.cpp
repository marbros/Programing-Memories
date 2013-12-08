#include <iostream>
#include <cstring>
#include<stdio.h>

using namespace std;

int x[1005];

int main() {
        
    int C;
    cin >> C;

    for(int j=0; j < C; ++j) {
      int N;      
      cin >> N;
      
      int sum = 0;  
      for(int i=0; i < N; i++) {
          cin >> x[i]; 
          sum += x[i];
      
      }
      double avg = 1.0*sum/N;

      int cont = 0;      
      for(int i=0; i < N; ++i) {
          if(x[i] > avg){
             cont++;     
          }        
      }
      double result = (cont*100.0) / N;
      printf("%.3lf%%\n",result);
      
     }
    return 0;
}
