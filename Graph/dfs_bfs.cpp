#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*  Thuat toan tim kiem tren do thi: DFS, BFS
    - Do phuc tap: G = (V, E) V: tap dinh, E: tap canh
        + O(V+E) neu su dung danh sach ke
        + O(V*V) neu su dung ma tran ke
        + O(V*E) neu su dung danh sach canh
*/

vector<int> adj[1001];// danh sach ke
bool visited[1001];// mang danh dau dinh da tham
int n, m;// so dinh, so canh
vector<pair<int,int>>  eList;// danh sach canh
int a[1001][1001]; // ma tran ke

/*DFS su dung de quy*/
void DFS_by_adjList(int u){
    cout << u << " ";
    visited[u] = true;
    // duyet danh sach ke cua dinh u
    for(int v : adj[u]){
        if(!visited[v]){
            DFS_by_adjList(v);
        }
    }
}

void DFS_by_adjMatrix(int u){
    cout << u <<" ";
    visited[u] = true;
    // duyet ds ke cua dinh u: duyet dong thu u trong adjMatrix
    for(int v = 1; v <= n; v++){
        if(a[u][v] == 1  && visited[v] == false)
            DFS_by_adjMatrix(v);
    }
}

void DFS_by_edgeList(int u){
    cout << u << " ";
    visited[u] = true;
    // Moi lan tim dinh ke phai xet lai toan bo canh trong eList
    for(auto it : eList){
        if(it.first == u){
            if(!visited[it.second])
                DFS_by_edgeList(it.second);
        }
        if(it.second == u){
            if(!visited[it.first])
                DFS_by_edgeList(it.first);
        }
    }
}

//BFS
void BFS_by_adjList(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << " ";
        for(int y : adj[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    DFS_by_adjMatrix(1);
    return 0;
}