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

int ans;

int f(TreeNode* node)
{
    if(node == NULL) return 0;
    int l = max(0, f(node->left));
    int r = max(0, f(node->right));
    ans = max(ans, l + r + node->val);
    return max(l, r) + node->val;
}

class Solution {
public:
    // time O(N) | space O(1)
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        f(root);
        return ans;
    }
};