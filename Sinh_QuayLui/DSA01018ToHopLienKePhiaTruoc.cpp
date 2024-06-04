#include<bits/stdc++.h>
using namespace std;



int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(k+1, 0);// khởi tạo trước giá trị để tránh truy cập vào giá trị rác
        for(int i = 1; i <= k; i++) cin >> a[i];
        int i = k;
        while(i >= 1 && a[i] == a[i-1]+1){
            i--;
        }
        if(i != 0) a[i]--;
        for(int j = i+1; j <= k; j++){
            a[j] = n - k + j;
        }
        for(int j = 1; j <= k; j++)
            cout << a[j] <<' ';
        cout << endl;
    }
    return 0;
}