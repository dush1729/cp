/*
Problems
https://binarysearch.com/problems/Minimal-Submatrices
*/

vector <int> f(vector <int> &a, int k) {
	deque <int> dq;
	vector <int> ans;
	for(int i = 0; i < a.size(); i++) {
		while(!dq.empty() and i - dq.front() >= k) dq.pop_front();
		while(!dq.empty() and a[i] <= a[dq.back()]) dq.pop_back();
		dq.push_back(i);
		if(i >= k - 1) ans.push_back(a[dq.front()]);
	}
	return ans;
}