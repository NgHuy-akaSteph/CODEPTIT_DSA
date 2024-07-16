#include<bits/stdc++.h>
using namespace std;

void nge(int a[], int r[], int n){
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] < a[i]){
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        r[st.top()] = -1;
        st.pop();
    }
}

void rse(int a[], int r1[], int n){
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[i] < a[st.top()]){
            r1[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        r1[st.top()] = -1;
        st.pop();
    }
}

int main() {
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int a[n], r[n], r1[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        nge(a, r, n);
        rse(a, r1, n);
        for(int i = 0; i < n; i++){
            if(r[i] != -1) cout << r1[r[i]] <<' ';
            else cout  << r[i] <<' ';
        }
        cout << endl;
    }
    return 0;
}