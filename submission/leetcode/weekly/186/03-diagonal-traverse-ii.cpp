#include "bits/stdc++.h"
using namespace std;

bool cmp(pair <int,int> &a,pair <int,int> &b)
{
	int sa=a.first+a.second;
	int sb=b.first+b.second;
	if(sa!=sb) return sa<sb;
	return a.first>b.first;
}

class Solution
{
public:
    // time O(n*m*log(n*m)) | space O(n*m)
    // we can reduce time to O(n*m) but I found n*m*log(n*m) fast to code
	vector<int> findDiagonalOrder(vector<vector<int>>& a)
	{
		int n=a.size();
		vector <pair <int,int>> v;
		for(int i=0;i<n;i++)
			for(int j=0;j<a[i].size();j++)
				v.push_back({i,j});
		sort(v.begin(),v.end(),cmp);

		vector <int> ans;
		for(auto p:v) ans.push_back(a[p.first][p.second]);
		return ans;
	}
};

#ifdef LOCAL
int main()
{
}
#endif