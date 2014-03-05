#include<iostream>

using namespace std;

int main()
{
  int k;
  int n;
  cin >> k >> n;

  int currentTime = 0;
  int t;
  char x;

  for(int i = 0; i < n; ++i) {
    cin >> t;
    cin >> x;
    if(currentTime + t > 210) 
      break;
    currentTime += t;
    if(x == 'T') {
      k++;
      if(k == 9)
        k = 1;
    }
  }
  cout << k << endl;
}
