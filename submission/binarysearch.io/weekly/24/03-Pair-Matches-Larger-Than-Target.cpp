#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(vector<int>& a, int k) {
		sort(a.begin(),a.end());

		int n=a.size();
		int lo=0,hi=n/2,ans;
		while(lo<=hi)
		{
			int mid=(lo+hi)/2;

			bool ok=true;
			for(int i=0;i<mid and ok;i++)
			{
				if(a[n-(mid-i)]-a[i]<k) ok=false;
			}

			if(ok) ans=mid,lo=mid+1;
			else hi=mid-1;
		}
		return ans;
	}
};
