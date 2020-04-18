const int N = 1e3 + 20;

int n, m;
bool vis[N][N];
int dx[] = {+1,-1, 0, 0};
int dy[] = { 0, 0,+1,-1};
vector <vector <char>> a;

bool invalid(int x,int y) {
    return x<0 or x>=n or y<0 or y>=m or vis[x][y];
}

void go(int x, int y) {
    vis[x][y] = true;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(invalid(nx,ny) or a[nx][ny] == '0') continue;
        go(nx, ny);
    }
}

class Solution {
public:
    // time O(n*m) | space O(n*m)
    int numIslands(vector<vector<char>>& grid) {
        a = grid;
        n = a.size(), m = a[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = false;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '0' or vis[i][j]) continue;
                go(i, j);
                ans++;
            }
        }
        return ans;
    }
};