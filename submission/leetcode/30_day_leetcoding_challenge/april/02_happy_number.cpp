#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	bool isHappy(int n)
	{
		set <int> s;
		while(s.find(n)==s.end())
		{
			s.insert(n);
			int x=0;
			while(n) x+=(n%10)*(n%10),n/=10;
			n=x;
		}
		return n==1;
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif