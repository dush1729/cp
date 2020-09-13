//#include "bits/stdc++.h"
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

const int N=1e5+20,K=30;

int dp[N][K];
int k,ans,mx;

void dfs(Tree* root)
{
	if(root==NULL) return ;

	dp[root->val][0]++;

	if(root->left)
	{
		dfs(root->left);
		for(int i=0;i<k;i++) ans+=dp[root->left->val][k-1-i]*dp[root->val][i];
		for(int i=0;i<k;i++) dp[root->val][i+1]+=dp[root->left->val][i];
	}

	if(root->right)
	{
		dfs(root->right);
		for(int i=0;i<k;i++) ans+=dp[root->right->val][k-1-i]*dp[root->val][i];
		for(int i=0;i<k;i++) dp[root->val][i+1]+=dp[root->right->val][i];
	}
}


void go(Tree* root)
{
	if(root==NULL) return;
	mx=max(mx,root->val);
	go(root->left);
	go(root->right);
}

class Solution {
	public:
	int solve(Tree* root, int kk) {
		ans=0;
		k=kk-1;

		mx=0;
		go(root);
		for(int i=0;i<=mx;i++)
			for(int j=0;j<=k;j++) dp[i][j]=0;

		dfs(root);

		return ans;
	}
};
