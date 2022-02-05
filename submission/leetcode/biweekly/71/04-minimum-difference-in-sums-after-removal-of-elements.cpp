#define ll long long
class Solution {
public:
	long long minimumDifference(vector<int> nums) {
		int n = nums.size();
		vector <ll> a, dp = {0};
		for(int &x: nums) {
			a.push_back(x);
			dp.push_back(dp.back() + x);
		}

		vector <ll> l(n), r(n);
		ll pqsum = 0;
		priority_queue <ll> pq;
		for(int i = 0; i < n / 3; i++) pq.push(a[i]), pqsum += a[i];
		l[n / 3 - 1] = pqsum;
		for(int i = n / 3; i < n; i++) {
			pq.push(a[i]);
			pqsum += a[i] - pq.top();
			pq.pop();
			l[i] = pqsum;
		}

		pqsum = 0;
		while(!pq.empty()) pq.pop();
		for(int i = n - 1; i >= n - n / 3; i--) pq.push(-a[i]), pqsum += a[i];
		r[n - n / 3] = pqsum;
		for(int i = n - n / 3 - 1; i >= 0; i--) {
			pq.push(-a[i]);
			pqsum += a[i] + pq.top();
			pq.pop();
			r[i] = pqsum;
		}

		ll ans = LLONG_MAX;
		for(int i = n / 3 - 1, it = 0; it <= n / 3; i++, it++) {
			ans = min(ans, l[i] - r[i + 1]);
		}
		return ans;
	}
};