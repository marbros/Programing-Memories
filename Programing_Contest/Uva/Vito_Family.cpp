#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int cases;
        cin >> cases; 
        
        int x[cases];
        for(int j = 0; j < cases; j++) {
            cin >> x[j];
        }
        
        qsort (x, cases, sizeof(int), compare);     
        
        int minimo = 0;
        int result = 0;
        int med = cases /2;
        for(int j = 0; j < cases; j++) {
            minimo = abs(x[j]- x[med]);       
            result += minimo; 	         
        }             
        cout << result << endl;
    }  
    return 0;   
}



  
