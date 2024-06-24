#include<bits/stdc++.h>
using namespace std;

int n, a[20];

void Try(int i){
    if(i == 0) return; // dk dung de quy
    cout << "[";
    for(int j = 1; j <= i; j++){
        if(j == i) cout << a[j] <<"]\n";
        else cout << a[j] <<" ";
    }
    for(int j = 1; j < i; j++){
        a[j] += a[j+1];
    }
    Try(i-1);
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        Try(n);
    }
}