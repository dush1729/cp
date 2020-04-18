#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
 	int findMinFibonacciNumbers(int k)
	{
		vector <int> v={1,1};
		while(v.back()<1e9) v.push_back(v.back()+v[v.size()-2]);

		long long ans=0,sum=0;
		reverse(v.begin(),v.end());
		for(auto i:v)
		{
			if(sum+i<=k) sum+=i,ans++;
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