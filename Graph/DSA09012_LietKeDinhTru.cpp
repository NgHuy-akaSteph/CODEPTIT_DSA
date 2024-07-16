#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gr[1005];
int used[1005];

void dfs(int u){
    used[u] = 1;
    for(int v : gr[u]){
        if(!used[v]){
            dfs(v);
        }
    }
}

int tplt() {
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main(){
    int T; cin >> T;
    while(T--){
        memset(used, 0, sizeof(used));
        for(int i = 1; i <= 1001; i++) gr[i].clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        int cc = tplt();
        for(int i = 1; i <= n; i++){
            memset(used, 0, sizeof(used));
            used[i] = 1;
            if(tplt() > cc) cout << i <<' ';
        }
        cout << endl;
    }
    return 0;
}