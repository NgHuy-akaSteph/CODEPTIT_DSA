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
//Cach 1: 
// set<int> se;
// void preorder(node *root, int cnt){
//     if(root == NULL) return;
//     if(root->left == NULL && root->right == NULL) se.insert(cnt);
//     preorder(root->left, cnt+1);
//     preorder(root->right, cnt+1);
// }

//Cach 2:
int height(node *root){
    if(root == NULL) return 0;
    return max(height(root->left)+1, height(root->right)) + 1;
}

int check(node *root, int cnt, int h){
    if(root == NULL) return 1;
    if(!root->left && !root->right){
        return cnt == h;
    }
    return check(root->left, cnt+1, h) && check(root->left, cnt+1, h);
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
        // se.clear();
        // preorder(root, 0);
        // if(se.size() > 1) cout << 0 << endl;
        // else cout << 1 << endl;
        int h = height(root);
        if(check(root, 1, h)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}