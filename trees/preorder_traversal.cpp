#include<iostream>
using namespace std;

struct Node{

    int val;

    struct Node* left;
    struct Node* right;

    Node (int val){
        this->val=val;
        left=nullptr;
        right=nullptr;
    }

};

void preorder(Node* root , vector<int>&ans){
    if(root==nullptr) return ;
    ans.push_back(root->val);
    preorder(root->left , ans);
    preorder(root->right , ans);
}

vector<int> preOrder(Node* root){
    // Create an empty vector to
    // store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
    return arr;
}

int main(){
    struct Node* root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


     vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

}