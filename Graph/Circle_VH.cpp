#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gr[1005];
int used[1005];

bool dfs(int u, int par){
    used[u] = 1;
    for(int v : gr[u]){
        if(!used[v]){
            if(dfs(v, u))
                return true;
        }
        // dinh v da duoc tham nhung v khong phai cha truc tiep cua u
        else if(v != par){
            return true;
        }
    }
    return false;
}

int main() {
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= 1001; i++) gr[i].clear();
        memset(used, 0, sizeof(used));
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        int ok = 0;
        for(int i = 1; i <= n; i++){
           if(!used[i] && dfs(i, 0)){
                ok = 1; break;
           }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}