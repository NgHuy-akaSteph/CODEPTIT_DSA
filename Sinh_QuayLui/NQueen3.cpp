#include<bits/stdc++.h>
using namespace std;
int n, col[100], d1[100], d2[100], x[100];

void ql(int i){
    for(int j = 1; j <= n; j++){
        if(col[j] == 0 && d1[i+j-1] == 0 && d2[i-j+n] == 0){
            x[i] = j;
            col[j] = 1;
            d1[i+j-1] = 1;
            d2[i-j+n] = 1;
            if(i == n){
                for(int r = 1; r <= n; r++){
                    for(int c = 1; c <= n; c++){
                        if(x[r] == c){
                            cout << "Q";
                        }
                        else{
                            cout << ".";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else ql(i+1);
            col[j] = 0;
            d1[i+j-1] = 0;
            d2[i-j+n] = 0;
        }
    }
}

int main(){
    cin >> n;
    ql(1);
}