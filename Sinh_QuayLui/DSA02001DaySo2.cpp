#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[20];
/* 
    Mang a[]:
    1 2 3 4 5  -> i = 5
    3 5 7 9 5  -> i = 4
    8 12 16 9 5 -> i = 3
    20 28 16 9 5 -> i = 2
    48 28 16 9 5 -> i = 1
*/

void Try(int i){
    if(i == 0) return;//ket thuc de quy
    for(int j = 1; j < i; j++){
        a[j] = a[j] + a[j+1];
    }
    Try(i-1);
    cout << "[";
    for(int j = 1; j <= i; j++){
        if(j == i) cout << a[j] <<"] ";
        else cout << a[j] <<" ";
    }
    for(int j = i; j >= 1; j--){
        a[j] -= a[j+1];
    }
}

int main() {
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        Try(n);
        cout << endl;
    }
    return 0;
}