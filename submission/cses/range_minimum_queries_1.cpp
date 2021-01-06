#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20, Z = log2(3), L = log2(N) + 5;

int n, q, a[N], l, r;
int st[N][Z], lg[N];

void build() {
	for(int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
	for(int j = 0; j < L; j++) {
		for(int i = 1; i + (1 << j) <= n + 1; i++) {
			if(j == 0) st[i][0] = a[i];
			else st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int j = lg[r - l + 1];
	return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n;i++) scanf("%d", &a[i]);
	build();

	while(q--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
}