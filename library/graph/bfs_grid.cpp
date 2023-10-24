// https://leetcode.com/problems/surrounded-regions/submissions/
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A2/my-submissions
const vector <pair <int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
const char TARGET = 'W';
struct BFS {
	vector <vector <int>> dp, c, sz;
	vector <vector <pair <int, int>>> components;

	BFS(const vector <vector <char>> &a) {
		int n = a.size(), m = a[0].size();
		queue <pair <int, int>> q;
		dp.assign(n, vector (m, -1));
		c.assign(n, vector (m, 0));
		sz.assign(n, vector (m, 0));

		auto inside = [&](int x, int y) {return min(x, y) >= 0 && x < n && y < m;};
		auto ok = [&](int x, int y) {return inside(x, y) && a[x][y] == TARGET && dp[x][y] == -1;};
		auto neighbours = [&](int x, int y, char target) {
			vector <pair <int, int>> vec;
			for(const auto &[dx, dy]: dirs) {
				int nx = x + dx, ny = y + dy;
				if(inside(nx, ny) && a[nx][ny] == target) vec.push_back({nx, ny});
			}
			return vec;
		};
		auto add = [&](int x, int y, int d) {
			q.push({x, y});
			components.back().push_back({x, y});
			dp[x][y] = d;
			c[x][y] = components.size();
		};

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] != TARGET || dp[i][j] != -1) continue;

				components.push_back({});
				add(i, j, 0);
				while(!q.empty()) {
					auto [x, y] = q.front();
					q.pop();
					for(const auto &[nx, ny]: neighbours(x, y, TARGET)) {
						if(ok(nx, ny)) add(nx, ny, dp[x][y] + 1);
					}
				}
				for(const auto &[x, y]: components.back()) {
					sz[x][y] = components.back().size();
				}
			}
		}
	}
};