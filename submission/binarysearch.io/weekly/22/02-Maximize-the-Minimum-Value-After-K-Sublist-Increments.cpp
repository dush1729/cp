#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(vector<int>& a, int size, int k) {
		long long lo=0,hi=1e18;
		int n=a.size();

		long long ans=-1;
		while(lo<=hi)
		{
			long long mid=(lo+hi)/2;

			long long moves=0,total=0;
			queue <long long> q;
			for(int i=0;i<n;i++)
			{
				while(q.size()>=size)
				{
					moves-=q.front();
					q.pop();
				}

				if(a[i]+moves>=mid) q.push(0);
				else
				{
					long long val=mid-(a[i]+moves);
					total+=val;
					q.push(val);
					moves+=val;
				}
			}

		//	cout<<lo<<" "<<mid<<" "<<hi<<" "<<total<<endl;
			if(total>k) hi=mid-1;
			else ans=mid,lo=mid+1;

		}
		return ans;
	}
};
