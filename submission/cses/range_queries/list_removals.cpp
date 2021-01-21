#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int N = 2e5 + 20;

int n, a[N], x;
typedef tree<
int, null_type,
less<int>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
ordered_set s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 0; i < n; i++) {
		cin >> x;

		int lo = 1, hi = n, idx = -1;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;

			int ele = mid - s.order_of_key(mid + 1);
			if(ele >= x) hi = mid - 1, idx = mid;
			else lo = mid + 1;
		}

		cout << a[idx] << " ";
		s.insert(idx);
	}
}