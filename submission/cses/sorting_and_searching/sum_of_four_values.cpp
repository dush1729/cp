#include "bits/stdc++.h"
using namespace std;
 
const int N = 5e3 + 20;
 
int n, s;
pair <int, int> p[N];
map <int, pair <int, int>> m;

int main() {
	scanf("%d%d", &n, &s);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i + 1;
	}

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int target = s - (p[i].first + p[j].first);
			
			auto it = m.find(target);
			if(it != m.end()) {
				printf("%d %d %d %d", it->second.first, it->second.second, p[i].second, p[j].second);
				return 0;
			}
		}

		for(int j = 0; j < i; j++) {
			m[p[i].first + p[j].first] = {p[i].second, p[j].second};
		}
	}

	printf("IMPOSSIBLE");
}