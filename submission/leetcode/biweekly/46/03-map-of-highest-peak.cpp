const int MAX = 1e9;
const int WATER = 0, LAND = 1;

vector <pair <int, int>> dirs = {
    {+1, 0},
    {-1, 0},
    { 0,+1},
    { 0,-1}
};

vector<vector<int>> solve(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();

    vector <vector <int>> dp(n, vector <int> (m, MAX));
    queue <pair <int, int>> q;

    auto add = [&](int x, int y, int d) {
        q.push({x, y});
        dp[x][y] = d;
    };

    auto invalid = [&](int x, int y) {
        return min(x, y) < 0 or x >= n or y >= m or dp[x][y] != MAX;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == WATER) add(i, j, 0);
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(auto &[dx, dy]: dirs) {
            int nx = x + dx, ny = y + dy;
            if(!invalid(nx, ny)) add(nx, ny, dp[x][y] + 1);
        }
    }

    return dp;
}

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        for(auto &v: isWater) {
        	for(int &x: v) {
        		x ^= 1;
        	}
        }

        return solve(isWater);
    }
};
