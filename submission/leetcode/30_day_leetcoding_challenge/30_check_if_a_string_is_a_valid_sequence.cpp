/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool f(TreeNode *node, vector <int> &a, int i) {
    if(node == NULL) return false;
    if(i == a.size() - 1) return node->val == a[i] and node->left == NULL and node->right == NULL;
    return node->val == a[i] and (f(node->left, a, i + 1) or f(node->right, a, i + 1)); 
}

class Solution {
public:
    // time O(n) | space O(1)
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return f(root, arr, 0);
    }
};