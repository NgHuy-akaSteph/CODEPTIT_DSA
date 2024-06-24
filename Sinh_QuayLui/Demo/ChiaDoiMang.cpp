#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok = 0, s = 0;

void ql(int i, int bd, int sum){
    if(ok) return; // ngat canh
    for(int j = bd; j <= n; j++){
        if(sum + a[j] <= s){
            if(sum + a[j] == s) ok = 1;
            else ql(i+1, j+1, sum + a[j]);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    if(s % 2 != 0){
        cout << 0;
        return 0;
    }
    s = s/2;
    ql(1, 1, 0);
    if(ok) cout << ok;
}