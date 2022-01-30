const int C = 26;

struct DSU {
	int count, maxsize;
	struct node {
		int parent, size;
		node(int id = 0): parent(id), size(1) {}
	};

	vector <node> data;

	DSU(int SZ = 0): count(SZ), maxsize(1), data(SZ) {
		iota(data.begin(), data.end(), 0);
	}

	int root(int i) {
		return i == data[i].parent ? data[i].parent : root(data[i].parent);
	}

	bool is_root(int i) {
		return i == root(i);
	}

	bool cycle(int a, int b) {
		return root(a) == root(b);
	}

	int set_size(int a) {
		return data[root(a)].size;
	}

	bool join(int a, int b) {
		a = root(a), b = root(b);
		if(a == b) return false;

		count--;
		if(data[a].size < data[b].size) swap(a, b);
		data[b].parent = a;
		data[a].size += data[b].size;
		maxsize = max(maxsize, data[a].size);

		return true;
	}
};

class Solution {
public:
	vector<int> groupStrings(vector<string>& a) {
		int n = a.size();
		auto ds = DSU(n);

		unordered_map <int, int> dp;
		for(int i = 0; i < n; i++) {
			int mask = 0;
			for(char &c: a[i]) mask ^= (1 << (c - 'a'));

			for(int c = 0; c < C; c++) {
				int nmask = (mask ^ (1 << c));
				if(dp.find(nmask) != dp.end()) ds.join(dp[nmask], i);
			}
			for(int c1 = 0; c1 < C; c1++) {
				if(!(mask & (1 << c1))) continue;
				for(int c2 = 0; c2 < C; c2++) {
					if(c1 != c2 && mask & (1 << c2)) continue;
					int nmask = (mask ^ (1 << c1) ^ (1 << c2));
					if(dp.find(nmask) != dp.end()) ds.join(dp[nmask], i);
				}
			}

			dp[mask] = i;
		}
		return {ds.count, ds.maxsize};
	}
};