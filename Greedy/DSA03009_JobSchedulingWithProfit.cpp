#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n;
        pair<int,int> a[n];
        int maxd = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> a[i].first >> a[i].second;
            maxd = max(maxd, a[i].first);
        }
        sort(a, a+n, cmp);
        bool used[maxd];
        int profit = 0, cnt = 0;
        memset(used, false, sizeof(used));
        for(int i = 0; i <= n-1; i++){
            for(int j = a[i].first - 1; j >= 0; j--){
                if(used[j] == false){
                    used[j] = true;
                    profit += a[i].second;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << ' ' << profit << "\n";
    }
    return 0;
}