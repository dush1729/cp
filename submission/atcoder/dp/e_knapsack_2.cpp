#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 2, MAX = 1e9 + 1;


int main() {
	int n, capacity, w, v;
	cin >> n >> capacity;
	vector dp(N, MAX);
	dp[0] = 0;
	while(n--) {
		cin >> w >> v;
		for(int i = N - 1; i >= v; i--) {
			dp[i] = min(dp[i], dp[i - v] + w);
		}
	}

	for(int i = N - 1; i >= 0; i--) {
		if(dp[i] <= capacity) {
			cout << i;
			break;
		}
	}
}