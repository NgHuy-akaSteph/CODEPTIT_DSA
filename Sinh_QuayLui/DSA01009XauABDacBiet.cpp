#include<bits/stdc++.h>
using namespace std;
int n, k, ok;
vector<char> a(20);

void init() {
    for(int i = 1; i <= n; i++){
        a[i] = 'A';
    }
}

void next() {
    int i = n;
    while(i >= 1 && a[i] == 'B'){
        a[i] = 'A';
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 'B';
}

bool check() {
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 'A') cnt++;
        else cnt = 0;
        if(cnt > k) return false;
        if(cnt == k) ans++;
    }
    return ans == 1;
}

int main(){
    cin >> n >> k;
    init(); ok = 1;
    int cnt = 0;
    vector<vector<char>> v;
    while(ok){
        if(check()){
            v.push_back(a);
            cnt++;
        }
        next();
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        for(int j = 1; j <= n; j++){
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}