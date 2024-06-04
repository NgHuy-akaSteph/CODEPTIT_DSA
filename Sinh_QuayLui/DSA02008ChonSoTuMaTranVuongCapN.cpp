#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k; cin >> n >> k;
    int a[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int b[n+1];
    int cnt = 0;
    for(int i = 1; i <= n; i++) b[i] = i;
    do{
        int sum = 0;
        for(int i = 1; i <= n; i++) sum += b[i][a[i]];
        if(sum == k) cnt++;
    }while(next_permutation(b+1, b+n+1));
    cout << cnt << endl;
    do{
        int sum = 0;
        for(int i = 1; i <= n; i++) 
            sum += a[i][b[i]];
        if(sum == k){
            for(int i = 1; i <= n; i++) 
                cout << b[i] <<' ';
            cout << endl;
        }
    }while(next_permutation(b+1, b+n+1));
}