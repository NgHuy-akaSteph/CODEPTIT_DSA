#include<bits/stdc++.h>
using namespace std;

// Cho mảng các số nguyên A[] gồm N phần tử. Hãy chia mảng số nguyên A[] thành
// K tập con khác rỗng sao cho tổng các phần tử của mỗi tập con đều bằng nhau.
// Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập con. Ví
// dụ với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.

int n, k, sum = 0, ok = 0;
int a[100], x[100];
bool used[100];

void ql(int i, int bd, int cur_sum, int cnt){
    if(cnt == k){// da xay duoc k tap (0 den k-1)
        ok = 1;
        return;
    }
    for(int j = bd; j <= n; j++){
        if(!used[j] && cur_sum + a[j] <= sum){
            x[i] = j;
            used[j] = true;
            if(cur_sum + a[j] == sum){
                ql(i+1, 1, 0, cnt + 1);
            }
            else ql(i+1, j+1, cur_sum + a[j], cnt);
            used[j] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % k == 0){
        sum = sum / k;
        ql(1, 1, 0, 0);
        cout << ok;
    }
    else{
        cout << 0 ;
    }
}