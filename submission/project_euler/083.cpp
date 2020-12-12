#include "bits/stdc++.h"
using namespace std;

const int N = 80, MAX = 1e9;

int a[N][N], dp[N][N];
bool vis[N][N];
priority_queue <pair <int, pair <int, int>>> pq;
int dx[]{+1,-1, 0, 0};
int dy[]{ 0, 0,+1,-1};

void add(int x, int y, int d) {
	dp[x][y] = d;
	vis[x][y] = true;
	pq.push({-d, {x, y}});
}

bool invalid(int x, int y) {
	return min(x, y) < 0 or max(x, y) >= N or vis[x][y];
}

int main() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	add(0, 0, a[0][0]);
	while(not pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int x = p.second.first, y = p.second.second;

		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if(invalid(nx, ny)) continue;
			add(nx, ny, dp[x][y] + a[nx][ny]);
		}
	}

	printf("%d", dp[N - 1][N - 1]);
}