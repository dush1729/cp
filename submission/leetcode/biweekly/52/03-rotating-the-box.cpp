class Solution {
public:
	vector<vector<char>> rotateTheBox(vector<vector<char>> a) {
		int n = a.size(), m = a[0].size();
		vector <vector <char>> b(m, vector <char> (n));
		for(int i = 0; i < n; i++) {
			vector <char> v = a[i];
			for(int j = 0; j < m; j++) {
				b[j][n - i - 1] = v[j];
			}
		}

		swap(n, m);
		a = b;

		for(int j = 0; j < m; j++) {
			for(int i = n - 1; i >= 0; ) {
				int k = i, leaf = 0;
				while(k >= 0 && a[k][j] != '*') {
					if(a[k][j] == '#') leaf++;
					k--;
				}

				for(int p = i; p > k; p--) {
					if(leaf) a[p][j] = '#', leaf--;
					else a[p][j] = '.';
				}

				i = k - 1;
			}
		}

		return a;
	}
};