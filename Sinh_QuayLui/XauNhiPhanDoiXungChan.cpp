#include<bits/stdc++.h>
using namespace std;

int n, ok, a[50];

void next(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i--] = 0;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}

int main(){
    int k; cin >> k;
    vector<string> vs;
    for(n = 1; n <= k/2; n++){
        ok = 1;
        while(ok){
            string s;
            for(int i = 1; i <= n; i++){
                s += to_string(a[i]);
            }
            for(int i = n; i >= 1; i--){
                s += to_string(a[i]);
            }
            vs.push_back(s);
            next();
        }
    }
    sort(vs.begin(), vs.end());
    for(string x : vs) cout << x << endl;
}