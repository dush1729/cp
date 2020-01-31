#include "bits/stdc++.h"
using namespace std;
const int N=50;
int ans;

bool ok(vector <int> a)
{
	sort(a.begin(),a.end());
	return a[2]==a[0]+a[1];
}

int main()
{
	for(int x1=0;x1<=N;x1++)
	{
		for(int y1=0;y1<=N;y1++)
		{
			if(max(x1,y1)==0) continue;
			for(int x2=0;x2<=N;x2++)
			{
				for(int y2=0;y2<=N;y2++)
				{
					if(x1==x2 and y1==y2) continue;
					if(max(x2,y2)==0) continue;
					int d1=x1*x1+y1*y1,d2=x2*x2+y2*y2;
					int d3=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
					if(ok({d1,d2,d3})) ans++;
				}
			}
		}
	}
	cout<<ans/2<<endl;
}