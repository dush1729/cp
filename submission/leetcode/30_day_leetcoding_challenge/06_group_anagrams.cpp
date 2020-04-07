#include "bits/stdc++.h"
using namespace std;

string sorted(string a)
{
	sort(a.begin(),a.end());
	return a;
}

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& a)
	{
		//"ate","eat","tea"
		//"aet","aet","aet"

		map <string,vector <string>> m;
		for(auto s:a) m[sorted(s)].push_back(s);

		//"aet" -> {"ate","eat","tea"}
		//"ant" -> {"nat","tan"}
		//"abt" -> {"bat"}

		vector <vector <string>> ans;
		for(auto i:m) ans.push_back(i.second);
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