#include "solution.hpp"
using namespace std;

set <string> s;
vector <char> v={'A','C','G','T'};

void go(string a)
{
	s.erase(a);

	string ns=a;
	for(int i=0;i<a.size();i++)
	{
		for(int k=0;k<4;k++)
		{
			if(a[i]==v[k]) continue;
			ns[i]=v[k];
			if(s.find(ns)!=s.end()) go(ns);
			ns[i]=a[i];
		}
	}
}

class Solution {
	public:
	int solve(vector<string>& genes) {
		for(auto str:genes) s.insert(str);

		int ans=0;
		while(not s.empty())
		{
			go(*s.begin());
			ans++;
		}
		return ans;
	}
};

