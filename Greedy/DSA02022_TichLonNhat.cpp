#include<bits/stdc++.h>
using namespace std;
using ll = long long;




int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int max1 = max(a[0] * a[1] * a[n-1], a[n-3] * a[n-2] * a[n-1]);
    int max2 = max(a[0] * a[1], a[n-1] * a[n-2]);
    cout << max(max1, max2) << endl;
    return 0;
}