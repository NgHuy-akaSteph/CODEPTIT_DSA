#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string v[15];

void xuli(){
    v[2] = "abc";
    v[3] = "def";
    v[4] = "ghi";
    v[5] = "jkl";
    v[6] = "mno";
    v[7] = "pqrs";
    v[8] = "tuv";
    v[9] = "wxyz";
}

void ql(int i, string cur){
    int num = s[i] - '0';
    for(char c : v[num]){
        if(i == n){
            cout << cur + c << " ";
        }
        ql(i+1, cur + c);
    }
}


int main(){
    xuli();
    cin >> s;
    sort(s.begin(), s.end());
    n = s.size();
    s = "0" + s;
    string tmp = "";
    ql(1, tmp);
    return 0;
}