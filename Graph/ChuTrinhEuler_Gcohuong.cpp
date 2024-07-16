#include<bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a1[n+1];// deg+
        vector<int> a2[n+1];// deg-
        for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;
            a1[x].push_back(y);
            a2[y].push_back(x);
        }
        int ok = 1;
        for(int i = 1; i <= n; i++){
            if(a1[i].size() != a2[i].size()){
                ok = 0; break;
            }
        }
        if(ok) cout << 1 << endl;
        else cout << 0 << endl;
    }
}