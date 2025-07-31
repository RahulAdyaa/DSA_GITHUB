// File: TopView.cpp
// Time Complexity: O(N)
// Space Complexity: O(N)
// Intuition: Use BFS to track the topmost node for each horizontal distance (line). Only store the first node encountered at each line.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { 
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        unordered_map<int, int> mpp;  // {line : node->data}
        queue<pair<Node*, int>> q;    // {node, line}
        int minLine = 0, maxLine = 0;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int line=it.second;
            Node* node=it.first;

            
            mpp[line] = node->data;
            minLine = min(minLine, line);
            maxLine = max(maxLine, line);
            
            if (node->left)  q.push({node->left,  line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        for (int line = minLine; line <= maxLine; ++line) {
            ans.push_back(mpp[line]);
        }

        return ans;
    }
};


// Helper function to create a simple binary tree
Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    return root;
}

// Main function
int main() {
    Node* root = buildTree();
    Solution sol;
    vector<int> res = sol.topView(root);

    cout << "Top View: ";
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
