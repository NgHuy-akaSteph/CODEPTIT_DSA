#include<bits/stdc++.h>
using namespace std;

int n, a[100];
bool used[100];

bool nguyen_am(int n){
    return (n == 1 || n == 5);// Vi tri tuong ung cua A va E
}

void xuli(){
    for(int i = 2; i <= n-1; i++){
        if(nguyen_am(a[i]) && !nguyen_am(a[i-1]) && !nguyen_am(a[i+1])){
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << (char)('A' + a[i] - 1);
    }
    cout << endl;
}

void ql(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            a[i] = j;
            used[j] = true;
            if(i == n) xuli();
            else ql(i+1);
            used[j] = false;
        }
    }
}

int main(){
    char c;
    cin >> c;
    n = (int)(c - 'A' + 1);
    ql(1);
}