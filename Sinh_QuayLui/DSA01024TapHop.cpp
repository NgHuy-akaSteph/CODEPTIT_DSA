#include<bits/stdc++.h>
using namespace std;

int n, k, s, cnt;
int x[30];

void Try(int i){
    for(int j = x[i-1]+1; j <= n-k+i; j++){
        x[i] = j;
        if(i == k){
            int sum = 0;
            for(int j = 1; j <= k; j++){
                sum += x[j];
            }
            if(sum == s) ++cnt;
        }
        else Try(i+1);
    }
}


int main(){
    while(1){
        cin >> n >> k >> s;
        if(n + k + s == 0) break;
        cnt = 0;
        Try(1);
        cout << cnt << endl;
    }
}