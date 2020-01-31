#include "bits/stdc++.h"
using namespace std;
int mx,ans;
map <int,int> decimal;

int divide(int numerator,int denominator,int pos)
{
	if(numerator%denominator==0) return 0;
	while(numerator<denominator) numerator*=10;
	if(decimal.find(numerator%denominator)==decimal.end())
	{
		decimal[numerator%denominator]=pos;
		return divide(numerator%denominator,denominator,pos+1);
	}
	else return pos-decimal[numerator%denominator];
}

int main()
{
	for(int d=2;d<1e3;d++)
	{
		decimal.clear();
		int cycle=divide(1,d,0);
		if(mx<cycle) mx=cycle,ans=d;
	}
	cout<<ans;
}