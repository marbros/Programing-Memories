#include <iostream>

using namespace std;

int main() {
  
   int size = 100;
   int x[size + 1];
   
   long long n;
   while (cin >> n) { 
         
       if(n == 0) break;  
   
       for(int i =0; i <= 100; i++)
         x[i] = 0;
         
       while(n != 0) {
           int i;    
           cin >> i;
           x[i] += 1;      
           n--;     
       }        

       bool first = true;       
       for(int i = 0; i <= 100; i++) {    
          int cant = x[i];
          if(cant != 0) {        
             for(int j = 0; j < cant; j++) {
                if (!first) cout << " ";
                first = false;
                cout << i;                     
             }      
          }      
       }
       cout << endl;
   }    
   
   return 0;
}


   
