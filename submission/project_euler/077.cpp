#include "bits/stdc++.h"
using namespace std;
const int N=1e2+20;
int dp[N];
vector <int> prime;

bool is_prime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

int main()
{
	for(int i=2;i<N;i++)
		if(is_prime(i)) prime.push_back(i);
	dp[0]=1;
	for(auto i:prime)
		for(int j=i;j<N;j++)
			dp[j]+=dp[j-i];
	for(int i=2;i<N;i++)
		if(dp[i]>5000) return 0 * printf("%d",i);
}