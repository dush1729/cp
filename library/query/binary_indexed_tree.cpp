/*
Problems
https://codeforces.com/contest/1354/problem/D
*/

const int N = 1e7 + 20;

int tree[N];

// add delta to x position
void update(int x, int delta) {
	for(; x <= n; x += x & -x) tree[x] += delta;
}

// returns sum[1 .. x]
int query(int x) {
	int sum = 0;
	for(; x > 0; x -= x & -x) sum += tree[x];
	return sum;
}