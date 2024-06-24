#include<bits/stdc++.h>
using namespace std;
int n, k, sum = 0, ok;
int a[100], x[100];



void ql(int i, int pos){
    for(int j = pos; j <= n; j++){
        x[i] = a[j];
        sum += a[j];
        if(sum == k){
            ok = 1;
            cout <<"[";
            for(int l = 1; l <= i; l++){
                if(l != i) cout << x[l] <<' ';
                else cout << x[l] <<"] ";
            }
        }
        else{
            ql(i + 1, j + 1);
        }
        sum -= a[j];
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        ok = 0;
        ql(1, 1);
        if(!ok) cout << "-1\n";
        else cout << endl;
    }
}