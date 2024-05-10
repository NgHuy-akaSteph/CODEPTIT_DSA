#include<bits/stdc++.h>
using namespace std;

int pre(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

bool Var(char c){
    return ((c >= 'a' && c <= 'z') && (c >= 'A' && c <= 'Z'));
}

void solve(){
    string s;
    cin >> s;
    stack<char> st;
    string ans;
    for(int i = 0; i < s.size(); i++){
        if(s[i] =='(') st.push(s[i]);
        else if(Var(s[i])) ans += string(1, s[i]);
        else if(s[i] == ')'){
            while(st.top() != '('){
                ans += string(1, st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && pre(st.top()) >= pre(s[i])){
                ans += string(1, st.top());
                st.top();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += string(1, st.top());
        st.pop();
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}