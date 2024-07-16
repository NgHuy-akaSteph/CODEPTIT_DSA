#include<bits/stdc++.h>
using namespace std;
int n, m, s, t;
map<int, set<int>> mp;
bool used[1005];
int truoc[1005];

// void dfs(int u){
//     used[u] = true;
//     for(int v : mp[u]){
//         if(!used[v]){
//             truoc[v] = u;
//             dfs(v);
//         }
//     }
//}
void bfs(int u){
    queue<int> q;
    q.push(u);
    used[u] = true;
    while(!q.empty()){
        int e = q.front(); q.pop();
        for(int v : mp[e]){
            if(!used[v]){
                q.push(v);
                used[v] = true;
                truoc[v] = e;
            }
        }
    }
}

int main() {
    int T; cin >> T;
    while(T--){
        cin >> n >> m >> s >> t;
        mp.clear();
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            mp[x].insert(y);
            mp[y].insert(x);
        }
        memset(used, false, sizeof(used));
        memset(truoc, 0, sizeof(truoc));
        bfs(s);
        if(used[t]){
            vector<int> path;
            while(t != s){
                path.push_back(t);
                t = truoc[t];
            }
            path.push_back(s);
            reverse(path.begin(), path.end());
            for(int x : path) cout << x <<' ';
        }
        else cout << -1;
        cout << endl;
    }
}