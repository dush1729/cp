#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	bool checkIfCanBreak(string s1, string s2)
	{
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		
		bool ok=true;
		int order=-1;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]==s2[i]) continue;
			if(order==-1)
			{
				if(s1[i]>s2[i]) order=0;
				else order=1;
			}
			else
			{
				if(s1[i]>s2[i] and order==1) ok=false;
				else if(s1[i]<s2[i] and order==0) ok=false;
			}
		}
		return ok;
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif