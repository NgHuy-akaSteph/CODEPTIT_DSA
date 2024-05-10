#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n), r(n);
        for(int &x : v) cin >> x;
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= v[i])
                st.pop();
            if(st.empty()) r[i] = -1;
            else r[i] = st.top();
            st.push(v[i]);
        }
        for(int x : r)
            cout << x <<' ';
        cout << endl;
    }
    return 0;
}