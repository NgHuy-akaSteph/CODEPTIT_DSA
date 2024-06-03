#include<bits/stdc++.h>
using namespace std;

//Thuật toán chuyển từ bin -> gray:
/*
    - Bit đầu tiên của mã gray giống mã nhị phân
    - Các bit còn lại ở vị trí i ở mã gray có được 
    bằng cách XOR 2 bit thứ i và thứ i - 1 của xâu nhị phân
*/
string binToGray(string bin){
    string gray; gray += bin[0];
    for(int i = 1; i < bin.size(); i++){
        if(bin[i] == bin[i-1]) gray += "0";
        else gray += "1";
    }
    return gray;
}

//Thuật toán chuyển từ gray -> bin:
/*
    - Bit đầu tiên của mã gray và bin giống nhau
    - Các bit thứ i còn mã bin như sau:
        - Nếu bit thứ i (gray) = 0 thì bit thứ i(bin) = bit thứ i-1(bin);
        - Ngược lại , bit thứ i (bin) là lật của bit thứ i-1 (bin)
*/
string grayToBin(string gray){
    string bin = ""; 
    bin += gray[0];
    for(int i = 1; i < gray.size(); i++){
        if(gray[i] == '1'){
            if(bin[i-1] == '0') bin += "1";
            else bin += "0";
        }
        else bin += bin[i-1];
    }
    return bin;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << grayToBin(s) << endl;
    }
}