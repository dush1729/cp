#include "bits/stdc++.h"
using namespace std;
const int N=1e4+20;
bool b[N];
vector <int> prime,v;

bool is_prime(long long x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

bool both_prime(int i,int j)
{
	string s1=to_string(i)+to_string(j);
	if(not is_prime(stoll(s1))) return false;
	string s2=to_string(j)+to_string(i);
	if(not is_prime(stoll(s2))) return false;
	return true;
}

void go(int i)
{
	if(v.size()==5)
	{
		cout<<accumulate(v.begin(),v.end(),0)<<endl;
		exit(0);
	}
	for(int j=i+1;j<prime.size();j++)
	{
		bool okay=true;
		for(auto i:v)
		{
			if(not both_prime(prime[j],i))
			{
				okay=false;
				break;
			}
		}
		if(okay)
		{
			v.push_back(prime[j]);
			go(j);
			v.pop_back();
		}
	}
}


int main()
{
	for(int i=2;i*i<N;i++)
		if(not b[i])
			for(int j=i*i;j<N;j+=i) b[j]=true;
	for(int i=2;i<N;i++)
		if(b[i]==false) prime.push_back(i);

	for(int i=0;i<30;i++)
	{
		v.push_back(prime[i]);
		go(i+1);
		v.pop_back();
	}
}