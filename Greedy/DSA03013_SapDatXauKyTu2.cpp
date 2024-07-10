#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--){
        int d; cin >> d;
        string s; cin >> s;
        int f[256] = {0};
        int max_fre = 0;
        for(char c : s){
            f[c]++;
            max_fre = max(max_fre, f[c]);
        }
        int n = s.size();
        if(max_fre <= (n-1)/d + 1) cout << 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}