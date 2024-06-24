#include <bits/stdc++.h>
using namespace std;

int n, m, used[100][100], ok;
char a[100][100];
string s, tmp;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

void ql(int i, int j){
    // cout << tmp << endl;
    if(ok) return;
    if(s == tmp){
        ok = 1;
        return;
    }
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !used[i1][j1]){
            tmp += a[i1][j1];
            used[i1][j1] = 1;
            // if(tmp == s) ok = 1;
            if(s.find(tmp) != string::npos){
                ql(i1, j1);
            }
            used[i1][j1] = 0;
            tmp.pop_back();
        }
    }
}

void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    cin >> s;
    memset(used, 0, sizeof(used));
}

int main(){
    nhap();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == s[0]){
                tmp = ""; tmp += a[i][j];
                used[i][j] = 1;
                ql(i, j);
                if(ok){
                    cout << "YES\n";
                    return 0;
                }
                used[i][j] = 0;
                tmp.pop_back();
            }
        }
    }
    cout << "NO\n";
}