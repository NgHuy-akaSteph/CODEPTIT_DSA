#include<bits/stdc++.h>
using namespace std;

// Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được
// gọi là số xa cách nếu thỏa mãn: K không chứa chữ số 0. Tất cả các chữ số từ 1
// đến N đều xuất hiện trong K đúng 1 lần. Không có hai chữ số liên tiếp nào trong K
// có hiệu bằng 1.

int n, a[100];
bool used[100];

void ql(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j] && abs(j - a[i-1]) != 1){
            a[i] = j;
            used[j] = true;
            if(i == n){
                for(int k = 1; k <= n; k++){
                    cout << a[k];
                }
                cout << endl;
            }
            else ql(i+1);
            used[j] = false;
        }
    }
}

int main(){
    cin >> n;
    a[0] = 0;
    ql(1);
    return 0;
}