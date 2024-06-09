#include<bits/stdc++.h>
using namespace std;

int n, a[100], b[100];
bool used[100];
vector<string> vs1, vs2;

void xl1(){
    string s;
    for(int i = 1; i <= n; i++){
        s += (char)(a[i] - 1 + 'A');
    }
    vs1.push_back(s);
}

void ql1(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            a[i] = j;
            used[j] = true;
            if(i == n) xl1();
            else ql1(i+1);
            used[j] = false;
        }
    }
}

void xl2(){
    string s;
    for(int i = 1; i <= n; i++){
        s += to_string(b[i]);
    }
    vs2.push_back(s);
}

void ql2(int i){
    for(int j = 1; j <= n; j++){
        b[i] = j;
        if(i == n) xl2();
        else ql2(i+1);
    }
}

int main(){
    cin >> n;
    ql1(1);
    ql2(1);
    for(string x : vs1){
        for(string y : vs2){
            cout << x << y << endl;
        }
    }
}