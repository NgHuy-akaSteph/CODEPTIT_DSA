#include<bits/stdc++.h>
using namespace std;                 

int ok;
vector<string> vs;
string s;
long long ans [501];

void next(){
    int i = s.size()-1;
    while(i >= 0 && s[i] == '9'){
        s[i--] = '0'; 
    }
    if(i == -1) ok = 0;
    else s[i] = '9';
}

void solve(){
    s = string(13, '0');
    ok = 1;
    while(ok){
        vs.push_back(s);
        next();
    }
    for(int i = 1; i <= 500; i++){
        for(string x : vs){
            long long tmp = stoll(x);
            if(tmp && tmp % i == 0){
                ans[i] = tmp;
                break;
            }
        }
    }
}

int main(){
    int t; cin >> t;
    solve();
    while(t--){
        int n; cin >> n;
        cout << ans[n] << endl;
    }
}