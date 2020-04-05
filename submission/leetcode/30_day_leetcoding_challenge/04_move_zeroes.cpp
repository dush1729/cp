#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	void moveZeroes(vector<int>& a)
	{
		int zero=0;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]==0) zero++; // add 0 to our zero block
			else if(zero>0) swap(a[i],a[i-zero]); // swap non-zero element with first 0 in the block
			// ....[0]0000[7]...
			// ....[7]0000[0]...
		}
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif