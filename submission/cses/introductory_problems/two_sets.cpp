#include "bits/stdc++.h"
using namespace std;

int n;

void print(vector <int> &v)
{
	printf("%d\n",v.size());
	for(auto i:v) printf("%d ",i);
	printf("\n");
}

int main()
{
	scanf("%d",&n);
	if(n%4==1 or n%4==2) return 0 * printf("NO");
	
	printf("YES\n");
	
	int l=1,r=n;
	vector <int> v1,v2;
	if(n%4==3)
	{
		v1.push_back(1);
		v1.push_back(2);
		v2.push_back(3);
		l=4;
	}

	int sz=(r-l+1);
	for(int i=0;i<sz/4;i++)
	{
		v1.push_back(l++);
		v1.push_back(r--);
	}
	for(int i=0;i<sz/4;i++)
	{
		v2.push_back(l++);
		v2.push_back(r--);
	}

	print(v1);
	print(v2);
}