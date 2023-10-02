/*
Problems
https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph/description/
https://codeforces.com/contest/1867/submission/226246992
*/

struct FUNCTIONAL_GRAPH {
	vector <int> cycle_sz, cycle_col, node_vis;
	vector <vector <int>> cycles;

	FUNCTIONAL_GRAPH(const vector <int> &nxt) {
		int n = nxt.size();

		vector indeg(n, 0), zero_deg(0, 0);
		for(int i = 0; i < n; i++) indeg[nxt[i]]++;
		for(int i = 0; i < n; i++)
			if(!indeg[i]) zero_deg.push_back(i);
		cycle_sz.assign(n, -1);
		stack <int> s;
		for(int i = 0; i < zero_deg.size(); i++) {
			int node = zero_deg[i], child = nxt[node];
			s.push(node);
			cycle_sz[node] = 0;
			if(!--indeg[child]) zero_deg.push_back(child);
		}

		cycle_col.assign(n, 0), node_vis.assign(n, 0);
		for(int i = 0; i < n; i++) {
			if(cycle_sz[i] >= 0) continue;

			cycles.push_back({});
			for(int j = i; cycle_sz[j] == -1; j = nxt[j]) {
				cycles.back().push_back(j);
				cycle_sz[j] = 0;
			}
			for(const int &node: cycles.back()) {
				node_vis[node] = cycle_sz[node] = cycles.back().size();
				cycle_col[node] = cycles.size() - 1;
			}
		}
		while(!s.empty()) {
			int node = s.top(), child = nxt[node];
			s.pop();
			node_vis[node] = node_vis[child] + 1;
		}
	}
};