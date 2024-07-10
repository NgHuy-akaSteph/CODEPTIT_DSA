#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string s; cin >> s;
        map<char,int> mp;
        for(char x : s){
            mp[x]++;
        }
        priority_queue<int> q;
        for(auto it : mp) q.push(it.second);
        while(k--){
            int tmp = q.top(); q.pop();
            --tmp;
            q.push(max(tmp, 0));
        }
        long long ans = 0;
        while(!q.empty()){
            ans += 1ll * q.top() * q.top();
            q.pop();
        }
        cout << ans << endl;
    }
    return 0;
}