#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int h, m;
 
  while(scanf("%d:%d", &h, &m) == 2) {
    if(h==0 && m == 0) break;
    
    double res;
    
    int angulo_m = 6 * m;   
    double angulo_h = (30*h)+ (1/2.0*m);
    res = fabs(angulo_m - angulo_h);

    while(res >= 360) {
       res -= 360;          
    }    
    res = min(res, 360 - res);
    printf("%.3lf\n", res);
  }
 return 0;   
}
