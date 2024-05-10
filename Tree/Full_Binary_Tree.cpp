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

void makeRoot(node* root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v ,c);
    }
}

int checkFullBT(node *root){
    if(root == NULL) return 1;
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->left != NULL && root->right != NULL){
        return checkFullBT(root->left) && checkFullBT(root->right);
    }
    else return 0;
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int u, v; char c;
        node *root = NULL;
        for(int i = 0; i < n; i++){
            cin >> u >> v >> c;
            if(root == NULL){
                root = new node(u);
                makeRoot(root, u, v, c);
            }
            else{
                insertNode(root, u, v ,c);
            }
        }
        cout << checkFullBT(root) << endl;
    }
    return 0;
}