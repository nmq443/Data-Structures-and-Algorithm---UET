#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(NULL), right(NULL){}
    Node(int x, Node* l, Node* r): data(x), left(l), right(r){}
};

int height(Node* root){
	if(root == NULL){
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

bool isBalance(Node* root){
	if(root == NULL){
		return true;
	}
	int left = height(root->left);
	int right = height(root->right);
	if(isBalance(root->left) and isBalance(root->right) and
	abs(left - right) <= 1){
		return true;
	}
	return false;
}

void preorder(Node* root){
	if(root == NULL) 
		return;
	preorder(root->left);
	cout << root->data << " ";
	preorder(root->right);
}

int main (){
    int n;
    cin >> n;
    vector<Node*> tree(n, NULL);
    for(int i = 0; i < n; i++){
    	Node* temp = new Node(i);
    	tree[i] = temp;
    }
    int x, y;
    for(int i = 0; i < n - 1; i++){
		cin >> x >> y;
		if(!tree[x]->left){
			tree[x]->left = tree[y];
		} else if(!tree[x]->right){
			tree[x]->right = tree[y];
		}
	}
	if(isBalance(tree[0])){
		cout << "yes";
	} else {
		cout << "no";
	}
    return 0;
}
