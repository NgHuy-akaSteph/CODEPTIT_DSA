#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, x[20], col[20], d1[105], d2[105], cnt;

void init(){
    memset(col, 1, sizeof(col));
    memset(d1, 1, sizeof(d1));
    memset(d2, 1, sizeof(d2));
    cnt = 0;
}

void Try(int i){
    for(int j = 1; j <= n; j++){
        if(col[j] && d1[i-j+n] && d2[i+j-1]){
            x[i] = j;
            col[j] = d1[i-j+n] = d2[i+j-1] = 0;
            if(i == n) ++cnt;
            Try(i+1);
            col[j] = d1[i-j+n] = d2[i+j-1] = 1;
        }
    }
}



int main() {
    int t; cin >> t;
    while(t--){
        init();
        cin >> n;
        Try(1);
        cout << cnt << endl;
    }
    return 0;
}