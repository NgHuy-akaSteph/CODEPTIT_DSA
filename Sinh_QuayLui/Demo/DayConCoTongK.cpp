#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, s;
int a[100], x[100];

void ql(int i, int bd, int sum){
    for(int j = bd; j <= n; j++){
        x[i] = a[j];
        if(sum + a[j] == s){
            for(int u = 1; u <= i; u++){
                cout << x[u] <<' ';
            }
            cout << endl;
        }
        else if(sum + a[j] < s){
            ql(i+1, j+1, sum + a[j]);
        }
    }
}

int main() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ql(1, 1, 0);
    return 0;
}