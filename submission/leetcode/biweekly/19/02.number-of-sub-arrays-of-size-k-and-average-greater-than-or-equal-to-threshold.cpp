#include "bits/stdc++.h"
using namespace std;

map <int,int> dp;

class Solution
{
public:
	int numOfSubarrays(vector<int>& arr, int k, int threshold) 
	{
		long long sum=0;
		for(int i=0;i<k;i++) sum+=arr[i];

		int ans=0;
		if(sum>=1ll*threshold*k) ans++;
		for(int i=k;i<arr.size();i++)
		{
			sum+=arr[i]-arr[i-k];
			if(sum>=1ll*threshold*k) ans++;
		}
		return ans;
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().numberOfSteps(6);
	cout<<ans<<endl;
}
#endif