#include<bits/stdc++.h>
using namespace std;

//Đỉnh trụ: khi loại bỏ đỉnh này và các cạnh liên thuộc 
//sẽ làm tăng số thành phần liên thông của đồ thị
int n, m;
bool visited[1001];
set<int> adj[1001];
vector<pair<int,int>> el;
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
        el.push_back(make_pair(x,y));
		adj[x].insert(y);
		adj[y].insert(x);
	}
	memset(visited, false, sizeof(visited));
}

int Tplt(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}
//O(E*(E+V));
//Đỉnh trụ: khi loại bỏ đỉnh này và các cạnh liên thuộc 
//sẽ làm tăng số thành phần liên thông của đồ thị
void dinh_tru(){
    int cc = Tplt();//So thanh phan lien thong ban dau
    for(int i = 1; i <= n; i++){
        visited[i] = true;
        if(cc < Tplt()){
            cout << i <<' ';
        }
    }
}
//O(E*(E+V));
//Cạnh cầu: khi loại bỏ cạnh này làm cho
//số thành phần liên thông của đồ thị tăng lên
void canh_cau(){
    int cc = Tplt();
    int cnt = 0;
    for(auto it : el){
        int x = it.first, y = it.second;
        adj[x].erase(y);
        adj[y].erase(x);
        memset(visited, false, sizeof(visited));
        if(cc < Tplt()){
            cnt++;
        }
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout << cnt << endl;
}

int main(){
    nhap();
    
}