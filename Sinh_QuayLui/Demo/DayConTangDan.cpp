#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100], x[100];
vector<string> vs;

void ql(int i, int bd){
    for(int j = bd; j <= n; j++){
        if(a[j] > x[i-1]){
            x[i] = a[j];
            if(i >= 2){
                string s;
                for(int k = 1; k <= i; k++){
                    s += to_string(x[k]) + " ";
                }
                vs.push_back(s);
            }
            ql(i+1, j+1);
        }
    }
}



int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    x[0] = 0;
    ql(1, 1);
    sort(vs.begin(), vs.end());
    for(string x : vs){
        cout << x << endl;
    }
    return 0;
}