#include<bits/stdc++.h>
using namespace std;

int n, k, a[100];
/*
    Cho chữ cái c in hoa và số nguyên K; Hãy tìm cách liệt kê tất cả các xâu có K ký
tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được
phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước
đó.
Input Format
Chữ cái c và K
Constraints
'A' < c <='H'; 0 < K < (c – ‘A’);
Output Format
Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển trên từng dòng.
*/

void out(){
    for(int i = 1; i <= k; i++){
        cout << (char)(a[i]-1+'A');
    }
    cout << endl;
}

void Try(int i){
    for(int j = 1; j <= n; j++){
        a[i] = j;
        if(i == k) out();
        else Try(i+1);
    }

}

int main(){
    char c;
    cin >> c >> k;
    n = (int)(c - 'A') + 1;
    Try(1);
}