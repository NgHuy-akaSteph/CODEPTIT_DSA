#include<bits/stdc++.h>
using namespace std;

int n, a[100];
bool used[100];

void out(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
}

void ql(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j] && abs(j - a[i-1]) != 1){
            a[i] = j;
            used[j] = true;
            if(i == n) out();
            else ql(i+1);
            used[j] = false;
        }
    }
}

int main(){
    cin >> n;
    a[0] = -1;
    ql(1);
}