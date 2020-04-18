#include "bits/stdc++.h"
using namespace std;

string f(int n,int x)
{
	string ans="";
	for(int i=0;i<n;i++)
	{
		ans+=((x%3)+'a');
		x/=3;
	}
	return ans;
}

bool ok(int n,int x)
{
	string s=f(n,x);
	for(int i=1;i<s.size();i++)
		if(s[i]==s[i-1]) return false;
	return true;
}

class Solution
{
public:
 	string getHappyString(int n, int k)
	{
		int till=1;
		for(int i=1;i<=n;i++) till*=3;

		vector <string> ans;
		for(int i=0;i<till;i++)
			if(ok(n,i)) ans.push_back(f(n,i));

		sort(ans.begin(),ans.end());
		return k<=ans.size()?ans[k-1]:"";
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().getHappyString(1,3);
	cout<<ans<<endl;
}
#endif