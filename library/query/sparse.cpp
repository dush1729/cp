/*
https://codeforces.com/contest/872/problem/B
https://binarysearch.com/problems/Longest-Sublist-with-Absolute-Difference-Condition
*/
const int L = 20, N = 1 << L;

int lg[N];
template <typename T, typename F = std::function<T(const T&, const T&)>> struct SPARSE {
	vector<T> st[L];
	F op;

	SPARSE(const vector<T> &a, F operation): op(operation) {
		int n = a.size();
		if(!lg[N - 1]) for(int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
		for(int i = 0; i < L; i++) st[i].resize(n);
		for(int i = 0; i < n; i++) st[0][i] = a[i];
		for(int i = 1; i < L; i++)
			for(int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	}

	// O(1) query for idempotent functions like min, gcd, or
	T query(int i, int j) {
		int k = lg[j - i + 1];
		return op(st[k][i], st[k][j - (1 << k) + 1]);
	}

	// O(logn) query for associative functions like add, xor
	T querys(int l, int r) {
		T s = -1;
		for(int j = L - 1, flag = 0; j >= 0; j--) {
			if((1 << j) > r - l + 1) continue;
			s = (flag ? op(s, st[j][l]) : st[j][l]);
			l += 1 << j;
			flag = 1;
		}
		return s;
	}
};