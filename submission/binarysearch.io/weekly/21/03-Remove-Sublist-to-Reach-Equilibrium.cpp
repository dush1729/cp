#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(vector<int>& a, int k) {
		int g=0,s=0;
		for(auto i:a)
			if(i>k) g++;
			else if(i<k) s++;
		if(g==s) return a.size();


		int req=g-s;
		int bal=0;
		map <int,int> m;
		m[bal]=-1;

		int ans=INT_MAX;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>k) bal++;
			else if(a[i]<k) bal--;

			if(m.find(bal-req)!=m.end()) ans=min(ans,i-m[bal-req]);
			m[bal]=i;
		}

		if(ans==INT_MAX) return 0;
		return a.size()-ans;
	}
};
