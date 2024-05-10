#include<bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1001];
set<int> adj[1001];
vector<pair<int,int>> el;// dscanh

void dfs(int u){
    visited[u] = true;
    for(int x : adj[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        el.push_back(make_pair(x, y));
        adj[x].insert(y);
        adj[y].insert(x);
    }
}

int tplt(){
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            dfs(i);
        }
    }
    return cnt;
}

void canh_cau(){
    int cc = tplt();
    for(auto it : el){
        int x = it.first, y = it.second;
        adj[x].erase(y);
        adj[y].erase(x);
        memset(visited, false, sizeof(visited));
        if(cc < tplt()){
            cout << x << ' ' << y << ' ';
        }
        adj[x].insert(y);
        adj[y].insert(x);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        nhap();
        canh_cau();
        cout << endl;
    }
    return 0;
}