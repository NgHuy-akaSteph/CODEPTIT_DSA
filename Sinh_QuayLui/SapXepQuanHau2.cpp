#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n = 8, res, x[20], d1[100], d2[100], c[100];
int v[100][100];


void Try(int i){
    for(int j = 1; j <= n; j++){
        if(c[j] && d1[i-j+n] && d2[i+j-1]){
            x[i] = j;
            c[j] = d1[i-j+n] = d2[i+j-1] = 0;
            if(i == n){
                int tmp = 0;
                for(int k = 1; k <= n; k++){
                    tmp += v[k][x[k]];
                }
                res = max(res, tmp);
            }
            Try(i+1);
            c[j] = d1[i-j+n] = d2[i+j-1] = 1;
        }
    }
}

void inp(){
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            cin >> v[x][y];
        }
    }
    memset(c, 1, sizeof(c));
    memset(d1, 1, sizeof(d1));
    memset(d2, 1, sizeof(d2));
}

int main() {
    int t; cin >> t;
    while(t--){
        inp(); res = 0;
        Try(1);
        cout << res << endl;
    }
    return 0;
}