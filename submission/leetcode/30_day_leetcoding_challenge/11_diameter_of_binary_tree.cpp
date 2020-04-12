/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// {height, diamter}
pair <int,int> diameterOfBinaryTreeHelper(TreeNode* node)
{
    if(node == NULL) return {0, 0};
    auto l = diameterOfBinaryTreeHelper(node->left);
    auto r = diameterOfBinaryTreeHelper(node->right);
    int h = max(l.first+1, r.first+1);
    int dia = max({l.second, r.second, l.first + r.first});
    return {h, dia};
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOfBinaryTreeHelper(root).second;
    }
};