class Solution {
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		int n = persons.size();
		vector <pair <int, int>> a(n);
		for(int i = 0; i < n; i++) {
			a[i] = {persons[i], i};
		}
		sort(a.begin(), a.end());

		sort(flowers.begin(), flowers.end());

		int j = 0;
		vector ans(n, 0);
		priority_queue <int> pq;
		for(auto &[x, i]: a) {
			while(j < flowers.size() && flowers[j][0] <= x) {
				pq.push(-flowers[j][1]);
				j++;
			}
			while(!pq.empty() && -pq.top() < x) {
				pq.pop();
			}
			ans[i] = pq.size();
		}
		return ans;
	}
};