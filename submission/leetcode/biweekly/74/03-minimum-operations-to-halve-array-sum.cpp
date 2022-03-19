class Solution {
public:
	int halveArray(vector<int>& a) {
		long long s = 0, ans = 0;
		for(int &x: a) s += x;
		double r = s / 2.;

		priority_queue <double> pq;
		for(int &x: a) pq.push(x);

        double sum = 0;
		while(sum < r) {
			double ele = pq.top();
			pq.pop();

			sum += ele / 2;
			pq.push(ele / 2);
			ans++;
		}
		return ans;
	}
};