#include<bits/stdc++.h>
using namespace std;

int n, a[100], x[100];
vector<string> vs;

void ql(int i, int bd, int sum){
    for(int j = bd; j <= n; j++){
        x[i] = a[j];
        if((sum + a[j]) % 2 == 1){
            string s;
            for(int k = 1; k <= i; k++){
                s += to_string(x[k]) + " ";
            }
            vs.push_back(s);
        }
        ql(i+1, j+1, sum + a[j]);
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ql(1, 1, 0);
    if(vs.empty()) cout <<"NOT FOUND";
    else{
        sort(vs.begin(), vs.end());
        for(string x : vs){
            cout << x << endl;
        }
    }
}