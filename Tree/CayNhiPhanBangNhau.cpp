#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};

void makeNode(node *root, int x, int y, char c){
    if(c == 'L') root->left = new node(y);
    else root->right = new node(y);
}

void insertNode(node *root, int x, int y, char c){
    if(root == NULL) return;
    if(root->val == x){
        makeNode(root, x, y, c);
    }
    else{
        makeNode(root->left, x, y, c);
        makeNode(root->right, x, y, x);
    }
}

void input(node*  &root){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; 
        char c;
        cin >> x >> y >> c;
        if(root == NULL){
            root = new node(x);
            makeNode(root, x, y, c);
        }
        else insertNode(root, x, y, c);
    }
}

int check(node *r1, node *r2){
    if(r1 == NULL && r2 == NULL) return 1;
    if(r1 == NULL || r2 == NULL) return 0;
    if(r1->val != r2->val) return 0;
    return check(r1->left, r2->left) && check(r1->right, r2->right);
}

int main(){
    int t; cin >> t;
    while(t--){
        node *r1 = NULL;
        node *r2 = NULL;
        input(r1);
        input(r2);
        if(check(r1, r2)) 
            cout << 1 << endl;
        else 
            cout << 0 << endl;
    }
    return 0;
}