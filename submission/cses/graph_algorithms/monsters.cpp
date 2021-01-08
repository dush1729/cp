#include "bits/stdc++.h"
using namespace std;
#define pp pair <int, int>

const int N = 1e3 + 20, MAX = 1e7;

int n, m, dp[N][N], t[N][N], pv[N][N];
string a[N];
queue <pp> q;
pp source;
int dx[]{+1,-1, 0, 0};
int dy[]{ 0, 0,+1,-1};
char dir[] = "DURL";

void add(int x, int y, int type, int d) {
	q.push({x, y});
	dp[x][y] = d;
	t[x][y] = type;
}

bool out(int x, int y) {
	return min(x, y) < 0 or x >= n or y >= m or a[x][y] == '#' or dp[x][y] != MAX;
}

bool border(int x, int y) {
	return min(x, y) == 0 or x == n - 1 or y == m - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'M') add(i, j, 0, 0);
			else if(a[i][j] == 'A') source = {i, j};
			else dp[i][j] = MAX;
		}
	}

	add(source.first, source.second, 1, 0);
	while(!q.empty()) {
		auto p = q.front();
		q.pop();

		int x = p.first, y = p.second;
		if(border(x, y) and t[x][y] == 1) {
			string ans;
			while(make_pair(x, y) != source) {
				int k = pv[x][y];
				ans += dir[k];
				x -= dx[k], y -= dy[k];
			}
			reverse(ans.begin(), ans.end());
			cout << "YES\n" << ans.size() << "\n" << ans;
			return 0;
		}

		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if(out(nx, ny)) continue;
			add(nx, ny, t[x][y], dp[x][y] + 1);
			pv[nx][ny] = k;
		}
	}

	cout << "NO";
}