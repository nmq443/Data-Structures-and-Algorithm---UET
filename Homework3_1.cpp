#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
    Node(int x): data(x) {}
};

bool preorder(Node* root){
	if(!root)
		return true;
	if(root->children.size() > 2){
		return false;
	}
	for(int i = 0; i < (int)root->children.size(); i++){
		if(preorder(root->children[i]) == false){
			return false;
		}
	}
	return true;
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
		tree[x]->children.push_back(tree[y]);
	}
	if(preorder(tree[0])){
		cout << "yes";
	} else {
		cout << "no";
	}
    return 0;
}
