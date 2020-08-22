#include "bits/stdc++.h"
using namespace std;

const int N = 5e2 + 20;

int n, m, vis[N][N];
vector <vector <char>> a;
bool cycle;
int dx[] = {+1, -1, 0, 0};
int dy[] = { 0, 0, +1, -1};

bool invalid(int x, int y)
{
    return min(x, y)<0 or x >= n or y >= m;
}

void go(int x, int y, int px, int py, char c)
{
    vis[x][y] = 1;
    for(int k = 0; k < 4; k++)
    {
        int nx = x + dx[k], ny = y + dy[k];
        if(invalid(nx, ny) or (nx == px and ny == py)) continue;
        if(vis[nx][ny] == 1) cycle = true;
        else if(vis[nx][ny] == 0 and a[nx][ny] == c) go(nx, ny, x, y, c);
    }
    vis[x][y] = 2;
}

class Solution
{
public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        cycle = false;
        a = grid;
        n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                vis[i][j] = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(vis[i][j] == 0) go(i, j, -1, -1, a[i][j]);

        return cycle;
    }
};
/*
time O(n*m)
space O(n*m)
*/