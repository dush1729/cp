#include "bits/stdc++.h"
using namespace std;
const int N=1e6+20;
bool is_prime[N];
vector <int> prime,square;
int main()
{
	for(int i=2;i<N;i++) is_prime[i]=true;
	for(int i=2;i*i<N;i++)
		if(is_prime[i])
			for(int j=i*i;j<N;j+=i)
				is_prime[j]=false;
	for(int i=2;i<N;i++) if(is_prime[i]) prime.push_back(i);
	for(int i=1;i<1e3;i++) square.push_back(2*i*i);
	for(int i=3;i<N;i+=2)
	{
		if(is_prime[i]) continue;
		bool okay=false;
		for(auto j:prime)
		{
			if(j>i) break;
			if(binary_search(square.begin(),square.end(),i-j))
			{
				okay=true;
				break;
			}
		}
		if(not okay) return 0 * printf("%d",i);
	}
}