#include "solution.hpp"
using namespace std;

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int ans;

int dfs(Tree* node)
{
	if(node==NULL) return INT_MIN;
	int l=dfs(node->left);
	int r=dfs(node->right);
	if(node->val >= max(l,r)) ans++;
	return max({node->val,l,r});
}

class Solution {
	public:
	int solve(Tree* root) {
		ans=0;
		dfs(root);
		return ans;
	}
};

