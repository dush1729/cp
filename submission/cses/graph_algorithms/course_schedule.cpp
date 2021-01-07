#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int n, m, u, v, vis[N];
vector <int> adj[N];
stack <int> s;
bool cycle;

void dfs(int node, int parent) {
	vis[node] = 1;
	for(int child: adj[node])
		if(!vis[child]) dfs(child, node);
		else if(vis[child] == 1) cycle = true;
	vis[node] = 2;
	s.push(node);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for(int i = 1; i <= n; i++)
		if(!vis[i]) dfs(i, 0);

	if(cycle) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}