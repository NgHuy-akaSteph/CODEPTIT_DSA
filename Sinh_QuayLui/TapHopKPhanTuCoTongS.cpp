#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, s, cnt = 0;
int a[30];

void ql(int i, int start, int sum){
    for(int j = start; j <= n; j++){
        a[i] = j;
        if(i == k){
            if(sum + j == s) cnt++;
        }
        else ql(i+1, j+1, sum + j);
    }
}


int main() {
    cin >> n >> k >> s;
    ql(1, 1, 0);
    cout << cnt << endl;
    return 0;
}