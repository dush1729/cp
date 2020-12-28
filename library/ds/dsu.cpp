/*
Problems
https://binarysearch.com/problems/Number-of-Islands-Online-Version
*/

struct DSU {
	int count;
	struct node {
		int parent, size;
		node(int id = 0): parent(id), size(1) {}
	};

	vector <node> data;

	DSU(int SZ = 0): count(SZ), data(SZ + 1) {
		iota(data.begin(), data.end(), 0);
	}

	int root(int i) {
		if(i != data[i].parent) {
			data[i].parent = root(data[i].parent);
		}
		return data[i].parent;
	}

	bool is_root(int i) {
		return i == root(i);
	}

	bool cycle(int a, int b) {
		return root(a) == root(b);
	}

	bool join(int a, int b) {
		a = root(a), b = root(b);
		if(a == b) return false;

		count--;
		if(data[a].size < data[b].size) swap(a, b);
		data[b].parent = a;
		data[a].size += data[b].size;

		return true;
	}
};