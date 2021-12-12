// https://leetcode.com/problems/surrounded-regions/submissions/
const vector <pair <int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
struct BFS {
	queue <pair <int, int>> q;
	vector <vector <int>> dp;

	void add(int x, int y, int d) {
		q.push({x, y});
		dp[x][y] = d;
	}

	BFS(const vector <vector <char>> &a, const vector <pair <int, int>> &sources) {
		int n = a.size(), m = a[0].size();
		dp.assign(n, vector (m, -1));
		auto invalid = [&](int x, int y) {
			return min(x, y) < 0 || x >= n || y >= m || a[x][y] == 'X' || dp[x][y] != -1;
		};
		
		for(auto &[x, y]: sources) add(x, y, 0);
		while(!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for(const auto &[dx, dy]: dirs) {
				int nx = x + dx, ny = y + dy;
				if(!invalid(nx, ny)) add(nx, ny, dp[x][y] + 1);
			}
		}
	}
};