#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            pq.push(x);
        }
        ll ans = 0;
        while(pq.size() > 1){
            ll d1 = pq.top(); pq.pop();
            ll d2 = pq.top(); pq.pop();
            ll tmp = (d1 + d2) % MOD;
            ans = (ans + tmp) % MOD;
            pq.push(tmp);
        }
        cout << ans << endl;
    }
    return 0;
}