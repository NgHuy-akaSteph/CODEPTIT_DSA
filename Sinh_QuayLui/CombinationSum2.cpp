/*
Cho 2 số nguyên dương N và K, bạn hãy liệt kê các các tổ hợp K phần tử các số
nguyên tố mà có tổng bằng N. Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự
từ bé đến lớn, các tổ hợp cũng được liệt kê theo thứ tự từ điển tăng dần. Nếu
không tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N in ra NOT FOUND */
#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> vi, prime;
vector<vector<int>> res;

bool snt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}

void ql(int i, int sum){
    for(int j = i; j <= prime.size(); j++){
        vi.push_back(prime[j]);
        sum += prime[j];
        if(sum == n && vi.size() == k){
            res.push_back(vi);
        }
        else if(sum < n && vi.size() < k){
            ql(j+1, sum);
        }
        sum -= prime[j];
        vi.pop_back();
    }
}

int main(){
    for(int i = 1; i <= 500; i++){
        if(snt(i)) prime.push_back(i);
    }
    cin >> n >> k;
    ql(1, 0);
    if(res.empty()) cout << "NOT FOUND";
    else{
        sort(res.begin(), res.end());
        for(vector<int> vi : res){
            for(int i = 0; i < vi.size(); i++){
                cout << vi[i];
                if(i != vi.size() - 1) cout << " + ";
                else cout << endl;
            }
        } 
    }
    return 0;
}