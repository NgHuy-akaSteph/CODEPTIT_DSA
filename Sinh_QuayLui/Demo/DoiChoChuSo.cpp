#include<bits/stdc++.h>
using namespace std;
int n, k;
string s, res;

void ql(int i, string cur_str, int cnt){
    if(cnt > k || i > n) return;
    res = max (res, cur_str);
    char c = cur_str[i];
    for(int j = i+1; j <= n; j++){
        c = max(c, cur_str[j]);
    }
    if(c == cur_str[i]){
        ql(i+1, cur_str, cnt);
    }
    else{
        for(int j = i+1; j <= n; j++){
            if(cur_str[j] == c){
                string tmp = cur_str;
                swap(tmp[i], tmp[j]);
                ql(i+1, tmp, cnt+1);
            }
        }
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> k >> s;
        n = s.size();
        s = "0" + s;
        res = s;
        ql(1, s, 0);
        cout << res.substr(1) << endl;
    }
    return 0;
}