#include<bits/stdc++.h>
using namespace std;

int n, ok;
int a[100][100];
string s;

void ql(int i, int j){
    if(i == n && j == n){
        ok = 1;
        cout << s << " ";
    }
    //Chon di xuong truoc se sinh cau hinh theo tt tu dien
    //Gan nuoc di tiep theo khi dang o (i, j)
    if(i + 1 <= n && a[i+1][j]){
        s += "D";
        a[i+1][j] = 0; // Danh dau da di qua roi
        ql(i+1, j);
        s.pop_back();// xoa nuoc di cuoi cung
        a[i+1][j] = 1; 
    }
    if(j + 1 <= n && a[i][j+1]){
        s += "R";
        a[i][j+1] = 0;
        ql(i, j+1);
        s.pop_back();
        a[i][j+1] = 1;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        ok = 0; s = "";
        if(a[1][1] && a[n][n]){
            ql(1,1);
        }
        if(!ok) cout << "-1\n";
        else cout << endl;
    }
    return 0;
}