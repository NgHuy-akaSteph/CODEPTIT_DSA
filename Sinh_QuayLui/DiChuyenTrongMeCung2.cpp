#include<bits/stdc++.h>
using namespace std;

int n, ok;
int a[100][100];
string s, way = "DLRU";
//Huong di chuyen theo thu tu DLRU
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j){
    if(i == n && j == n){
        ok = 1;
        cout << s <<" ";
    }
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]){
            s += way[k];
            a[i1][j1] = 0;
            Try(i1, j1);
            a[i1][j1] = 1;
            s.pop_back();
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        inp();
        ok = 0; s = "";
        if(a[1][1] && a[n][n]){
            a[1][1] = 0;
            Try(1,1);
        }
        if(!ok) cout << "-1\n";
        else cout << endl;
    }
    return 0;
}