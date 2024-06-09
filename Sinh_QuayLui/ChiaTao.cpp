#include<bits/stdc++.h>
using namespace std;
/*
    Có n quả táo với khối lượng đã biết. Nhiệm vụ của bạn là chia táo thành hai nhóm
    sao cho sự khác biệt giữa trọng lượng của 2 nhóm là nhỏ nhất.
Input Format
    Dòng 1 là số nguyên dương N : số lượng quả táo. Dòng thứ 2 là N số nguyên
    p1,p2,...,pn là trọng lượng tương ứng của các quả táo.
Constraints
    1<=N<=20; 1<=pi<=10^9;
Output Format
    In ra độ chênh lệch nhỏ nhất giữa 2 nhóm táo.
*/

int n, ok, a[30], b[30];

void init(){
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void next(){
    int i = n;
    while(i >= 1 && a[i]){
        a[i--] = 0;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    init(); ok = 1;
    long long res = 1e11;
    while(ok){
        long long sum1 = 0, sum2 = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0) sum1 += 1ll*b[i];
            else sum2 += 1ll*b[i];
        }
        res = min(res, abs(sum2 - sum1));
        next();
    }
    cout << res << endl;
    return 0;
}