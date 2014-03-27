#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

using namespace std;  

vector <pair<string,int> >v;

int tam;

int main(){
    
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        map <string,int> m;
        for(int i = 0; i < n; i++){
            string a,b;
            cin >> a >> b;
            m[b]++;
        }
        dev = 0;
        cout<<dev-1<<endl;
    }
    
    return 0;
}
