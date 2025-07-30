#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

// Preorder: Root → Left → Right
void preorder(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

// Inorder: Left → Root → Right
void inorder(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// Postorder: Left → Right → Root
void postorder(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

// Wrappers for ease of use
vector<int> preOrder(Node* root) {
    vector<int> arr;
    preorder(root, arr);
    return arr;
}

vector<int> inOrder(Node* root) {
    vector<int> arr;
    inorder(root, arr);
    return arr;
}

vector<int> postOrder(Node* root) {
    vector<int> arr;
    postorder(root, arr);
    return arr;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> pre = preOrder(root);
    vector<int> in = inOrder(root);
    vector<int> post = postOrder(root);

    cout << "Preorder Traversal: ";
    for (int val : pre) cout << val << " ";
    cout << endl;

    cout << "Inorder Traversal: ";
    for (int val : in) cout << val << " ";
    cout << endl;

    cout << "Postorder Traversal: ";
    for (int val : post) cout << val << " ";
    
    cout << endl;

    return 0;
}
