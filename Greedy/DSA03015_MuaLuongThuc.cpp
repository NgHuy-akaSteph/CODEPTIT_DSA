#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n, m, s;
        cin >> n >> s >> m;
        if(s * m > (s-s/7) * n) cout << -1 << endl;
        else cout << (s * m + n-1)/n << endl;
    }
    return 0;
}
