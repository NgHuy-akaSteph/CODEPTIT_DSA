#include<bits/stdc++.h>
using namespace std;

//Thuật toán sinh phân hoạch
/*
    5 : 5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1
*/

int n, ok, cnt, a[100];

void init(){
    cnt = 1;
    a[1] = n;
}

void next(){
    int i = cnt;
    while(i >= 1 && a[i] == 1){
        i--;
    }
    if(i == 0) ok = 0;
    else{
        a[i]--;
        int thieu = cnt-i+1;
        int x = thieu/a[i];
        int y = thieu % a[i];
        cnt = i;
        for(int j = 1; j <= x; j++){
            a[cnt+1] = a[i];
            ++cnt;
        }
        if(y){
            a[cnt+1] = y;
            ++cnt;
        }
    }
}



int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        init(); ok = 1;
        while(ok){
            cout << "(";
            for(int i = 1; i <= cnt; i++){
                if(i == cnt) cout << a[i];
                else cout << a[i] <<" "; 
            }
            cout << ") ";
            next();
        }
        cout << endl;
    }
}