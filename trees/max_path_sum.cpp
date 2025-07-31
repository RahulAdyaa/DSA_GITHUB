// Time Complexity: O(N)
// Space Complexity: O(H) — H is the height of the tree (due to recursion stack)

// Intuition:
// The function calculates the maximum path sum in a binary tree, where a path
// can start and end at any node. It recursively computes the maximum gain
// from left and right subtrees. At each node, it checks if the sum of the
// current node and its left and right gains gives a higher path sum.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to compute max path sum and update global max
    int solve(TreeNode* node, int &maxi) {
        if (!node) return 0;

        int leftSum = max(0, solve(node->left, maxi));   // Ignore negative paths
        int rightSum = max(0, solve(node->right, maxi));

        // Update maximum path sum if the current path is greater
        maxi = max(maxi, node->val + leftSum + rightSum);

        // Return max gain from this node to its parent
        return node->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};

// ----------- MAIN FUNCTION FOR TESTING -----------

int main() {
    /*
       Construct the following binary tree:
               -10
               /  \
              9   20
                 /  \
                15   7

       Max path sum is 15 + 20 + 7 = 42
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    // Cleanup dynamically allocated memory (good practice)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
