#include<bits/stdc++.h>
using namespace std;
string s, tmp;
set<string> res;

void ql(int i){
    for(char x : {tolower(s[i]), toupper(s[i])}){
        tmp += x;
        if(tmp.size() == s.size())
            res.insert(tmp);
        else
            ql(i+1);
        tmp.pop_back();
    }
}

int main(){
    cin >> s;
    ql(0);
    for(string s : res){
        cout << s << endl;
    }
}