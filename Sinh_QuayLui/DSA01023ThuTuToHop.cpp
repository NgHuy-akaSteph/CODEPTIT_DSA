#include<bits/stdc++.h>
using namespace std;

int n, k, ok;
int a[20], b[20];

void ktao(){
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
}

bool check(){
    for(int i = 1; i <= k; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n-k+i){
        i--;
    }
    if(i == 0) ok = 0;
    else{
        a[i]++;
        for(int j = i+1; j <= k; j++){
            a[j] = a[j-1]+1;
        }
    }
}



int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >> b[i];
        }
        int res = 0;
        ktao(); ok = 1;
        while(ok){
            res++;
            if(check()){
                cout << res << endl;
                break;
            }
            sinh();
        }
    }
}