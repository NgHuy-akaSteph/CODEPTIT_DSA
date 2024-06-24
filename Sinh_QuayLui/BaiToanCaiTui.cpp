#include<bits/stdc++.h>
using namespace std;

int n, res = -1e9, s;
int a[100], v[100], w[100];

void ql(int i, int totalWeight, int totalVal){
    //Neu totalWeight > s -> dung nhanh chon nay
    if(totalWeight > s) return; // Ki thuat ngat canh
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i == n){
            if(a[i]){
                if(totalWeight + w[i] <= s){
                    res = max(res, totalVal + v[i]);
                }
            }
            else{
                if(totalWeight <= s){
                    res = max(res, totalVal);
                }
            }
        }
        else{
            if(a[i]) ql(i+1, totalWeight + w[i], totalVal + v[i]);
            else ql(i+1, totalWeight, totalVal);
        }
    }
}



int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    ql(1, 0, 0);
    cout << res << endl;
}