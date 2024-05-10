#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        for(int i = s.size()-1; i >= 0; i--){
            if(isdigit(s[i])){
                st.push(s[i] - '0');
            }
            else{
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                int exp;
                if(s[i] == '+') exp = op1 + op2;
                else if(s[i] == '-') exp = op1 - op2; 
                else if(s[i] == '*') exp = op1 * op2;
                else if(s[i] == '/') exp = op1/op2;
                st.push(exp);
            }
        }
        cout << st.top() << endl;
    }
}