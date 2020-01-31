#include "bits/stdc++.h"
using namespace std;
int n;

bool bouncy(string a)
{
	bool inc=true,dec=true;
	for(int i=1;i<a.size();i++)
		if(a[i]<a[i-1]) inc=false;
		else if(a[i]>a[i-1]) dec=false;
	return not inc and not dec;
}

int main()
{
	for(int d=1;;d++)
	{
		n+=bouncy(to_string(d));
		if(n*100>=d*99) return 0 * printf("%d ",d);
	}
}