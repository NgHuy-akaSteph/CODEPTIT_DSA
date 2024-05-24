#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        ll res = 0;
        for(int i = 0; i < n-1; i++){
            res += 1ll*((upper_bound(a+i+1, a+n, k-a[i])-a) - (lower_bound(a+i+1, a+n, k-a[i])-a));
        }
        cout << res << "\n";
    }
}