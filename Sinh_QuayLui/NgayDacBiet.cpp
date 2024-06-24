#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string date(8,'0');
vector<string> ans;

void out(){
    int d = stoi(date.substr(0,2));
    int m = stoi(date.substr(2,2));
    int y = stoi(date.substr(4));
    if(d > 0 && d <= 31 && m > 0 && m <= 12 && y >= 2000){
        string s = date;
        s.insert(2, 1, '/');
        s.insert(5, 1, '/');
        ans.push_back(s);
    }
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        if(j == 0) date[i] = '0';
        else date[i] = '2';
        
        if(i == 7) out();
        else Try(i+1);
    }
}

int main() {
    Try(0);
    sort(ans.begin(), ans.end());
    for(string x : ans)
        cout << x << endl;
    return 0;
}