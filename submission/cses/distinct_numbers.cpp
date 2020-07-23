#include "bits/stdc++.h"
using namespace std;

int n,x;
set <int> s;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&x),s.insert(x);
	printf("%d",s.size());
}