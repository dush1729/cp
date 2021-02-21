#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int calculated, deep[N];
vector <int> coprime[51];

class Solution {
public:
	vector <int> a, ans;
	vector <int> adj[N], d[51];

	void precompute() {
		for(int i = 1; i <= 50; i++) {
			for(int j = 1; j <= 50; j++) {
				if(__gcd(i, j) == 1) coprime[i].push_back(j);
			}
		}
	}

	void dfs(int node, int parent, int depth) {
		deep[node] = depth;

		int mx = INT_MIN;
		for(int num: coprime[a[node]]) {
			for(int x: d[num]) {
				if(deep[x] > mx) {
					mx = deep[x];
					ans[node] = x;
				}
			}
		}
		

		d[a[node]].push_back(node);

		for(int child:adj[node]) {
			if(child != parent) {
				dfs(child, node, depth + 1);
			}
		}

		d[a[node]].pop_back();
	}

	vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
		if(coprime[1].empty()) precompute();

		a = nums;
		int n = a.size();
		for(int i = 0; i < n; i++) ans.push_back(-1);

		for(const auto &v: edges) {
			adj[v[0]].push_back(v[1]);
			adj[v[1]].push_back(v[0]);
		}

		dfs(0, -1, 0);

		return ans;
	}
};

#ifdef LOCAL
int main() {
	vector <int> v = {1, 2};
	auto ans = Solution().maxSumDivThree(v);
}
#endif
