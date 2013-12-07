#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main (){
     string p, q;
     while(getline(cin,p) and getline(cin, q)) {
        map<char, int> map_p, map_q;  
        
        for(int i = 0; i < p.size(); i++) {
           //Cuantas letras hay en cada string
           map_p[ p[i] ]++;        
        } 
        
        for(int i = 0; i < q.size(); i++) {
           //Cuantas letras hay en cada string
           map_q[ p[i] ]++;        
        }  
        
        for(char c = 'a'; c <= 'z'; ++c) {
             int veces = min(map_p[c], map_q[c]);
             //while(veces--) { 
             for(int i = 0; i < veces; ++i) {
                cout << c;        
             }            
        }
        cout << endl;
                          
     }
}
