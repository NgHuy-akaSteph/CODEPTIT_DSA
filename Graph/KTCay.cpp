#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        set<int> se;
        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;
            se.insert(x);
            se.insert(y);
        }
        if(se.size() != n) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}