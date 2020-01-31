#include "bits/stdc++.h"
using namespace std;
string a="123456789";
set <int> product;
int ans;

void run()
{
	for(int i=1;i<=7;i++)
	{
		for(int j=1;i+j<=8;j++)
		{
			if(9-(i+j)<max(i,j) or (a[i-1]-'0')*(a[i+j-1]-'0')%10!=a[8]-'0') continue;
			string s1=a.substr(0,i);
			string s2=a.substr(i,j);
			string s3=a.substr(i+j);
			if(1ll*stoi(s1)*stoi(s2)==stoi(s3)) product.insert(stoi(s3));
		}
	}
}

int main()
{
	do run();
	while(next_permutation(a.begin(),a.end()));
	for(auto i:product) ans+=i;
	cout<<ans<<endl;
}