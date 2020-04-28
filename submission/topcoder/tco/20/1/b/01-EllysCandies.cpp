#include "bits/stdc++.h"
using namespace std;



class EllysCandies
{
public:
	string getWinner(vector <int> a)
	{
		return a.size()%2?"Elly":"Kris";
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif