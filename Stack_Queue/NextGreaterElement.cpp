#include<bits/stdc++.h>
using namespace std;

void nge(vector<int> a, int n, vector<int> b){
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] < a[i]){
            b[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    for(int x : b) cout << x << ' ';
    cout << endl;
}

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int &x : a) cin >> x;
        nge(a, n, b);
    }
    return 0;
}