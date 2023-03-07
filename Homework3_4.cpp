#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(NULL), right(NULL){}
    Node(int x, Node* l, Node* r): data(x), left(l), right(r){}
};

int depth(Node* root){
    if(root == NULL) {
        return 0;
    }
    int d = 0;
    while(root){
        d++;
        root = root->left;
    }
    return d;
}

int height(Node* root){
	if(root == NULL){
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

bool isPerfect(Node* root, int d, int level = 0){
	if(root == NULL) 
		return true;
	if(root->left and root->right){
		return (isPerfect(root->left, d, level + 1) and isPerfect(root->right, d, level + 1));
	} else {
		if(!root->left and !root->right){
		    return d == level + 1;
		}
		return false;
	}
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
	int h = height(tree[0]);
	if(isPerfect(tree[0], h, 0)){
	    cout << "yes";
	} else {
	    cout << "no";
	}
    return 0;
}
