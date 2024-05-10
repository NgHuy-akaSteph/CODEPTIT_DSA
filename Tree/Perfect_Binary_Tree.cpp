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
//Cay nhi phan hoan hao co so phan tu hang i la 2^i
int perfectBT(node *root){
    queue<node*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int s = q.size();// so phan tu trong hang dang xet
        if(s != pow(2, cnt)) return 0;
        //chi duyet cac phan tu trong 1 hang
        for(int i = 0; i < s; i++){
            node *u = q.front(); q.pop();
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
        }
        cnt++;
    }
    return 1;
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
        if(perfectBT(root)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}