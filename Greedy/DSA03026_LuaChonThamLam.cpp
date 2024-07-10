#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string minNum(int n, int s){
    string res = string(n, '0');
    for(int i = n-1; i >= 0; i--){
        if(s > 9){
            res[i] = '9';
            s -= 9;
        }
        else{
            if(i != 0){
                res[0] = '1';
                res[i] += (s - 1);
                return res;
            }
            else{
                res[i] += s;
                return res;
            }
        }
    }
    return res;
}

string maxNum(int n, int s){
    string res = string(n, '0');
    for(int i = 0; i < n; i++){
        if(s > 9){
            res[i] = '9';
            s -= 9;
        }
        else{
            res[i] += s;
            break;
        }
    }
    return res;
}


int main() {
    int n, s;
    cin >> n >> s;
    if(s > 9 * n || (n == 0 && s > 1) || (n > 0 && s == 0)) cout << "-1 -1";
    else cout << minNum(n, s) <<' '<< maxNum(n, s);
    return 0;
}