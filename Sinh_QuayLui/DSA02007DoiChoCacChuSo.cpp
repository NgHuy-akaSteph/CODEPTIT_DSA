#include<bits/stdc++.h>
using namespace std;
int n, k, ok = 0;
string s, res;

void ql(int i, string cur_str, int cnt){
    if(i > n || cnt > k) return;
    res = max(res, cur_str);
    char max_val = cur_str[i];
    for(int j = i+1; j <= n; j++){
        max_val = max(max_val, cur_str[j]);
    }
    if(max_val == cur_str[i]){
        ql(i+1, cur_str, cnt);
    }
    else{
        for(int j = i+1; j <= n; j++){
            if(cur_str[j] == max_val){
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
        n = s.size()-1;
        res = s;
        ql(0, res, 0);
        cout << res << endl;
    }
}