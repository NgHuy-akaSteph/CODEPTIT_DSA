#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(int s, int d){
    string res = string(d, '0');
    for(int i = d-1; i >= 0; i--){
        if(s > 9){
            res[i] = '9';
            s -= 9;
        }
        else{
            if(i != 0){
                res[0]  = '1';
                res[i] += (s - 1);
                return res;
            }
            else{
                res[i] += s;
                return res;
            }
        }
    }
}


int main() {
    int t; cin >> t;
    while(t--){
        int s, d; cin >> s >> d;
        if(s > 9 * d || d = 0 && s >= 0) cout << -1 << endl;
        else cout << solve(s, d) << endl;
    }
    return 0;
}