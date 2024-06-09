#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int X[100], n, k;
//Sinh xau nhi phan
// void Try(int i){
//     for(int j = 0; j <= 1; j++){
//         X[i] = j;
//         if(i == n){
//             for(int i = 1; i <= n; i++)
//                 cout << X[i];
//             cout << endl;
//         }
//         else{
//             Try(i+1);
//         }
//     }
// }

//Sinh to hop
// void output(){
//     for(int i = 1; i <= k; i++){
//         cout << X[i] ;
//     }
//     cout << endl;
// }
// void Try(int i){
//     for(int j = X[i-1]+1; j <= n-k+i; j++){
//         X[i] = j;
//         if(i == k){
//             output();
//         }
//         else Try(i+1);
//     }
// }

//Sinh chinh hop lap
// void out(){
//     for(int i = 1; i <= n; i++){
//         cout << X[i];
//     }
//     cout << endl;
// }
// void Try(int i){
//     for(int j = 1; j <= n; j++){
//         X[i] = j;
//         if(i == n) out();
//         else Try(i+1);
//     }
// }

//Sinh hoan vi
int used[100];
void out(){
    for(int i = 1; i <= n; i++){
        cout << X[i];
    }
    cout << endl;
}
void Try(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            X[i] = j;
            used[j] = 1;
            if(i == n) out();
            else Try(i+1);
            used[j] = 0; //backtrack
        }
    }
}

int main(){
    cin >> n;
    memset(used, 0, sizeof(used));
    Try(1);
}
