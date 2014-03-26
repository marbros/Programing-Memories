#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

using namespace std;  

vector<pair<string,int> >v;

int tam;

int main(){
    
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
            cin >> n >> m;
        
        for(int i = 0; i < m; i++) {
            int a,b;
            cin >> a >> b;    
        }
        cout << n-1 << endl;
    }
    
    return 0;
}