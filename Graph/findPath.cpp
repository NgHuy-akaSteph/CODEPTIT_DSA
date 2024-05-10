#include<bits/stdc++.h>
using namespace std;

int n, m, s, t;
bool visited[1001];
vector<int> adj[1001];
int parent[1001];

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i : adj[x]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = x;
                bfs(i);
            }
        }
    }
}

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    cin >> s >> t;
	memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
}

void findPath(int s, int t){
    bfs(s);
    if(!visited[t]){
        cout <<"Not exist!";
    }
    else{
        vector<int> path;
        //Bat dau tu dinh ket thuc
        while(t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int x : path) cout << x << ' ';
        cout << endl;
    }
}


int main(){
    input();
    findPath(s, t);
}