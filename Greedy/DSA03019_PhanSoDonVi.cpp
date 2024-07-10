#include<bits/stdc++.h>
using namespace std;
// Cần để tử và mẫu ở dạng long long để tránh tràn
//VD: 13 / 79 = 1 / 7 + 1 / 47 + 1 / 2363 + 1 / 30708367 + 1 / 1886007576905011
void solve(long long p, long long q){
    while(1){
        if(q % p == 0){
            cout << "1/" << q/p << endl;
            return;
        }
        long long x = q/p+1;
        cout << "1/" << x << " + ";
        p = p * x - q;
        q = q * x;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        long long p, q; cin >> p >> q;
        solve(p, q);
    }
    return 0;
}