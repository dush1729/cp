#include "bits/stdc++.h"
using namespace std;

int ans;

string replace(string a,char oldc,char newc)
{
	for(auto &c:a)
		if(c==oldc) c=newc;
	if(a[0]=='0' or stoi(a)==0) return "#";
	return a;
}

void go(string &a,string s1)
{
	for(char oldc='0';oldc<='9';oldc++)
	{
		for(char newc='0';newc<='9';newc++)
		{
			string n=replace(a,oldc,newc);
			if(n=="#") continue;
			if(s1=="") go(a,n);
			else
			{
				ans=max(ans,stoi(s1)-stoi(n));
			}
		}
	}
}

class Solution
{
public:
	int maxDiff(int num)
	{
		ans=INT_MIN;
		string a=to_string(num);
		go(a,"");
		return ans;
	}
};

#ifdef LOCAL
int main()
{
}
#endif