#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(string s){
    int ans = 0;
    stack<int> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[') st.push(i);
        else{
            if(!st.empty()) st.pop();
            else{
                int j = i;
                while(s[j] == ']') j++;
                ans += j - i;
                swap(s[i], s[j]);
                st.push(i);
            }
        }
    }
    cout << ans << endl;
}


int main() {
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        solve(s);
    }
    return 0;
}