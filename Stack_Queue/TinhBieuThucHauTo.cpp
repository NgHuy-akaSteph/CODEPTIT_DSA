#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        for(char x : s){
            if(isdigit(x)){
                st.push(x - '0');
            }
            else{
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                int exp;
                if(x == '/') exp = op2/op1;
                else if(x == '*') exp = op2 * op1;
                else if(x == '+') exp = op2 + op1;
                else if(x == '-') exp = op2 - op1;
                st.push(exp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}