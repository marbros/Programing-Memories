#include <iostream>
#include <vector>
using namespace std;


int main() {
  int n,g;

  while (n > 0) {

    int recuentos[4][2*n+1];
    for (int j=0; j<4; j++)
      for (int k=0; k <= 2*n; k++)
        recuentos[j][k] = 0;

    cin >> g
    for (int i=0; i<g; i++) {
      int k,x,y,s,t;
      fin >> k >> x >> y >> s >> t;
      for (int j=0; j<k; j++) {
        recuentos[0][x]++;
        recuentos[1][y]++;
        recuentos[2][x+y]++;
        recuentos[3][1+n+x-y]++;

        x += s;
        y += t;
      }
    }

    long count = 0;
    for (int j=0; j<4; j++)
      for (int k=0; k <= 2*n; k++)
        if (recuentos[j][k] > 1)
          count += (recuentos[j][k] - 1);

    cout << count << endl;
    cin >> n;
  }
}