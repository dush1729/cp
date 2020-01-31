#include "bits/stdc++.h"
using namespace std;

const int N=20;

int dp[1<<N];

int main()
{
	//https://codeforces.com/blog/entry/45223
	for(int i=0;i<N;i++)
		for(int mask=0;mask<(1<<N);mask++)
			if(mask&(1<<i)) dp[mask]+=dp[mask^(1<<i)];
}
