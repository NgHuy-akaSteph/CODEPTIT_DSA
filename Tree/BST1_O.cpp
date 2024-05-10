#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

void addNode(node *root, int x){
    if(root == NULL){
        root = new node(x);
    }
    else{
        if(root->val > x){
            addNode(root->left, x);
        }
        else addNode(root->right, x);
    }
}


int main(){
    int n; cin >> n;
    int a[n];
    node *root = NULL;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        addNode(root, a[i]);
    }
}
