#include<bits/stdc++.h>
using namespace std;

vector<string> vs;
vector<vector<string>> res;

bool check(string s){
    int l = 0, r = s.size()-1;
    while(l < r){
        if(s[l] != s[r]) return false;
        ++l; --r;
    }
    return true;
}

void ql(int bd, string s){
    if(bd >= s.size()) res.push_back(vs);
    for(int j = bd; j < s.size(); j++){
        if(check(s.substr(bd, j - bd + 1))){
            vs.push_back(s.substr(bd, j - bd + 1));
            ql(j + 1, s);
            vs.pop_back();
        }
    }
}

int main(){
    string s; cin >> s;
    ql(0, s);
    for(auto it : res){
        for(string x : it) cout << x <<' ';
        cout << endl;
    }
}