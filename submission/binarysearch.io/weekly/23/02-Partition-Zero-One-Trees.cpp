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

const int N=6;

int f[N],ans;
map <Tree*,int> zero,one;

void dfs(Tree* node)
{
	if(node==NULL) return;
	f[node->val]++;
	dfs(node->left);
	dfs(node->right);
}

void go(Tree* node)
{
	if(node==NULL) return;
	if(node->val==0) zero[node]++;
	else if(node->val==1) one[node]++;

	go(node->left);
	go(node->right);

	if(node->left)
	{
		zero[node]+=zero[node->left];
		one[node]+=one[node->left];
	}
	if(node->right)
	{
		zero[node]+=zero[node->right];
		one[node]+=one[node->right];
	}

	if(zero[node] and one[node]) return ;
	if(zero[node] and zero[node]==f[0]) ans++;
	if(one[node] and one[node]==f[1]) ans++;
}

class Solution {
	public:
	int solve(Tree* root) {
		ans=0;
		for(int i=0;i<N;i++) f[i]=0;
		zero.clear(),one.clear();

		dfs(root);
		go(root);
		return ans;
	}
};

