#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {

   string a,b,aux;
   int sizea,sizeb;
   while(getline(cin,a) && getline(cin,b)){
     sizea = a.size(); 
     sizeb = b.size();
     sort(a.begin(),a.end());
     sort(b.begin(),b.end());
     string per = "";
     int i ,j = 0;
     for(i = 0; i<sizea && j<sizeb; i++)
        while(j<sizeb && a[i]>=b[j]) { 
           if(b[j]==a[i]){ 
              per += a[i];
              j++;
              break;
           }
         j++;
     }
     cout << per <<endl;
   }         
    return 0;
}
