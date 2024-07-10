#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a = 0, ok = 0;
        for(int b = n/7; b >= 0; b--){
            a = (n - b*7)/4;
            if(b * 7 + a * 4 == n){
                for(int i = 1; i <= a; i++) cout << 4;
                for(int i = 1; i <= b; i++) cout << 7;
                ok = 1;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
        else cout << endl;
    }
    return 0;
}