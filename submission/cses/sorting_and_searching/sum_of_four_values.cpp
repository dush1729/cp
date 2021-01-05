#include "bits/stdc++.h"
using namespace std;
 
const int N = 5e3 + 20;
 
int n, a[N], s;
map <int, pair <int, int>> m;

int main() {
	scanf("%d%d", &n, &s);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int target = s - (a[i] + a[j]);
			
			auto it = m.find(target);
			if(it != m.end()) {
				printf("%d %d %d %d", it->second.first, it->second.second, i + 1, j + 1);
				return 0;
			}
		}

		for(int j = 0; j < i; j++) {
			m[a[i] + a[j]] = {i + 1, j + 1};
		}
	}

	printf("IMPOSSIBLE");
}