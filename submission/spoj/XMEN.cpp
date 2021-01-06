#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int t, n, x, p[N];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			p[x] = i;
		}

		vector <int> v;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			int j = lower_bound(v.begin(), v.end(), p[x]) - v.begin();
			if(j == v.size()) v.push_back(p[x]);
			else v[j] = p[x];
		}

		printf("%d\n", v.size());
	}
}