#include<bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> gr[1005];
vector<pair<int,int>> ed;
int used[1005];

void dfs(int u){
    used[u] = 1;
    for(int v : gr[u]){
        if((u == s && v == t) || (u == t && v == s))
            continue;
        if(!used[v]) dfs(v);
    }
}

int tplt(){
    int cnt = 0;
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main() {
    int T; cin >> T;
    while(T--){
        s = t = -1;
        for(int i = 1; i <= 1001; i++) gr[i].clear();
        ed.clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
            ed.push_back({x, y});
        }
        int cc = tplt();
        for(pair<int,int> e : ed){
            s = e.first;
            t = e.second;
            if(cc < tplt()) cout << s <<' ' << t <<' ' ;
        }
        cout << endl;
    }
    return 0;
}