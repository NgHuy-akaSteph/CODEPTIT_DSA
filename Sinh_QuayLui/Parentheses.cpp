#include<bits/stdc++.h>
using namespace std;
int n;
string s, tmp = "()[]{}";
vector<string> vs;

bool check(string x){
    stack<char> st;
    for(char c : x){
        if(c == '(' || c == '[' || c == '{'){
            st.push(c);
        }
        else{
            if(st.empty()) return false;
            char k = st.top();
            st.pop();
            if((k == '(' && c != ')') || (k == '[' && c != ']') || (k == '{' && c != '}')){
                return false;
            }
        }
    }
    if(st.empty()) return true;
    return false;
}

void ql(int i){
    for(int j = 0; j < tmp.size(); j++){
        s += tmp[j];
        if(s.size() == n){
            if(check(s)) vs.push_back(s);
        }
        else ql(i+1);
        s.pop_back();
    }
}

int main(){
    cin >> n;
    if(n%2 != 0){
        cout <<"NOT FOUND";
    }
    else{
        ql(1);
        if(vs.empty()) cout << "NOT FOUND";
        else{
            sort(vs.begin(), vs.end());
            for(string x : vs){
                cout << x <<' ';
            }
        }
    }

}