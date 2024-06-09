#include<bits/stdc++.h>
using namespace std;

//Thuật toán sinh phân hoạch
/*
    5 : 5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1
*/

int n, ok, cnt, a[100];

void init(){
    cnt = 1;// ban đầu có 1 số là chính nó
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
        int pt = cnt-i+1; // phần còn thiếu của n
        int x = pt/a[i];    // biểu diễn pt theo số a[i] vừa giảm
        int y = pt % a[i]; // phần dư của pt chia a[i]
        cnt = i; // 
        for(int j = 1; j <= x; j++){
            a[++cnt] = a[i]; // vừa gán vừa tăng cnt
        }
        if(y){
            a[++cnt] = y; // vừa gán vừa tăng cnt
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