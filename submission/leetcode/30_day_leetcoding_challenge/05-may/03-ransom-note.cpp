//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
const int C=26;
class Solution
{
public:
	bool canConstruct(string a, string b)
	{
		vector <int> f(C,0);
		for(auto c:b) f[c-'a']++;
		for(auto c:a) f[c-'a']--;
		return *min_element(f.begin(),f.end())>=0;
	}
};