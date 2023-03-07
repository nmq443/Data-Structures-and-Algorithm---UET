#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(NULL), right(NULL){}
    Node(int x, Node* l, Node* r): data(x), left(l), right(r){}
};

void preorder(Node* root, int& ans){
	if(root == NULL) 
		return;
	preorder(root->left, ans);
	if((!root->left and root->right) or (root->left and !root->right)){
	    ans++;
	}
	preorder(root->right, ans);
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
	int ans = 0;
	preorder(tree[0], ans);
	cout << ans;
    return 0;
}
