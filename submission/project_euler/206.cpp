#include "bits/stdc++.h"
using namespace std;
map <int,char> m;
int main()
{
	for(int i=0;i<9;i++) m[i*2]=(char)('0'+i+1);
	m[18]='0';

	for(int i=1000000030;;)
	{
		string sqr=to_string(1ll*i*i);
		bool okay=true;
		for(auto j:m)
			okay&=(sqr[j.first]==j.second);
		if(okay)
		{
			cout<<i;
			return 0;
		}
		if(i%100==30) i+=40;
		else i+=60;
	}
}