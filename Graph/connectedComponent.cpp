#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
bool visited[1001];
vector<int> adj[1001];

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	cout << u <<" ";
	visited[u] = true;
	for(int x : adj[u]){
		if(!visited[x])
			dfs(x);
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int x = q.front(); q.pop();
		cout << x <<' ';
		for(int i : adj[x]){
			if(!visited[i]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}
//Đếm số thành phần liên thông trên đồ thị vô hướng
//Sử dụng để kiểm tra đồ thị vô hướng liên thông: cnt == 1
void connectedComponent(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			cnt++;
			cout <<"Các đỉnh thuộc thành phần liên thông thứ "<< cnt << ":\n";
			bfs(i);
			cout << "\n";
		}
	}
	cout << cnt << endl;
}

int main(){
	nhap();
	connectedComponent();
	return 0;
}