#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> st;
        int cnt = 0;
        if(s[0] == ')') cnt++, s[0] = '(';
        if(s[s.size()-1] == '(') cnt++, s[s.size()-1] = ')';
        for(char x : s){
            if(x == '('){
                st.push(x);
            }
            else{
                if(!st.empty() && st.top() == '(') st.pop();
                else if(!st.empty() && st.top() == ')') cnt++, st.pop();
                else if(st.empty()) cnt++, st.push('(');
            }
        }
        if(!st.empty()) cnt += st.size()/2;
        cout << cnt << endl;
    }
    return 0;
}