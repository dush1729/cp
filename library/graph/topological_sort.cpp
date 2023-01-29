/*
Problems
https://cses.fi/problemset/task/1681
https://codeforces.com/contest/919/problem/D
https://leetcode.com/problems/course-schedule-ii/description/
https://codeforces.com/contest/1790/problem/C
*/

struct TOPOLOGICAL_SORT {
	// leaf -> root
	vector <vector <int>> adj;
	vector <int> vis, order;
	int cycle = 0;

	void dfs(int node) {
		vis[node] = 1;
		for(int child: adj[node])
			if(!vis[child]) dfs(child);
			else if(vis[child] == 1) cycle = 1;
		vis[node] = 2;
		order.push_back(node);
	}

	TOPOLOGICAL_SORT(const vector <vector <int>> &g) : adj(g) {
		int n = g.size();
		vis.resize(n);

		for(int i = 0; i < n; i++)
			if(!vis[i]) dfs(i);

		// uncomment for root -> leaf
		//reverse(order.begin(), order.end());
	}
};

struct KAHN {
	// root -> leaf
	vector <int> order;
	int cycle = 0;

	KAHN(const vector <vector <int>> &adj) {
		int n = adj.size();
		vector indeg(n, 0);
		for(int node = 0; node < n; node++)
			for(const auto &child: adj[node]) indeg[child]++;

		priority_queue<int, vector<int>, greater<int>> pq; // lexicographical min
		for(int i = 0; i < n; i++)
			if(indeg[i] == 0) pq.push(i);

		while(!pq.empty()) {
			int node = pq.top();
			pq.pop();
			order.push_back(node);
			for(const auto &child: adj[node])
				if(--indeg[child] == 0) pq.push(child);
		}
		if(order.size() != n) cycle = 1, order.clear();

		// uncomment for leaf -> root
		//reverse(order.begin(), order.end());
	}
};