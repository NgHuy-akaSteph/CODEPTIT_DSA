#include<bits/stdc++.h>
using namespace std;

int n, a[50], stop = 0;
// 1. Sinh xau nhi phan
// void ktao() {
//     for(int i = 1; i <= n; i++){
//         a[i] == 0;
//     }
// }

// void sinh(){
//     int i = n;
//     while(i >= 1 && a[i] == 1){
//         a[i] = 0;
//         i--;
//     }
//     if(i == 0) stop = 1;
//     else a[i] = 1;
// }

//2. Sinh xau to hop(Sinh tap con)
// void ktao(){
//     for(int i = 1; i <= k; i++){
//         a[i] = i;
//     }
// }

// void sinh(){
//     int i = k;
//     while(i >= 1 && a[i] == n - k + i){
//         i--;
//     }
//     if(i == 0) stop = 1;
//     else{
//         a[i]++;
//         for(int j = i + 1; j <= k; j++){
//             a[j] = a[j-1] + 1;
//         }
//     }
// }

//3. Sinh xau hoan vi
// void ktao(){
//     for(int i = 1; i <= n; i++){
//         a[i] = i;
//     }
// }

// void sinh(){
//     int i = n-1;
//     while(i >= 1 && a[i] > a[i+1]){
//         i--;
//     }
//     if(i == 0) stop = 1;
//     else{
//         int j = n;
//         while(a[i] > a[j]) j--;
//         swap(a[i], a[j]);
//         reverse(a+i+1, a+n+1);
//     }
// }


void in(){
    for(int i = 1; i <= n; i++){
        cout << a[i] <<' ';
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    do{
        for(int i = 0; i < n; i++){
            cout << a[i] <<' ';
        }
        cout << endl;
    }
    while(next_permutation(a, a+n));
    return 0;
}