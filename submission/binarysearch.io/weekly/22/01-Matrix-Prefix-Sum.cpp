#include "solution.hpp"
using namespace std;

const int N=300;

int n,m;
int dp[N][N];

class Solution {
    public:
    vector<vector<int>> solve(vector<vector<int>>& a) {
        if(a.empty()) return {};
        // Write your code here
        n=a.size();
        m=a[0].size();
        
        if(m==0)
        {
            vector <vector <int>> ans;
            for(int i=0;i<n;i++) ans.push_back({});
            return ans;
        }
        
        dp[0][0]=a[0][0];
        for(int i=1;i<n;i++) dp[i][0]=a[i][0]+dp[i-1][0];
        for(int j=1;j<m;j++) dp[0][j]=a[0][j]+dp[0][j-1];
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
            }
        }
        
        vector <vector <int>> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back({});
            for(int j=0;j<m;j++) ans.back().push_back(dp[i][j]);
        }
        return ans;
    }
};
