#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> res;
        res.push_back("0");
        res.push_back("1");
        for(int i = 2; i <= n; i++){
            int m = res.size();
            for(int i = m-1; i >= 0; i--){
                res.push_back(res[i]);
            }
            for(int i = 0; i < m; i++){
                res[i] = '0' + res[i];
            }
            for(int i = m; i < res.size(); i++){
                res[i] = '1' + res[i];
            }
        }
        for(string x : res) cout << x << ' ';
        cout << endl;
    }
}