/*
    Cho 2 số nguyên dương N và K, bạn hãy liệt kê các các tổ hợp K phần tử các số có
1 chữ số mà có tổng bằng N. Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự từ
bé đến lớn, các tổ hợp cũng được liệt kê theo thứ tự từ điển tăng dần. Nếu không
tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N in ra NOT FOUND

IN:     38 7
OUT:    1 + 2 + 5 + 6 + 7 + 8 + 9
        1 + 3 + 4 + 6 + 7 + 8 + 9
        2 + 3 + 4 + 5 + 7 + 8 + 9
*/
#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> vi;
vector<vector<int>> res;

void ql(int idx, int sum){
    for(int j = idx; j <= 9; j++){
        vi.push_back(j);
        sum += j;
        if(sum == n && vi.size() == k){
            res.push_back(vi);
        }
        else if(sum < n && vi.size() < k){
            ql(j+1, sum);
        }
        sum -= j;
        vi.pop_back();
    }
}

int main(){
    cin >> n >> k;
    ql(1, 0);
    if(res.empty()){
        cout << "NOT FOUND";
    }
    else{
        sort(res.begin(), res.end());
        for(vector<int> vi : res){
            for(int i = 0; i < vi.size(); i++){
                if(i < vi.size()-1) cout << vi[i] <<" + ";
                else cout << vi[i] << endl;
            }
        }
    }
}