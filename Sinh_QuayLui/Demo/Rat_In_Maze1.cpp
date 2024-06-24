#include<bits/stdc++.h>
using namespace std;

int n, a[100][100];
vector<string> vs;

void ql(int i, int j, string s){
    if(i == n && j == n){
        vs.push_back(s);
        return;
    }
    if(i + 1 <= n && a[i+1][j]){
        s += "D";
        a[i+1][j] = 0;
        ql(i+1, j, s);
        a[i+1][j] = 1;
        s.pop_back();
    }
    if(j + 1 <= n && a[i][j+1]){
        s += "R";
        a[i][j+1] = 0;
        ql(i, j+1, s);
        a[i][j+1] = 1;
        s.pop_back();
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
        cout << -1;
        return 0;
    }
    string tmp = "";
    ql(1, 1, tmp);
    if(vs.empty()) cout << -1;
    else{
        for(string x : vs){
            cout << x << endl;
        }
    }
}