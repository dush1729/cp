#include "bits/stdc++.h"
using namespace std;

const int N = 5e3 + 20;

int n, s;
pair <int, int> p[N];

int main() {
	scanf("%d%d", &n, &s);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i + 1;
	}

	sort(p, p + n);
	for(int i = 0; i < n; i++) {
		for(int l = i + 1, r = n - 1; l < r;) {
			long long sum = 0ll + p[i].first + p[l].first + p[r].first;
			if(sum > s) r--;
			else if(sum < s) l++;
			else {
				printf("%d %d %d", p[i].second, p[l].second, p[r].second);
				return 0;
			}
		}
	}

	printf("IMPOSSIBLE");
}