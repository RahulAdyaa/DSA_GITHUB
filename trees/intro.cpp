#include<iostream>
using namespace std;



struct Node{
    int val;
    struct Node* left;
    struct Node* right;

    Node(int val){
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};

void print(Node* root){
    if(root==nullptr) return ;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);

    print(root);
}