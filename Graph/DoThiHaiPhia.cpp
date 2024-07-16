#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gr[1005];
int color[1005];

bool dfs(int u, int par){
    color[u] = 3 - color[par];
    for(int v : gr[u]){
        if(!color[v]){
            if(!dfs(v, u)) 
                return false;
        }
        else if(color[v] == color[u]){
            return false;
        }
    }
    return true;
}


int main() {
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= 1000; i++) gr[i].clear();
        for(int i = 0 ; i < m; i++){
            int x, y; cin >> x >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        int ok = 1;
        memset(color, 0, sizeof(color));
        color[0] = 2;
        for(int i = 1; i <= n; i++){
            if(!color[i]){
                if(!dfs(i, 0)){
                    ok = 0;
                }
            }
        }
        if(ok) cout <<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}