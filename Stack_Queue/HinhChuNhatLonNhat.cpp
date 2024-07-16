#include<bits/stdc++.h>
using namespace std;

void smaller_left(int a[], int l[], int n) {
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && a[i] < a[st.top()]){
            l[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        l[st.top()] = -1;
        st.pop();
    }
}

void smaller_right(int a[], int r[], int n){
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[i] < a[st.top()]){
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        r[st.top()] = n;
        st.pop();
    }
}

int main() {
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int a[n], l[n], r[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        smaller_left(a, l, n);
        smaller_right(a, r, n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int w = r[i] - l[i] - 1;
            long long dt = 1ll * a[i] * w;
            ans = max(ans, dt);
        }
        cout << ans << endl;
    }
    return 0;
}