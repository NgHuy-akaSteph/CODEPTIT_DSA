#include<bits/stdc++.h>
using namespace std;

int k, m, n;
char a[10][10];// ma tran chu cai
int used[10][10];// danh dau4 chu cai da dung
string s = "";// chuoi dang xet
set<string> dic;// tu dien
vector<string> ans;// ket qua
// huong di chuyen tu 1 o bat ki
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


void Try(int i, int j){
    s += a[i][j];
    if(dic.count(s)){
        ans.push_back(s);
    }
    for(int l = 0; l < 8; l++){
        int i1 = i + dx[l];
        int j1 = j + dy[l];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && used[i1][j1] == 0){
            used[i1][j1] = 1;
            Try(i1, j1);
            used[i1][j1] = 0;
        }
    }
    s.pop_back();
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> k >> m >> n;
        dic.clear(); ans.clear();
        memset(used, 0, sizeof(used));
        for(int i = 1; i <= k; i++){
            string x; cin >> x;
            dic.insert(x);
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                Try(i, j);
            }
        }
        if(ans.empty()) cout << -1;
        else{
            for(auto w : ans) cout << w << " ";
        }
        cout << endl;
    }
}