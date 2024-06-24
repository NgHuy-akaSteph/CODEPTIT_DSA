#include<bits/stdc++.h>
using namespace std;
int n, a[100][100];
vector<string> vs;
string s, way = "DLRU";
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

void ql(int i, int j){
    if(i == n && j == n){
        vs.push_back(s);
    }
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]){
            s += way[k];
            a[i1][j1] = 0;
            ql(i1, j1);
            a[i1][j1] = 1;
            s.pop_back();
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
    if(a[n][n] == 0){
        cout << -1  << endl;
        return 0;
    }
    ql(1, 1);
    if(vs.empty()) cout << -1;
    else{
        for(string x : vs){
            cout << x << endl;
        }
    }
}