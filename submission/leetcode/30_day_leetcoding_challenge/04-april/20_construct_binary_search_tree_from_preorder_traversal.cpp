/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// time O(n^2) | space O(1)
TreeNode* helper(vector <int> &a, int l, int r) {
    TreeNode* root = new TreeNode(a[l]);
    if(l == r) return root;
    else if(a[r] < a[l]) {
        root -> left = helper(a, l + 1, r);
    } else if(a[l + 1] > a[l]) {
        root -> right = helper(a, l + 1, r);
    } else {
        // 10 9 8 7 6 5 4 3 2 1
        int idx = r;
        while(idx >= l and a[idx] > a[l]) idx--;
        root -> left = helper(a, l + 1, idx);
        root -> right = helper(a, idx + 1, r);
    }
    return root;
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& a) {
        return helper(a, 0, a.size() - 1);
    }
};