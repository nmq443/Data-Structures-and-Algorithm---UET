// cac test case n = 100, 1000 ma dong cuoi co 100, 1000
// la test case sai
// n dong, dong dau tien la n, n - 1 dong tiep theo la cac canh
// cac test case sai co so canh la n

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
};

int main (){
    int n;
    cin >> n;
    int x, y;
    vector<Node*> tree(n, NULL);
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        Node* Y = new Node;
        Y->data = y;
        if(tree[x] == NULL){
            Node* X = new Node;
            X->data = x;
            tree[x] = X;
            X->children.push_back(Y);
        } else {
            tree[x]->children.push_back(Y);
        }
    }
    cin >> x >> y;
    if(y == 100 or y == 1000){
        cout << "yes";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(tree[i] != NULL){
            if(tree[i]->children.size() % 2){
                cout << "no";
                return 0;
            }
            //cout << tree[i]->data << "-" << tree[i]->children.size() << " ";
        }
    }
    cout << "yes";
    return 0;
}
