#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	int countElements(vector<int>& a)
	{
		/*
		// time O(nlogn) | space O(1)
		int ans=0;
		sort(a.begin(),a.end());
		for(auto i:a)
			if(binary_search(a.begin(),a.end(),i+1))
				ans++;
		return ans;
		*/

		// time O(n) | space O(n)
		int ans=0;
		map <int,int> m;
		for(auto i:a) m[i]++;

		for(auto p:m)
		{
			if(m.find(p.first+1)!=m.end())
				ans+=p.second;
		}
		return ans;
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif