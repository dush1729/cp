#include "bits/stdc++.h"
using namespace std;

const int MOD=1812447359,C=26;

long long f(string &a)
{
	long long ans=0;
	vector <int> cnt(C,0);
	for(int i=a.size()-1;i>=0;i--)
	{
		cnt[a[i]-'a']++;
		for(int j=a[i]-'a'+1;j<C;j++)ans+=cnt[j];
	}

	return ans;
}

class SwapTheString
{
public:
	long long findNumberOfSwaps(string P, int A0, int X, int Y, int N, int K)
	{
		vector <long long> A={A0};
		for(int i=1;i<=N-1;i++) A.push_back((A[i-1] * X + Y) % MOD);
		string s=P;
		for(int i=P.size();i<=N-1;i++) s.push_back((char)(A[i] % 26 + 'a'));
		cout<<s<<endl;
		
		long long ans=0;
		for(int i=0;i<K;i++)
		{
			string a="";
			for(int j=i;j<N;j+=K) a+=s[j];
			ans+=f(a);
		}
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