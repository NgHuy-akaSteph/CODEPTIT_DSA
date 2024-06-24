#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, s, res = 1e9;
int a[100], x[100];

void ql(int i, int st, int sum){
    for(int j = st; j <= n; j++){
        if(sum + a[j] <= s){
            x[i] = a[j];
            if(sum + a[j] == s){
                res = min(res, i);
            }
            else ql(i+1, j+1, sum + a[j]);
        }
        else return;
    }
}

int main() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ql(1, 1, 0);
    if(res == 1e9) cout << -1;
    else cout << res;
    cout << endl;
    return 0;
}