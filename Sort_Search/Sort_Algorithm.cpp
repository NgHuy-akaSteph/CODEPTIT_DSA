#include<bits/stdc++.h>
using namespace std;
using ll = long long;


//Sắp xếp chọn(Selection Sort) O(n^2)
//Đưa phần tử nhỏ nhất mỗi bước lên đầu dãy
void selectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int min_pos = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min_pos])// sap xep giam dan thi dao nguoc dau
                min_pos = j;
        }
        swap(a[i], a[min_pos]);
    }
}

//Bubble Sort O(n^2)
//Dua phan tu lon nhat ve cuoi day o moi buoc
void bubbleSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}

//Insertion Sort O(n^2);
//Dua phan tu dang xet ve dung vi tri cua no sao cho day tu dau den phan tu dang xet da sap xep xong

void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        //Lay ra phan tu o vi tri i
        int x = a[i], pos = i-1;
        //pos luu vi tri se chen x va vi tri co the la vi tri truoc cua x nen can khoi tao pos = i-1
        while(pos >= 0 && a[pos] > x){
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
        for(int i = 0; i < n; i++) cout << a[i] <<' ';
        cout << endl;
    }
}

//Counting Sort
//Dk: Co the khai bao duoc mang dem chua duoc phan tu lon nhat trong mang dang xet
//0 <= a[i] <= 1e6;
//Do phuc tap O(n+maxElement)
int dem[10000001];
void coutingSort(int a[], int n){
    int K = -1e9;
    for(int i = 0; i < n; i++){
        dem[a[i]]++;
        K = max(K, a[i]);
    }
    for(int i = 0; i <= K; i++){
        if(dem[i]){
            for(int j = 0; j < dem[i]; j++)
                cout << i << ' ';
        }
    }
}

//Merge Sort O(nlogn)
//Thuật toán này sử dụng phương pháp chia để trị, 
//chia dãy ban đầu thành các dãy con cho tới khi chỉ còn 1 phần tử, 
//sau đó thực hiện trộn hai con tăng dần thành 1 dãy tăng dần với độ phức tạp tuyến tính

//Tron hai day con : [l,m] va [m+1,r]
void merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i = 0, j = 0;
    while(i < (int)x.size() && j < (int)y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            ++l; ++i;
        }
        else{
           a[l] = y[j]; ++l; ++j; 
        }
    }
    while(i < (int)x.size()){
        a[l] = x[i]; ++l; ++i;
    }
    while(j < (int)y.size()){
        a[l] = y[j]; ++l; ++j;
    }
}


void mergeSort(int a[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}



int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionSort(a, n);
}