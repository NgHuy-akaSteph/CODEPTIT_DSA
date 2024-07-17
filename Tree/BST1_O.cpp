#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node (int x) {
        val = x;
        left = right = NULL;
    }
};

void makeRoot(node *root, int u, int v, char x){
    if(x == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char x){
    if(root == NULL) return;
    if(root->val == u){
        makeRoot(root, u, v, x);
    }
    else{
        insertNode(root->left, u, v, x);
        insertNode(root->right, u, v, x);
    }
}

bool fullBT(node *root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    if(root->left != NULL && root->right != NULL){
        return fullBT(root->left) && fullBT(root->right);
    }
    else return false;
}


int main() {
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int u, v;
        char c;
        node *root = NULL;
        for(int i = 0; i < n; i++){
            cin >> u >> v >> c;
            if(root == NULL){
                root = new node(u);
                makeRoot(root, u, v, c);
            }
            else{
                insertNode(root, u, v, c);
            }
        }
        if(fullBT(root)) cout << "YES\n";
        else cout << "NO\n";
    }
}