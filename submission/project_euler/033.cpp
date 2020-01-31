#include "bits/stdc++.h"
using namespace std;
int n=1,d=1,g;

bool okay(int num,int den)
{
	if(num%10==0 and den%10==0) return false; //trivial
	string s1=to_string(num),s2=to_string(den);
	sort(s1.begin(),s1.end()),sort(s2.begin(),s2.end());
	if(s1==s2) return false; //all cancels
	if(s1[0]!=s2[0] and s1[1]!=s2[1]) return false; //nothing common
	if(s1[0]==s2[0]) return (s1[1]-'0')*den==num*(s2[1]-'0');
	return (s1[0]-'0')*den==num*(s2[0]-'0');
}

int main()
{
	for(int num=10;num<100;num++)
		for(int den=num+1;den<100;den++)
			if(okay(num,den)) n*=num,d*=den;

	g=__gcd(n,d),n/=g,d/=g;
	cout<<d;
}