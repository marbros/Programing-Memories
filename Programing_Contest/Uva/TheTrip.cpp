#include <iostream>
#include<stdio.h>

using namespace std;

double x[1005];

int main () {
   
   long n;
   while(cin >> n) {
             
      if(n == 0) break;  
      
      double moneyStu, sum = 0;
      for(int i = 0; i < n; i++) {
         cin >> moneyStu;
         x[i] = moneyStu;
         sum += moneyStu;    
      } 
      
      double avg = sum/n;
      double negative = 0;
      double positive = 0;
      
      for(int i = 0; i < n; i++) {     
         double difer = (double)((int)((x[i] - avg)*100.0))/100.0;  
         cout << difer << endl;
         if(difer < 0) {              
            negative += -1*difer;
         }else {
            positive += difer;      
         }               
      }
      if(negative > positive){
         printf("$ %.2lf%\n",negative);         
      }else {
         printf("$ %.2lf%\n",positive);
      }          
   }
   return 0;    
}
