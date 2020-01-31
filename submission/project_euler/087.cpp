#include "bits/stdc++.h"
using namespace std;
const int N=5e7;
vector <int> prime;
bool b[N];

bool is_prime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

int main()
{
	for(int i=2;i*i<N;i++)
		if(is_prime(i)) prime.push_back(i);

	for(auto i:prime)
	{
		int val=i*i*i*i;
		if(val>=N) break;
		for(auto j:prime)
		{
			if(val+j*j*j>=N) break;
			for(auto k:prime)
			{
				if(val+j*j*j+k*k>=N) break;
				b[val+j*j*j+k*k]=true;
			}
		}
	}
	cout<<count(b,b+N,true)<<endl;
}