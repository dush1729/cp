#include "solution.hpp"
using namespace std;

const int N=1e5+20;

class Solution {
    public:
    int solve(vector<int>& a) {
        priority_queue <int> pq;
        pq.push(-a[0]);
        
        int ans=INT_MAX;
        for(int i=2;i<a.size();i++)
        {
            ans=min(ans,a[i]-pq.top());
            pq.push(-a[i-1]);
        }
        return ans;
    }
};
