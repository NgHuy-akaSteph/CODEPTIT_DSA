#include<bits/stdc++.h>
using namespace std;
int n, k;

void Try(vector<string> vs, int pos, int cnt, vector<string> cur){
    if(cnt == k){
        for(string x : cur) cout << x <<' ';
        cout << endl;
    }
    for(int i = pos; i < vs.size(); i++){
        cur.push_back(vs[i]);
        Try(vs, i+1, cnt+1, cur);
        cur.pop_back();
    }
}

int main(){
    int m;
    cin >> m >> k;
    set<string> se;
    for(int i = 1; i <= m; i++){
        string tmp; cin >> tmp;
        se.insert(tmp);
    }
    vector<string> vs, cur;
    for(string x : se){
        vs.push_back(x);
    }
    Try(vs, 0, 0, cur);
}