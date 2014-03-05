#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
int maximoComunDivisor(int num1, int num2);
int main() {

	int a, b, c;

	while(cin >> a >> b >> c) {
	  int num=a*b;
	  int den=c-b;
	
	  int mcd=maximoComunDivisor(num,den);
	  num=num/mcd;
	  den=den/mcd;
	
	  if(num==0){
		cout<<0;
	  }else{
	    cout<< num << "/" <<den << endl;
      }
    }
	  //system("pause");
	return 0;
	
}
int maximoComunDivisor(int num1, int num2){
       int menor= min(abs(num2), abs(num1));
       
       int mcd=1;
       if(num1==0||num2==0){
           return mcd;
       }
       
       for (int i=menor;i>1;i--){      
             if((num2%i==0)&&(num1%i==0)){
                  mcd=i;
                  break;
             }
       }
       return mcd;
   }

