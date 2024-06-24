#include<bits/stdc++.h>
using namespace std;

// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là
// tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có
// thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ
// tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số
// như sau: {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

int n, k;
int a[100], x[100];
vector<string> vs;

void ql(int i, int bd, int sum){
    for(int j = bd; j <= n; j++){
        if(sum + a[j] <= k){
            x[i] = a[j];
            if(sum + a[j] == k){
                string s = "{ ";
                for(int u = 1; u <= i; u++){
                    if(u == i)  s += to_string(x[u]) + " }";
                    else s += to_string(x[u]) + " ";
                }
                vs.push_back(s);
            }
            else ql(i+1, j, sum + a[j]);
        }
    }
}


int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ql(1, 1, 0);
    if(vs.empty()) cout << -1 << endl;
    else{
        cout << vs.size() << endl;
        for(string x : vs){
            cout << x << endl;
        }
    }
    return 0;
}