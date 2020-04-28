#include "bits/stdc++.h"
using namespace std;

const int N=50;

int f(int num,int x,int y,int z)
{
	long long val=1ll*num*x+y;
	val*=z;
	int s=0;
	while(val) s+=val%10,val/=10;
	return s;
}

class EllysWhatDidYouGet
{
public:
	int getCount(int n)
	{
		int ans=0;
		for(int x=1;x<=N;x++)
		{
			for(int y=1;y<=N;y++)
			{
				for(int z=1;z<=N;z++)
				{
					int val=-1;
					bool ok=true;
					for(int num=1;num<=n and ok;num++)
						if(val==-1) val=f(num,x,y,z);
						else if(val!=f(num,x,y,z)) ok=false;
					if(ok) ans++;
				}
			}
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