#include<bits/stdc++.h>
using namespace std;

int n, c[100][100], x[100], ans = INT_MAX;
bool visited[100];
int cmin = INT_MAX;// khoang cach nho nhat giua hai tp

void ql(int i, int exp){
    for(int j = 1; j <= n; j++){
        if(!visited[j]){
            x[i] = j;
            visited[j] = true;
            exp += c[x[i-1]][x[i]];
            if(i == n){
                ans = min(ans, exp + c[x[n]][1]);
            }
            //danh gia can
            else if(exp + (n-i+1)*cmin < ans){
                ql(i+1, exp);
            }
            visited[j] = false;
            exp -= c[x[i-1]][x[i]];
        }
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j])
                cmin = min(cmin, c[i][j]);
        }
    }
    x[1] = 1;
    visited[1] = true;
    ql(2, 0);
    cout << ans << endl;
}