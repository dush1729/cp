#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 +  20;

int n, x;
bool dp[N] = {true};
vector <int> ans;

int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		for(int i = N - 1; i >= x; i--)
			dp[i] |= dp[i - x];
	}

	for(int i = 1; i < N; i++)
		if(dp[i]) ans.push_back(i);

	printf("%d\n", ans.size());
	for(int x: ans) printf("%d ", x);
}