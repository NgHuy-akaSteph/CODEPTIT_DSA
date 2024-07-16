#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gr[1005];
int used[1005];

void dfs(int s) {
    stack<int> st;
    st.push(s);
    used[s] = 1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v : gr[u]) {
            if (!used[v]) {
                used[v] = 1;
                st.push(u);
                st.push(v);
                break;
            }
        }
    }
}

void strongConnected(){
    for(int i = 1; i <= n; i++){
        memset(used, 0, sizeof(used));
        dfs(i);
        for(int j = 1; j <= n; j++){
            if(!used[j]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int T; cin >> T;
    while(T--){
        memset(used, 0, sizeof(used));
        for(int i = 1; i <= 1001; i++) gr[i].clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            gr[x].push_back(y);
        }
        strongConnected();
    }
    return 0;
}