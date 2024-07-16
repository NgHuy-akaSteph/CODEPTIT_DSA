#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, u, v;
map<int, set<int>> mp;
bool used[1005];
int truoc[1005];

void dfs(int s){
    used[s] = true;
    for(int t : mp[s]){
        if(!used[t]){
            truoc[t] = s;
            dfs(t);
        }
    }
}



int main() {
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> u >> v;
        mp.clear();
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            mp[x].insert(y);
        }
        memset(used, false, sizeof(used));
        memset(truoc, 0, sizeof(truoc));
        dfs(u);
        if(used[v]){
           vector<int> path;
           while(v != u){
                path.push_back(v);
                v = truoc[v];
           }
           path.push_back(u);
           reverse(path.begin(), path.end());
           for(int x : path) cout << x <<' ';
        }
        else cout << -1;
        cout << endl;
    }
    return 0;
}