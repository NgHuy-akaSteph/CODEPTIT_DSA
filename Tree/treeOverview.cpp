#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct node {
	int data;
	node *left, *right;
	//constructor
	node(int x){
		data = x;
		left = right = NULL;
	}
};
// Hai hàm dưới không làm thay đổi root mà chỉ thêm các node 
// phía dưới của root nên không cần tham chiếu
//sau khi tim duoc node parent
void makeRoot(node *root, int u, int v, char c){
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
//cho v la node con cua u
void insertNode(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root->data == u){
		makeRoot(root, u, v, c);
	}
	else{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

void inOrder(node *root){
	if(root != NULL){
		inOrder(root->left);
		cout << root->data << ' ';
		inOrder(root->right);
	}
}

void preOrder(node *root){
	if(root != NULL){
		cout << root->data << ' ';
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(node *root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << ' ';
	}
}

void levelOrder(node *root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		// lay phan tu dau hang doi
		node *tmp = q.front(); q.pop();
		cout << tmp->data << ' ';
		if(tmp->left != NULL)
			q.push(tmp->left);
		if(tmp->right != NULL)
			q.push(tmp->right);
	}
}

void spiralOrder(node *root){
	stack<node*> s1, s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			node *top = s1.top(); s1.pop();
			cout << top->data << ' ';
			if(top->right != NULL){
				s2.push(top->right);
			}
			if(top->left != NULL){
				s2.push(top->left);
			}
		}
		while(!s2.empty()){
			node *top = s2.top(); s2.pop();
			cout << top->data << ' ';
			if(top->left != NULL){
				s1.push(top->left);
			}
			if(top->right != NULL){
				s1.push(top->right);
			}
		}
	}
}

void spiralByQueue(node *root){
	queue<node*> q;
	q.push(root);
	int cnt = 0;
	while(!q.empty()){
		int s = q.size();
		vector<node*> level;
		for(int i = 0; i < s; i++){
			node *u = q.front(); q.pop();
			level.push_back(u);
		}
		for(node *u : level){
			if(u->left) q.push(u->left);
			if(u->right) q.push(u->right);
		}
		if(cnt % 2 == 0) reverse(level.begin(), level.end());
		for(node* x : level){
			cout << x->data << ' ';
		}
		cnt++;
	}
}
int main(){
	node *root = NULL;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		if(root == NULL){
			root = new node(u);
			makeRoot(root, u, v, c);
		}
		else{
			insertNode(root, u, v, c);
		}
	}
	spiralByQueue(root);
	return 0;
}