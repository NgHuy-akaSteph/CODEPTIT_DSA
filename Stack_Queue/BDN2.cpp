#include<bits/stdc++.h>
using namespace std;

bool check(string s, int n){
    int x = 0;
    for(int i = 0; i < s.size(); i++){
        x = (x * 10 + (s[i] - 48)) % n;
    }
    return x == 0;
}

int main() {
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        while(true){
            string s = q.front();
            q.pop();
            if(check(s, n)){
                cout << s << endl;
                break;
            }
            q.push(s + "0");
            q.push(s + "1");
        }
    }
}